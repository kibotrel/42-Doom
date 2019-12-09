/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:47:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/09 06:40:55 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "utils.h"
#include "structs.h"

/* MovePlayer(dx,dy): Moves the player by (dx,dy) in the map, and
 * also updates their anglesin/anglecos/sector properties properly.
 */
void MovePlayer(t_env *env, float dx, float dy)
{
	/* Check if this movement crosses one of this sector's edges
	* that have a neighboring sector on the other side.
	* Because the edge vertices of each sector are defined in
	* clockwise order, PointSide will always return -1 for a point
	* that is outside the sector and 0 or 1 for a point that is inside.
	*/
	float px = env->cam.pos.x;
	float py = env->cam.pos.y;

	const t_sector* const sect = &env->sector[env->cam.sector];
	const t_vec2d* const vert = sect->vertex;
	for(unsigned s = 0; s < sect->points; ++s)
		if (sect->neighbor[s] >= 0
		&& IntersectBox(px,py, px+dx,py+dy, vert[s+0].x, vert[s+0].y, vert[s+1].x, vert[s+1].y)
		&& PointSide(px+dx, py+dy, vert[s+0].x, vert[s+0].y, vert[s+1].x, vert[s+1].y) < 0)
		{
			env->cam.sector = sect->neighbor[s];
			break;
		}
	env->cam.pos.x += dx;
	env->cam.pos.y += dy;
	env->cam.sin = sin(env->cam.angle);
	env->cam.cos = cos(env->cam.angle);
}
