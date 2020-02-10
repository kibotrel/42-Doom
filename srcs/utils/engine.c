/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:32:37 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/24 17:14:13 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"

void	transform(t_cam *cam, t_game *var, uint32_t i)
{
	t_vec2d p1;
	t_vec2d	p2;

	p1 = var->s->vertex[i];
	p2 = var->s->vertex[(i + 1) % var->s->points];
	var->v[0] = v2d(p1.x - cam->pos.x, p1.y - cam->pos.y);
	var->v[1] = v2d(p2.x - cam->pos.x, p2.y - cam->pos.y);
	var->t[0].x = var->v[0].x * cam->sin - var->v[0].y * cam->cos;
	var->t[0].y = var->v[0].x * cam->cos + var->v[0].y * cam->sin;
	var->t[1].x = var->v[1].x * cam->sin - var->v[1].y * cam->cos;
	var->t[1].y = var->v[1].x * cam->cos + var->v[1].y * cam->sin;
}

uint8_t	bound_view(t_game *var)
{
	t_vec2d	i[2];
	t_vec2d tmp[4];

	tmp[0] = v2d(-var->nearside, var->nearz);
	tmp[1] = v2d(-var->farside, var->farz);
	tmp[2] = v2d(var->nearside, var->nearz);
	tmp[3] = v2d(var->farside, var->farz);
	if (var->t[0].y <= 0 && var->t[1].y <= 0)
		return (0);
	var->org[0].x = var->t[0].x;
	var->org[1].x = var->t[1].x;
	var->org[0].y = var->t[0].y;
	var->org[1].y = var->t[1].y;
	if (var->t[0].y <= 0 || var->t[1].y <= 0)
	{
		i[0] = intersect(var->t[0], var->t[1], tmp[0], tmp[1]);
		i[1] = intersect(var->t[0], var->t[1], tmp[2], tmp[3]);
		if (var->t[0].y < var->nearz)
			var->t[0] = (i[0].y > 0 ? i[0] : i[1]);
		if (var->t[1].y < var->nearz)
			var->t[1] = (i[0].y > 0 ? i[0] : i[1]);
	}
	return (1);
}

uint8_t	scale(t_env *env, t_game *v, t_item *now)
{
	v->size[0] = v2d(env->cam.fov.x / v->t[0].y, env->cam.fov.y / v->t[0].y);
	v->size[1] = v2d(env->cam.fov.x / v->t[1].y, env->cam.fov.y / v->t[1].y);
	v->side[0] = env->w / 2 - floor(v->t[0].x * v->size[0].x);
	v->side[1] = env->w / 2 - floor(v->t[1].x * v->size[1].x);
	if (v->side[0] >= v->side[1]
		|| v->side[1] < now->min
		|| v->side[0] > now->max)
		return (0);
	else
	{
		v->render[now->sector]++;
		return (1);
	}
}
