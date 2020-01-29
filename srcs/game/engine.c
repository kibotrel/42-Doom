/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:22:56 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 10:08:54 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "game.h"
#include "clean.h"
#include "setup.h"
#include "utils.h"

void	physics(t_env *env)
{
	double		sight;
	t_vec2d		pos;
	t_vec2d		vel;
	t_sector	*sector;

	sector = &env->sector[env->cam.sector];
	pos = v2d(env->cam.pos.x, env->cam.pos.y);
	vel = v2d(env->cam.v.x, env->cam.v.y);
	sight = env->cam.sneak ? SNEAK_H : CAM_H;
	while (sector->ceil <= sector->floor + sight)
		sight -= 1;
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

void	graphics(t_env *env)
{
	uint32_t	i[2];
	t_game		var;
	t_item		now;

	i[0] = 0;
	game_setup(env, &var);
	while (i[0]++ == 0 || var.head != var.tail)
	{
		i[1] = 0;
		if (cycle_check(env, &var, &now))
			continue;
		while (i[1] < var.s->points)
		{
			transform(&env->cam, &var, i[1]);
			if (!bound_view(&var) || !scale(env, &var, &now))
			{
				i[1]++;
				continue;
			}
			draw_setup(env, &var, &now, i[1]++);
			draw_screen(env, &var);
			check_depth(&var, var.start, var.end);
		}
	}
	engine_clean(&var);
}
