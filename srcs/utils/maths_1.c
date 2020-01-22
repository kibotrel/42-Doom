/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:18:32 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/14 13:19:39 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"

t_vec2d	intersect(t_vec2d v1, t_vec2d v2, t_vec2d v3, t_vec2d v4)
{
	t_vec2d	p;
	t_vec2d	tmp[6];

	tmp[0] = v2d(vxs(v1, v2), v1.x - v2.x);
	tmp[1] = v2d(vxs(v3, v4), v3.x - v4.x);
	tmp[2] = v2d(v1.x - v2.x, v1.y - v2.y);
	tmp[3] = v2d(v3.x - v4.x, v3.y - v4.y);
	tmp[4] = v2d(vxs(v1, v2), v1.y - v2.y);
	tmp[5] = v2d(vxs(v3, v4), v3.y - v4.y);
	p.x = vxs(tmp[0], tmp[1]) / vxs(tmp[2], tmp[3]);
	p.y = vxs(tmp[4], tmp[5]) / vxs(tmp[2], tmp[3]);
	return (p);
}

double	side(t_vec2d p, t_vec2d v0, t_vec2d v1)
{
	t_vec2d tmp[2];

	tmp[0] = v2d(v1.x - v0.x, v1.y - v0.y);
	tmp[1] = v2d(p.x - v0.x, p.y - v0.y);
	return (vxs(tmp[0], tmp[1]));
}

int		hitbox(t_vec2d v0, t_vec2d v1, t_vec2d v2, t_vec2d v3)
{
	return ((overlap(v0.x, v1.x, v2.x, v3.x)
			&& overlap(v0.y, v1.y, v2.y, v3.y)));
}

void	vproj(t_vec3d *v, t_vec2d v1, t_vec2d v2)
{
	t_vec2d		w;

	w = v2d(v2.x - v1.x, v2.y - v1.y);
	v->x = w.x * (v->x * w.x + w.y * v->y) / (pow(w.x, 2) + pow(w.y, 2));
	v->y = w.y * (v->x * w.x + w.y * v->y) / (pow(w.x, 2) + pow(w.y, 2));
}

void	velocity(t_env *env, t_cam *cam, t_vec2d v)
{
	int		move;
	double	speed;

	if (env->input[SDL_SCANCODE_W] || env->input[SDL_SCANCODE_S]
		|| env->input[SDL_SCANCODE_A] || env->input[SDL_SCANCODE_D])
		move = 1;
	else
		move = 0;
	speed = (move ? 0.4 : 0.2);
	cam->v.x = cam->v.x * (1 - speed) + v.x * speed;
	cam->v.y = cam->v.y * (1 - speed) + v.y * speed;
	if (move)
		env->cam.move = 1;
}
