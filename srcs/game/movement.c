/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:47:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/28 17:10:43 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"

void	jump(t_env *env, t_cam *cam)
{
	if (cam->fly > 0
			&& env->sector[cam->sector].ceil - cam->pos.z > MARGIN_HEAD)
		cam->pos.z += 0.25;
	else if (env->sector[cam->sector].type == EFF_JET
			&& env->data.money >= (uint32_t)env->sector[cam->sector].data)
	{
		update_fall(cam, 0.25, 1);
		env->data.money -= env->sector[cam->sector].data;
		env->sector[cam->sector].data = 0;
	}
	else if (cam->ground)
		update_fall(cam, 0.75, 1);
}

void	fly(t_env *env)
{
	check_tick(&env->tick.fly, &env->cam.fly, 160);
	if (env->tick.fly.old == env->tick.fly.new)
	{
		env->cam.fall = (env->cam.fly > 0 ? 0 : 1);
		env->cam.v.z = 0;
	}
}

void	move(t_env *env)
{
	t_vec2d		v;

	v = v2d(0, 0);
	speed_check(env);
	if (env->input[SDL_SCANCODE_W])
	{
		v.x += env->cam.cos * (env->cam.speed * 0.2);
		v.y += env->cam.sin * (env->cam.speed * 0.2);
	}
	if (env->input[SDL_SCANCODE_S])
	{
		v.x -= env->cam.cos * (env->cam.speed * 0.1);
		v.y -= env->cam.sin * (env->cam.speed * 0.1);
	}
	if (env->input[SDL_SCANCODE_A])
	{
		v.x += env->cam.sin * (env->cam.speed * 0.15);
		v.y -= env->cam.cos * (env->cam.speed * 0.15);
	}
	if (env->input[SDL_SCANCODE_D])
	{
		v.x -= env->cam.sin * (env->cam.speed * 0.15);
		v.y += env->cam.cos * (env->cam.speed * 0.15);
	}
	velocity(env, &env->cam, v);
}
