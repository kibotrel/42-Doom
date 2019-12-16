/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:47:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/16 16:32:04 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game.h"
#include "utils.h"

void	jump(t_cam *cam)
{
	if (cam->ground)
	{
		cam->v.z += 0.75;
		cam->fall = 1;
	}
}

void	move(t_env *env)
{
	t_vec2d		v;

	v = v2d(0, 0);
	if (env->input[SDL_SCANCODE_W])
	{
		v.x += env->cam.cos * 0.2;
		v.y += env->cam.sin * 0.2;
	}
	if (env->input[SDL_SCANCODE_S])
	{
		v.x -= env->cam.cos * 0.2;
		v.y -= env->cam.sin * 0.2;
	}
	if (env->input[SDL_SCANCODE_A])
	{
		v.x += env->cam.sin * 0.2;
		v.y -= env->cam.cos * 0.2;
	}
	if (env->input[SDL_SCANCODE_D])
	{
		v.x -= env->cam.sin * 0.2;
		v.y += env->cam.cos * 0.2;
	}
	velocity(env, &env->cam, v);
}
