/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:21:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/28 14:19:39 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "texture.h"

static void	draw_ceil_and_floor(t_env *env, t_game *var, int32_t x)
{
	int32_t		*p;
	int32_t		max;
	int32_t		min;
	int32_t		r_size_wall;
	t_vec2d		*t;

	max = var->side[1];
	p = var->now;
	t = var->t;
	min = var->side[0];
	var->unbound[0] = (x - min) * (p[2] - p[0]) / (max - min) + p[0];
	var->unbound[1] = (x - min) * (p[3] - p[1]) / (max - min) + p[1];
	r_size_wall = 7 * (var->unbound[1] - var->unbound[0]) / (var->ceil[0] - var->floor[0]);
	var->depth = 4096 / r_size_wall;
	var->y[0] = bound(var->unbound[0], var->top[x], var->bottom[x]);
	var->y[1] = bound(var->unbound[1], var->top[x], var->bottom[x]);
	draw_slice(env, x, lim(var->top[x], var->y[0] - 1), flat(0, 0x222222, 0));
	draw_slice(env, x, lim(var->y[1] + 1, var->bottom[x]),
				flat(0, 0x0000AA, 0));
}

static void	draw_transitions(t_env *env, t_game *var, int32_t x, uint32_t *wall)
{
	int32_t		*p;
	int32_t		max;
	int32_t		min;
//	uint32_t	r1;
//	uint32_t	r2;

	//r1 = color_add(0xffffff, -2 * var->depth);
	//r2 = color_add(0xff00ff, -2 * var->depth);
	max = var->side[1];
	p = var->next;
	min = var->side[0];
	var->unbound[0] = (x - min) * (p[2] - p[0]) / (max - min) + p[0];
	var->unbound[1] = (x - min) * (p[3] - p[1]) / (max - min) + p[1];
	var->ny[0] = bound(var->unbound[0], var->top[x], var->bottom[x]);
	var->ny[1] = bound(var->unbound[1], var->top[x], var->bottom[x]);
	var->top[x] = bound(fmax(var->y[0], var->ny[0]), var->top[x], env->h - 1);
	var->bottom[x] = bound(fmin(var->y[1], var->ny[1]), 0, var->bottom[x]);
	draw_texture_slice(env, x, lim(var->y[0], var->ny[0]),
				var, wall);
	draw_texture_slice(env, x, lim(var->ny[1] + 1, var->y[1]),
				var, wall);
}

static void	draw_wall(t_env *env, t_game *var, int32_t *y, int32_t x, uint32_t *wall)
{
	draw_texture_slice(env, x, lim(y[0], y[1]), var, wall);
}

void		draw_screen(t_env *env, t_game *var)
{
	int32_t		x;
	t_bmp		wall;

	bmp_to_array("assets/wall.bmp", &wall);
	x = var->start;
	while (x <= var->end)
	{
		draw_ceil_and_floor(env, var, x);
		if (var->n >= 0)
			draw_transitions(env, var, x, wall.pixels);
		else
			draw_wall(env, var, var->y, x, wall.pixels);
		x++;
	}
}
