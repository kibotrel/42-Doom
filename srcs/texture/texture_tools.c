/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:40:06 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/28 13:14:00 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include "clean.h"
#include "utils.h"
#include "texture.h"

uint32_t	color_mul(uint32_t color, double mul)
{
	int		r;
	int		g;
	int		b;

	r = (color >> 16 & 0xFF);
	g = (color >> 8 & 0xFF);
	b = (color & 0xFF);
	r *= mul;
	g *= mul;
	b *= mul;
	r > 255 ? r = 255 : r;
	g > 255 ? g = 255 : g;
	b > 255 ? b = 255 : b;
	r < 0 ? r = 0 : r;
	g < 0 ? g = 0 : g;
	b < 0 ? b = 0 : b;
	return ((r << 16) | (g << 8) | b);
}

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
