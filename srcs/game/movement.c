/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:47:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/12 10:48:22 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game.h"
#include "utils.h"

void move(t_env *env, float x, float y)
{
	uint32_t	i;
	t_sector	*s = &env->sector[env->cam.sector];
	t_vec2d		*v = s->vertex;
	t_vec3d		pos;
	t_vec3d		vel;

	i = 0;
	vel = v3d(x, y, 0);
	pos = v3d(env->cam.pos.x, env->cam.pos.y, 0);
	while (i < s->points)
	{
		if (s->neighbor[i] >= 0 && check_collisions(pos, vel, v[i], v[i + 1]))
		{
			env->cam.sector = s->neighbor[i];
			break;
		}
		i++;
	}
	env->cam.pos.x += x;
	env->cam.pos.y += y;
	env->cam.sin = sin(env->cam.angle);
	env->cam.cos = cos(env->cam.angle);
}
