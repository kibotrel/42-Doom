/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:21:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 12:02:40 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "texture.h"

void		blur(t_env *env, SDL_Surface *win, t_pos p)
{
	int			*px;

	if ((p.x >= 0 && p.x < env->w) && (p.y >= 0 && p.y < env->h))
	{
		px = win->pixels + p.y * win->pitch + p.x * win->format->BytesPerPixel;
		*px = color_add(*px, -45);
	}
}

static void	draw_ceil_and_floor(t_env *env, t_game *var, int32_t x)
{
	int32_t		*p;
	int32_t		max;
	int32_t		min;
	t_vec2d		*t;

	max = var->side[1];
	p = var->now;
	t = var->t;
	min = var->side[0];
	var->depth = ((x - min) * (t[1].y - t[0].y) / (max - min) + t[0].y) * 8;
	var->unbound[0] = (x - min) * (p[2] - p[0]) / (max - min) + p[0];
	var->unbound[1] = (x - min) * (p[3] - p[1]) / (max - min) + p[1];
	var->y[0] = bound(var->unbound[0], var->top[x], var->bottom[x]);
	var->y[1] = bound(var->unbound[1], var->top[x], var->bottom[x]);
	draw_slice(env, x, lim(var->top[x], var->y[0] - 1), flat(0, 0x222222, 0));
	draw_slice(env, x, lim(var->y[1] + 1, var->bottom[x]),
				flat(0, 0x0000AA, 0));
}

static void	draw_transitions(t_env *env, t_game *var, int32_t x)
{
	int32_t		*p;
	int32_t		max;
	int32_t		min;
	uint32_t	r1;
	uint32_t	r2;

	r1 = (255 - var->depth < 0 ? 0 : 0x010101 * (255 - var->depth));
	r2 = (31 - var->depth / 8 < 0 ? 0 : 0x040007 * (31 - var->depth / 8));
	max = var->side[1];
	p = var->next;
	min = var->side[0];
	var->unbound[0] = (x - min) * (p[2] - p[0]) / (max - min) + p[0];
	var->unbound[1] = (x - min) * (p[3] - p[1]) / (max - min) + p[1];
	var->ny[0] = bound(var->unbound[0], var->top[x], var->bottom[x]);
	var->ny[1] = bound(var->unbound[1], var->top[x], var->bottom[x]);
	var->top[x] = bound(fmax(var->y[0], var->ny[0]), var->top[x], env->h - 1);
	var->bottom[x] = bound(fmin(var->y[1], var->ny[1]), 0, var->bottom[x]);
	draw_slice(env, x, lim(var->y[0], var->ny[0] - 1),
				flat(0, x == min || x == max ? 0 : r1, 0));
	draw_slice(env, x, lim(var->ny[1] + 1, var->y[1]),
				flat(0, x == min || x == min ? 0 : r2, 0));
}

static void	draw_wall(t_env *env, t_game *var, int32_t *y, int32_t x)
{
	int32_t		end;
	int32_t		min;
	uint32_t	r;

//	r = color_add(0xFFFFFF, -var->depth);
	r = 0xff0000;
	end = var->side[1];
	min = var->side[0];
	draw_slice(env, x, lim(y[0], y[1]),
				flat(0, x == min || x == end ? 0 : r, 0));
}

void		draw_screen(t_env *env, t_game *var)
{
	int32_t		x;

	x = var->start;
	while (x <= var->end)
	{
		draw_ceil_and_floor(env, var, x);
		if (var->n >= 0)
			draw_transitions(env, var, x);
		else
			draw_wall(env, var, var->y, x);
		x++;
	}
}
