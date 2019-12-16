/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:21:04 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/16 12:25:21 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"

void	cam_motion(t_env *env, t_cam *cam, int x, int y)
{
	t_vec2d		p;

	p = v2d(0, 0);
	p.x -= (env->w / 2 - x) / 12;
	p.y += (env->h / 2 - y) / 12;
	cam->angle += p.x * 0.03;
	cam->gap = bound(cam->gap - p.y * 0.05, -10, 10) - cam->v.z * 0.5;
	if (!cam->fall)
		update_cam(env, 0, 0);
}

void	update_cam(t_env *env, float x, float y)
{
	uint32_t	i;
	t_sector	*s = &env->sector[env->cam.sector];
	t_vec2d		*v = s->vertex;
	t_vec3d		pos;
	t_vec3d		vel;

	i = 0;
	vel = v3d(x, y, 0);
	pos = v3d(env->cam.pos.x, env->cam.pos.y, 0);
	while (i < s->points)
	{
		if (s->neighbor[i] >= 0 && check_collisions(pos, vel, v[i], v[i + 1]))
		{
			env->cam.sector = s->neighbor[i];
			break;
		}
		i++;
	}
	env->cam.pos.x += x;
	env->cam.pos.y += y;
	env->cam.sin = sin(env->cam.angle);
	env->cam.cos = cos(env->cam.angle);
}
