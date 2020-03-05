/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:40:06 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/05 21:57:22 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include "clean.h"
#include "utils.h"
#include "texture.h"

uint32_t	color_add(uint32_t color, double add)
{
	int		r;
	int		g;
	int		b;

	r = (color >> 16 & 0xFF);
	g = (color >> 8 & 0xFF);
	b = (color & 0xFF);
	r += add;
	g += add;
	b += add;
	r > 255 ? r = 255 : r;
	g > 255 ? g = 255 : g;
	b > 255 ? b = 255 : b;
	r < 0 ? r = 0 : r;
	g < 0 ? g = 0 : g;
	b < 0 ? b = 0 : b;
	return ((r << 16) | (g << 8) | b);
}

void		init_and_protect_variable_1
	(t_game *var, float w_size, float *u0, float *u1)
{
	double	protect;

	protect = (var->org[1].x - var->org[0].x) != 0 ?
		(var->org[1].x - var->org[0].x) : 1.0;
	*u0 = (var->t[0].x - var->org[0].x) * (W_UNIT * w_size / W_SIZE) / protect;
	*u1 = (var->t[1].x - var->org[0].x) * (W_UNIT * w_size / W_SIZE) / protect;
}

void		init_and_protect_variable_2
	(t_game *var, float w_size, float *u0, float *u1)
{
	double	protect;

	protect = (var->org[1].y - var->org[0].y) != 0 ?
		(var->org[1].y - var->org[0].y) : 1.0;
	*u0 = (var->t[0].y - var->org[0].y) * (W_UNIT * w_size / W_SIZE) / protect;
	*u1 = (var->t[1].y - var->org[0].y) * (W_UNIT * w_size / W_SIZE) / protect;
}

uint32_t	color_light(uint32_t color, int light, double pourcent)
{
	int		r;
	int		g;
	int		b;
	int		diff;

	if (light < 0)
		return (color);
	diff = (light >> 16 & 0xFF) - (color >> 16 & 0xFF);
	r = (color >> 16 & 0xFF) + (int)(diff * pourcent / 100);
	diff = (light >> 8 & 0xFF) - (color >> 8 & 0xFF);
	g = (color >> 8 & 0xFF) + (int)(diff * pourcent / 100);
	diff = (light & 0xFF) - (color & 0xFF);
	b = (color & 0xFF) + (int)(diff * pourcent / 100);
	return ((r << 16) | (g << 8) | b);
}
