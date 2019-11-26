/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:18:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/26 04:49:07 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"

void	scale_text(t_env *env, SDL_Rect *where, char *text, uint8_t pos)
{
	t_vec	p;
	t_pos	end;
	t_pos	start;
	t_pos	scale;

	TTF_SizeText(env->sdl.font, text, &p.x, &p.y);
	start.x = env->data.ui.min.x;
	start.y = env->data.ui.min.y * pos;
	end.x = env->data.ui.max.x;
	end.y = start.y + env->data.ui.min.y;
	scale.x = start.x + (end.x - (start.x + p.x)) / 2;
	scale.y = start.y + (end.y - (start.y + p.y)) / 2;
	paste_position(where, scale);
}

double	Yaw(double y, double z, double current_gap)
{
	return (y + z * current_gap);
}
double	min(double a, double b)
{
	return ((a < b ? a : b));
}

double	max(double a, double b)
{
	return ((a > b ? a : b));
}

double	clamp(double value, double minimum, double maximum)
{
	return (min(max(value, minimum), maximum));
}

double	vxs(double x0, double y0, double x1, double y1)
{
	return (x0 * y1 - x1 * y0);
}

t_vec2d	Intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	t_vec2d	p;

	p.x = vxs(vxs(x1, y1, x2, y2), x1 - x2, vxs(x3, y3, x4, y4), x3 - x4) / vxs(x1 - x2, y1 - y2, x3 - x4, y3 - y4);
	p.y = vxs(vxs(x1, y1, x2, y2), y1 - y2, vxs(x3, y3, x4, y4), y3 - y4) / vxs(x1 - x2, y1 - y2, x3 - x4, y3 - y4);
	return (p);
}

double	PointSide(double px, double py, double x0, double y0, double x1, double y1)
{
	return (vxs(x1 - x0, y1 - y0, px - x0, py - y0));
}

int		Overlap(double a0, double a1, double b0, double b1)
{
	return ((min(a0, a1) <= max(b0, b1) && (min(b0, b1) <= max(a0, a1))));
}

int		IntersectBox(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3)
{
	return ((Overlap(x0, x1, x2, x3) && Overlap(y0, y1, y2, y3)));
}
