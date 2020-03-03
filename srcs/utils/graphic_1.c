/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:21:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/03 17:46:12 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "texture.h"

#define FLOOR 0x424242
#define CEIL 0x222222

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
	uint32_t	border;

	max = var->side[1];
	p = var->now;
	min = var->side[0];
	var->unbound[0] = (x - min) * (p[2] - p[0]) / (max - min) + p[0];
	var->unbound[1] = (x - min) * (p[3] - p[1]) / (max - min) + p[1];
	r_size_wall = env->setting.fog_intensity * (var->unbound[1] - var->unbound[0]) / (var->ceil[0] - var->floor[0]);
	var->depth = W_UNIT / (r_size_wall != 0 ? r_size_wall : 1) * env->setting.fog_on_off;
	var->y[0] = bound(var->unbound[0], var->top[x], var->bottom[x]);
	var->y[1] = bound(var->unbound[1], var->top[x], var->bottom[x]);
	border = color_light(CEIL, env->sector[var->sector].light, env->setting.light_intensity) * !env->setting.border_on_off;
	draw_slice(env, x, lim(var->top[x], var->y[0] - 1),
			flat(border, color_light(CEIL, env->sector[var->sector].light, env->setting.light_intensity), border));
	border = color_light(FLOOR, env->sector[var->sector].light, env->setting.light_intensity) * !env->setting.border_on_off;
	draw_slice(env, x, lim(var->y[1] + 1, var->bottom[x]),
			flat(border, color_light(FLOOR, env->sector[var->sector].light, env->setting.light_intensity), border));
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
	/*(void)var;  //wesh killian tu commente les deux ligne du haut et tu decommente ces 3 lignes
	(void)wall;
	draw_slice(env, x, lim(y[0], y[1]), flat(0, 0x654321, 0));*/
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
