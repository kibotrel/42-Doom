/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:29:00 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 12:53:20 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "libft.h"
#include "utils.h"

static uint8_t	area_setup(t_env *env, t_game *var)
{
	if (!(var->top = malloc(sizeof(int) * env->w)))
		return (0);
	if (!(var->bottom = malloc(sizeof(int) * env->w)))
		return (0);
	if (!(var->render = malloc(sizeof(int) * env->zones)))
		return (0);
	return (1);
}

int				game_setup(t_env *env, t_game *var)
{
	uint32_t	i;

	i = 0;
	ft_bzero(var, sizeof(t_game));
	var->thread = get_thread(env);
	var->head = var->queue;
	var->tail = var->head;
	if (!area_setup(env, var))
	{
		var->error = 1;
		return (0);
	}
	side_infos(var);
	while ((int32_t)i < env->w)
	{
		if (i < env->zones)
			var->render[i] = 0;
		var->top[i] = 0;
		var->bottom[i++] = env->h - 1;
	}
	*var->head = item(env->cam.sector, var->thread * env->data.thread,
						(var->thread + 1) * (env->data.thread) - 1);
	if (++var->head == var->queue + 32)
		var->head = var->queue;
	return (1);
}

static int32_t	locate(t_game *v, double space, uint32_t vertex, uint32_t i)
{
	if (vertex % 2)
	{
		if (vertex == 1)
			return ((int)(gap(v->floor[i], v->t[0].y, space) * v->size[0].y));
		else
			return ((int)(gap(v->floor[i], v->t[1].y, space) * v->size[1].y));
	}
	else
	{
		if (vertex == 0)
			return ((int)(gap(v->ceil[i], v->t[0].y, space) * v->size[0].y));
		else
			return ((int)(gap(v->ceil[i], v->t[1].y, space) * v->size[1].y));
	}
}

void			draw_setup(t_env *env, t_game *var, t_item *now, uint32_t i)
{
	var->ceil[0] = var->s->ceil - env->cam.pos.z;
	var->ceil[1] = 0;
	var->floor[0] = var->s->floor - env->cam.pos.z;
	var->floor[1] = 0;
	var->n = var->s->neighbor[i];
	if (env->sector[var->n].ceil <= env->sector[now->sector].floor)
		var->n = -1;
	var->sector = now->sector;
	if (var->n >= 0)
	{
		var->ceil[1] = env->sector[var->n].ceil - env->cam.pos.z;
		var->floor[1] = env->sector[var->n].floor - env->cam.pos.z;
	}
	i = 0;
	while (i < 4)
	{
		var->now[i] = env->h / 2 - locate(var, env->cam.gap, i, 0);
		var->next[i] = env->h / 2 - locate(var, env->cam.gap, i, 1);
		i++;
	}
	var->start = fmax(var->side[0], now->min);
	var->end = fmin(var->side[1], now->max);
}

void			skybox_setup(t_env *env, t_skybox *skybox)
{
	ft_bzero(skybox, sizeof(t_skybox));
	skybox->draw = env->sdl.bmp[SKYBOX].width;
	skybox->shift.x = ft_degrees(env->cam.angle) * (env->w) / 90;
	skybox->shift.y = env->sdl.bmp[SKYBOX].height - env->data.sky;
	skybox->image = env->sdl.bmp[SKYBOX].pixels;
}
