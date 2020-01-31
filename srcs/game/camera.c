/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:21:04 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/31 22:18:01 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "game.h"
#include "utils.h"

void	cam_motion(t_env *env, t_cam *cam, int x, int y)
{
	t_vec2d		p;

	if (cam->ground || cam->fly > 0)
	{
		p = v2d(0, 0);
		p.x -= (env->w / 2 - x) / 8;
		p.y += (env->h / 2 - y) / 8;
		cam->angle += p.x * 0.03;
		cam->gap = bound(cam->gap - p.y * 0.05, -10, 10) - cam->v.z * 0.5;
		update_cam(env, v2d(0, 0));
	}
}

void	update_cam(t_env *env, t_vec2d vel)
{
	t_vec2d		p;
	t_vec2d		*v;
	uint32_t	i;
	t_sector	*s;

	i = 0;
	s = &env->sector[env->cam.sector];
	v = s->vertex;
	p = v2d(env->cam.pos.x, env->cam.pos.y);
	while (i < s->points)
	{
		if (s->neighbor[i] >= 0
			&& check_collisions(p, vel, v[i], v[(i + 1) % s->points]))
		{
			env->cam.sector = s->neighbor[i];
			break ;
		}
		i++;
	}
	env->cam.pos.x += vel.x;
	env->cam.pos.y += vel.y;
	env->cam.sin = sin(env->cam.angle);
	env->cam.cos = cos(env->cam.angle);
}

void	cam_height(t_env *env, int32_t crouch)
{
	if (env->cam.fly > 0 && crouch
		&& env->cam.pos.z > env->sector[env->cam.sector].floor + MARGIN_KNEE)
		env->cam.pos.z -= 0.25;
	else if (crouch)
	{
		env->cam.fall = 1;
		env->cam.sneak = 1;
		env->cam.speed = 0.5;
	}
	else
	{
		env->cam.sneak = 0;
		env->cam.speed = 1;
	}
}

void	fov_update(t_env *env)
{
	if (env->input[SDL_SCANCODE_UP])
	{
		if (env->cam.fov.x < env->h * 2 && env->cam.fov.y < env->h * 2)
		{
			env->cam.fov.x += (0.0375 * env->h);
			env->cam.fov.y += (0.01 * env->h);
		}
	}
	if (env->input[SDL_SCANCODE_DOWN])
	{
		if (env->cam.fov.x > env->h / 16 && env->cam.fov.y > env->h / 16)
		{
			env->cam.fov.x -= (0.0375 * env->h);
			env->cam.fov.y -= (0.01 * env->h);
		}
	}
}
