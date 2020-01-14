/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:28:40 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/14 13:34:45 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

void	line_params(t_line *line, t_pos a, t_pos b)
{
	line->sign.y = (a.y < b.y ? 1 : -1);
	line->sign.x = (a.x < b.x ? 1 : -1);
	line->delta.y = abs(b.y - a.y);
	line->delta.x = abs(b.x - a.x);
	line->offset = line->delta.x - line->delta.y;
	line->error = 0;
}

void	police_color(SDL_Color *color, uint8_t r, uint8_t g, uint8_t b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

void	paste_position(SDL_Rect *pos, t_pos scale)
{
	pos->x = scale.x;
	pos->y = scale.y;
}

t_vec2d	v2d(double x, double y)
{
	t_vec2d	p;

	p.x = x;
	p.y = y;
	return (p);
}

t_vec3d	v3d(double x, double y, double z)
{
	t_vec3d	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}
