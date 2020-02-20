/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:21:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/20 21:05:46 by demonwaves       ###   ########.fr       */
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
	int32_t		r_size_wall;

	max = var->side[1];
	p = var->now;
	min = var->side[0];
	var->unbound[0] = (x - min) * (p[2] - p[0]) / (max - min) + p[0];
	var->unbound[1] = (x - min) * (p[3] - p[1]) / (max - min) + p[1];
	r_size_wall = 7 * (var->unbound[1] - var->unbound[0]) / (var->ceil[0] - var->floor[0]); /*can be a variable*/
	var->depth = W_UNIT / (r_size_wall != 0 ? r_size_wall : 1);
	var->y[0] = bound(var->unbound[0], var->top[x], var->bottom[x]);
	var->y[1] = bound(var->unbound[1], var->top[x], var->bottom[x]);
	if (var->sector != 0 && var->sector != 6 && var->sector != 7)
		draw_slice(env, x, lim(var->top[x], var->y[0] - 1), flat(0, color_light(0x222222, env->sector[var->sector].light), 0));
	else
	setup_sky(env, lim(var->top[x], var->y[0] - 1), var, x);
	draw_slice(env, x, lim(var->y[1] + 1, var->bottom[x]), flat(0, color_light(0x424242, env->sector[var->sector].light), 0));
}

static void	draw_transitions(t_env *env, t_game *var, int32_t x)
{
	int32_t		*p;
	int32_t		max;
	int32_t		min;

	max = var->side[1];
	p = var->next;
	min = var->side[0];
	var->unbound[0] = (x - min) * (p[2] - p[0]) / (max - min) + p[0];
	var->unbound[1] = (x - min) * (p[3] - p[1]) / (max - min) + p[1];
	var->ny[0] = bound(var->unbound[0], var->top[x], var->bottom[x]);
	var->ny[1] = bound(var->unbound[1], var->top[x], var->bottom[x]);
	var->top[x] = bound(fmax(var->y[0], var->ny[0]), var->top[x], env->h - 1);
	var->bottom[x] = bound(fmin(var->y[1], var->ny[1]), 0, var->bottom[x]);
	var->text_height = fabs(var->ceil[1] - var->floor[1]);
	draw_texture_slice(env, x, lim(var->y[0], var->ny[0]),
				var);
	draw_texture_slice(env, x, lim(var->ny[1] + 1, var->y[1]),
				var);
}

static void	draw_wall(t_env *env, t_game *var, int32_t x)
{
	var->text_height = fabs(var->ceil[0] - var->floor[0]);
	draw_texture_slice(env, x, lim(var->y[0], var->y[1]), var);
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
			draw_wall(env, var, x);
		x++;
	}
}
