/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:47:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 10:56:44 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "env.h"

void	jump(t_env *env, t_cam *cam)
{
	if (cam->fly > 0
		&& env->sector[cam->sector].ceil - cam->pos.z > MARGIN_HEAD)
		cam->pos.z += 0.25;
	else if (cam->ground)
	{
		cam->v.z += 0.75;
		cam->fall = 1;
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
		v.x -= env->cam.cos * (0.5 * env->cam.speed * 0.2);
		v.y -= env->cam.sin * (0.5 * env->cam.speed * 0.2);
	}
	if (env->input[SDL_SCANCODE_A])
	{
		v.x += env->cam.sin * (0.75 * env->cam.speed * 0.2);
		v.y -= env->cam.cos * (0.75 * env->cam.speed * 0.2);
	}
	if (env->input[SDL_SCANCODE_D])
	{
		v.x -= env->cam.sin * (0.75 * env->cam.speed * 0.2);
		v.y += env->cam.cos * (0.75 * env->cam.speed * 0.2);
	}
	velocity(env, &env->cam, v);
}
