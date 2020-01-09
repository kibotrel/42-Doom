/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:47:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/09 08:13:38 by vivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game.h"
#include "utils.h"

void	jump(t_env *env, t_cam *cam)
{
	if (cam->fly > 0 && env->sector[cam->sector].ceil - cam->pos.z > MARGIN_HEAD)
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
		v.x += env->cam.cos * (0.2 * env->cam.speed);
		v.y += env->cam.sin * (0.2 * env->cam.speed);
	}
	if (env->input[SDL_SCANCODE_S])
	{
		v.x -= env->cam.cos * (0.1 * env->cam.speed);
		v.y -= env->cam.sin * (0.1 * env->cam.speed);
	}
	if (env->input[SDL_SCANCODE_A])
	{
		v.x += env->cam.sin * (0.15 * env->cam.speed);
		v.y -= env->cam.cos * (0.15 * env->cam.speed);
	}
	if (env->input[SDL_SCANCODE_D])
	{
		v.x -= env->cam.sin * (0.15 * env->cam.speed);
		v.y += env->cam.cos * (0.15 * env->cam.speed);
	}
	velocity(env, &env->cam, v);
}
