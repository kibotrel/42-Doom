/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:18:26 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 12:01:44 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "env.h"
#include "game.h"
#include "utils.h"

int32_t		check_collisions(t_vec2d old, t_vec2d v, t_vec2d w1, t_vec2d w2)
{
	t_vec2d		new;

	new = v2d(old.x + v.x, old.y + v.y);
	if (hitbox(old, new, w1, w2))
	{
		if (side(new, w1, w2) < 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static void	find_height(t_env *env, double *hole, uint32_t s)
{
	int32_t		cam;
	int32_t		neighbor;

	cam = env->cam.sector;
	neighbor = env->sector[cam].neighbor[s];
	if (neighbor < 0)
	{
		hole[0] = INT_MAX;
		hole[1] = INT_MIN;
	}
	else
	{
		hole[0] = fmax(env->sector[cam].floor, env->sector[neighbor].floor);
		hole[1] = fmin(env->sector[cam].ceil, env->sector[neighbor].ceil);
	}
}

void		vertical_movement(t_env *env, t_sector sector, double cam_height)
{
	double	newz;

	if (env->cam.fly < 0)
		env->cam.v.z -= env->sector[env->cam.sector].gravity;
	newz = env->cam.pos.z + env->cam.v.z;
	if (env->cam.v.z < 0 && newz < sector.floor + cam_height)
	{
		env->cam.pos.z = sector.floor + cam_height;
		env->cam.v.z = 0;
		env->cam.fall = 0;
		env->cam.ground = 1;
	}
	else if (env->cam.v.z > 0 && newz > sector.ceil)
	{
		env->cam.v.z = 0;
		env->cam.fall = 1;
	}
	if (env->cam.fall)
	{
		env->cam.pos.z += env->cam.v.z;
		env->cam.move = 1;
	}
}

//
//	Need to replace vel = 0 by sliding algorithm
//

void		horizontal_movement(t_env *env, t_vec2d p, t_vec2d vel, double view)
{
	uint32_t	i;
	uint32_t	points;
	double		hole[2];
	t_vec2d		*v;

	v = env->sector[env->cam.sector].vertex;
	i = 0;
	points = env->sector[env->cam.sector].points;
	while (i < points)
	{
		if (check_collisions(p, vel, v[i], v[(i + 1) % points]))
		{
			find_height(env, hole, i);
			if (hole[0] > env->cam.pos.z - view + MARGIN_KNEE
				|| hole[1] < env->cam.pos.z + MARGIN_HEAD)
			{
				vel.x = 0;
				vel.y = 0;
				env->cam.move = 0;
			}
		}
		i++;
	}
	update_cam(env, vel);
	env->cam.fall = 1;
}
