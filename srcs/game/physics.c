/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:18:26 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 10:20:14 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <math.h>
#include "utils.h"
#include "clean.h"

void		fall_damage(t_env *env)
{
	int			gravity;
	double		damage;
	double		height;

	damage = 0;
	gravity = env->sector[env->cam.sector].gravity * 10;
	height = (!env->cam.sneak ? CAM_H : SNEAK_H);
	env->track_fall = (!env->cam.ground ? 1 : 0);
	if (env->track_fall && env->cam.fly < 0)
		peak_point(env, env->sector[env->cam.sector].floor, height);
	else if (env->data.fall_height > INT_MIN && env->cam.fly < 0)
	{
		env->data.height_end = env->sector[env->cam.sector].floor;
		if (env->data.fall_height - 12 > 0)
			damage = (env->data.fall_height - (12 * (1 / gravity)) * gravity);
		damage = fabs(difficulty_scale(env, damage));
		env->data.life -= damage;
		if (env->data.life <= 0)
			clean(env, DEATH);
		env->data.fall_height = INT_MIN;
	}
	else if (!env->cam.v.x && !env->cam.v.y)
		env->data.height_start = env->sector[env->cam.sector].floor;
}

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
		env->cam.pos.z += env->cam.v.z;
}

void		horizontal_movement(t_env *env, t_vec2d p, t_vec2d vel, double view)
{
	uint32_t	i;
	uint32_t	points;
	double		hole[2];
	t_vec2d		*v;

	v = env->sector[env->cam.sector].vertex;
	i = 0;
	points = env->sector[env->cam.sector].points;
	update_velocity(&env->cam.v, &vel);
	while (i < points)
	{
		if (check_collisions(p, vel, v[i], v[(i + 1) % points]))
		{
			find_height(env, hole, i);
			if (hole[0] > env->cam.pos.z - view + MARGIN_KNEE
				|| hole[1] < env->cam.pos.z + MARGIN_HEAD)
			{
				vel = (t_vec2d){0, 0};
				env->cam.move = 0;
			}
		}
		i++;
	}
	env->cam.fall = 1;
	update_cam(env, vel);
}
