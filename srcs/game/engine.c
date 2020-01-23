/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:22:56 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/23 20:11:59 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "game.h"
#include "setup.h"
#include "utils.h"

void	physics(t_env *env)
{
	double		sight;
	t_vec2d		pos;
	t_vec2d		vel;

	pos = v2d(env->cam.pos.x, env->cam.pos.y);
	vel = v2d(env->cam.v.x, env->cam.v.y);
	sight = env->cam.sneak ? SNEAK_H : CAM_H;
	env->cam.ground = !env->cam.fall;
	if (env->cam.fall)
		vertical_movement(env, env->sector[env->cam.sector], sight);
	if (env->cam.move)
		horizontal_movement(env, pos, vel, sight);
}

//
//	WORK IN PROGRESS TEXTURES
//
//	t_bmp		bmp;
//	bmp_to_array("/Users/lojesu/exo42/42-Doom/srcs/texture/wall1.bmp", &bmp);
//
//	PS : Vu que la structure du code à changé, ce que tu es entrain de faire
//	ce trouve maintenant dans draw_screen() tu auras surement besoin de
//	changer le prototype mais tout y est !
//

void	graphics(t_env *env, t_game *var)
{
	uint32_t	i;
	uint32_t	j;
	t_item		now;

	i = 0;
	while (i++ == 0 || var->head != var->tail)
	{
		j = 0;
		if (cycle_check(env, var, &now))
			continue;
		while (j < var->s->points)
		{
			transform(&env->cam, var, j);
			if (!bound_view(var) || !scale(env, var, &now))
			{
				j++;
				continue;
			}
			draw_setup(env, var, &now, j);
			draw_screen(env, var);
			check_depth(var, var->start, var->end);
			j++;
		}
	}
}
