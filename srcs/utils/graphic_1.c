/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:21:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/05 22:10:26 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "texture.h"

#define FLOOR 0x424242
#define CEIL 0x222222
#define LAVA_FLOOR 0x330000
#define HEAL_FLOOR 0x29a329

static uint32_t	select_floor_color(t_env *env, t_game *var)
{
	if (env->sector[var->sector].type == LAVA)
		return (LAVA_FLOOR);
	else if (env->sector[var->sector].type == HEAL)
		return (HEAL_FLOOR);
	return (FLOOR);
}

static void	draw_ceil_and_floor_part2(t_env *env, t_game *var, int32_t x)
{
	uint32_t	border;

	if (env->sector[var->sector].type == TMP_SKY)
		setup_sky(env, lim(var->top[x], var->y[0] - 1), var, x);
	else
	{
		border = color_light(CEIL, env->sector[var->sector].light,
				env->setting.light_intensity) * !env->setting.border_on_off;
		draw_slice(env, x, lim(var->top[x], var->y[0] - 1), flat(
					border, color_light(CEIL, env->sector[var->sector].light,
						env->setting.light_intensity), border));
	}
	border = color_light(select_floor_color(env, var), env->sector[var->sector].light,
			env->setting.light_intensity) * !env->setting.border_on_off;
	draw_slice(env, x, lim(var->y[1] + 1, var->bottom[x]), flat(
				border, color_light(select_floor_color(env, var), env->sector[var->sector].light,
					env->setting.light_intensity), border));
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
	r_size_wall = env->setting.fog_intensity * (var->unbound[1] -
			var->unbound[0]) / (var->ceil[0] - var->floor[0]);
	var->depth = W_UNIT / (r_size_wall != 0 ? r_size_wall : 1) *
		env->setting.fog_on_off;
	var->y[0] = bound(var->unbound[0], var->top[x], var->bottom[x]);
	var->y[1] = bound(var->unbound[1], var->top[x], var->bottom[x]);
	draw_ceil_and_floor_part2(env, var, x);
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
	draw_texture_slice(env, x, lim(var->ny[1], var->y[1] + 1),
			var);
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
		{
			var->text_height = fabs(var->ceil[0] - var->floor[0]);
			draw_texture_slice(env, x, lim(var->y[0], var->y[1] + 1), var);
		}
		x++;
	}
}
