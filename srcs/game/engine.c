/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:22:56 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 11:24:39 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	graphics(t_env *env)
{
	t_game		var;
	t_item		now;

	game_setup(env, &var);
	while ((var.i++ == 0 || var.head != var.tail) && !var.error)
	{
		var.j = 0;
		if (cycle_check(env, &var, &now))
			continue;
		while (var.j < var.s->points)
		{
			transform(&env->cam, &var, var.j);
			if ((!bound_view(&var) || !scale(env, &var, &now)) && ++var.j)
				continue;
			draw_setup(env, &var, &now, var.j++);
			draw_screen(env, &var);
			check_depth(&var, var.start, var.end);
		}
	}
	if (var.sky > env->data.sky)
		env->data.sky = var.sky;
	if (var.error)
		env->crash = 1;
	engine_clean(&var);
	pthread_exit(NULL);
}
