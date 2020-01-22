/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:29:00 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/22 15:29:51 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game.h"
#include "libft.h"
#include "utils.h"

void			game_setup(t_env *env, t_game *var)
{
	uint32_t	i;

	i = 0;
	ft_bzero(var, sizeof(t_game));
	var->head = var->queue;
	var->tail = var->queue;
	var->top = malloc(sizeof(int) * env->w);
	var->bottom = malloc(sizeof(int) * env->w);
	var->render = malloc(sizeof(int) * env->zones);
	var->nearz = 0.0001;
	var->farz = 5;
	var->nearside = 0.00001;
	var->farside = 20;
	while ((int32_t)i < env->w)
	{
		if (i < env->zones)
			var->render[i] = 0;
		var->top[i] = 0;
		var->bottom[i++] = env->h - 1;
	}
	*var->head = item(env->cam.sector, 0, env->w - 1);
	if (++var->head == var->queue + 32)
		var->head = var->queue;
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
