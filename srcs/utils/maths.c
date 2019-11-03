/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:18:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/03 13:40:47 by demonwaves       ###   ########.fr       */
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

double	bound(double x, double min, double max)
{
	return (fmin(fmax(x, min), max));
}

uint8_t	overlap(double a, double b, double c, double d)
{
	return ((fmin(a, b) <= fmax(c, d) && fmin(c, d) <= fmax(a, b)) ? 1 : 0);
}

uint8_t	hitbox(t_vec2d a, t_vec2d b, t_vec2d c, t_vec2d d)
{
	return ((overlap(a.x, b.x, c.x, d.x) && overlap(a.y, b.y, c.y, d.y)) ? 1 : 0);
}

double	cross(t_vec2d a, t_vec2d b)
{
	return ((a.x * b.y) - (b.x * a.y));
}

double	side(t_vec2d cam, t_vec2d a, t_vec2d b)
{
	return (cross(vector2d(b.x - a.x, b.y - a.y), vector2d(cam.x - a.x, cam.y - a.y)));
}

t_vec2d	intersect(t_vec2d a, t_vec2d b, t_vec2d c, t_vec2d d)
{
	double	num;
	double	den;
	t_vec2d	v;

	num = cross(vector2d(cross(a,b), a.x - b.x), vector2d(cross(c, d), c.x - d.x));
	den = cross(vector2d(a.x - b.x, a.y - b.y), vector2d(c.x - d.x, c.y - d.y));
	v.x = num / den;
	num = cross(vector2d(cross(a,b), a.y - b.y), vector2d(cross(c, d), c.y - d.y));
	den = cross(vector2d(a.x - b.x, a.y - b.y), vector2d(c.x - d.x, c.y - d.y));
	v.y = num / den;
	return (v);

}
