/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/13 07:46:35 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "env.h"
#include "game.h"
#include "clean.h"
#include "libft.h"
#include "utils.h"

#define EyeHeight  6    // Camera height from floor when standing
#define DuckHeight 2.5  // And when crouching
#define HeadMargin 1    // How much room there is above camera before the head hits the ceiling
#define KneeHeight 2    // How tall obstacles the player can simply walk over without jumping

//double min(double a, double b)
//{
//	return ((a < b ? a : b));
//}
//
//double max(double a, double b)
//{
//	return ((a > b ? a : b));
//}
//
//double clamp(double a, double mi, double ma)
//{
//	return (min(max(a,mi),ma));
//}
//
// vxs: Vector cross product
//double vxs(double x0, double y0, double x1, double y1)
//{
//	return (x0 * y1 - x1 * y0);
//}
// Overlap:  Determine whether the two number ranges overlap.
//double Overlap(double a0, double a1, double b0, double b1)
//{
//	return ((min(a0, a1) <= max(b0, b1) && min(b0, b1) <= max(a0, a1)));
//}
// IntersectBox: Determine whether two 2D-boxes intersect.
//double IntersectBox(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3)
//{
//	return((Overlap(x0, x1, x2, x3) && Overlap(y0, y1, y2, y3)));
//}
// PointSide: Determine which side of a line the point is on. Return value: <0, =0 or >0.
//double PointSide(double px, double py, double x0, double y0, double x1, double y1)
//{
//	return (vxs(x1 -x0, y1 - y0, px - x0, py - y0));
//}
// Intersect: Calculate the point of intersection between two lines.
//t_vec2d Intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
//{
//	t_vec2d p;
//
//	p.x = vxs(vxs(x1 , y1, x2 , y2), x1 - x2, vxs(x3 , y3, x4 , y4), x3 - x4) / vxs(x1 - x2, y1 - y2, x3 - x4, y3 - y4);
//	p.y = vxs(vxs(x1 , y1, x2 , y2), y1 - y2, vxs(x3 , y3, x4 , y4), y3 - y4) / vxs(x1 - x2, y1 - y2, x3 - x4, y3 - y4);
//	return (p);
//}

static t_vec2d v2d(double x, double y)
{
	t_vec2d	p;

	p.x = x;
	p.y = y;
	return (p);
}

static t_vec3d v3d(double x, double y, double z)
{
	t_vec3d	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

static void	engine_setup(t_env *env)
{
	env->setup = 0;
	env->zones = 1; //PARSER
	ft_bzero(&env->cam, sizeof(t_cam));
	env->cam.pos = v3d(16, 8, 0); //PARSER
	env->cam.fov = v2d(0.75 * env->h, 0.2 * env->h);
	env->cam.angle = M_PI / 2; //PARSER
	env->cam.sector = 0; //PARSER
	env->cam.fall = 1;
	if (!(env->sector = (t_sector*)malloc(sizeof(t_sector) * env->zones)))
		clean(env, E_MALLOC);
	if (!(env->sector[0].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 5)))
		clean(env, E_MALLOC);
	if (!(env->sector[0].neighbor = (int32_t*)malloc(sizeof(int32_t) * 4)))
		clean(env, E_MALLOC);
	env->sector[0].ceil = 20;
	env->sector[0].floor = 0;
	env->sector[0].vertex[0] = v2d(8,0); //PARSER
	env->sector[0].vertex[0] = v2d(24,0); //PARSER
	env->sector[0].vertex[0] = v2d(24,24); //PARSER
	env->sector[0].vertex[0] = v2d(8,24); //PARSER
	env->sector[0].vertex[4] = env->sector[0].vertex[0];
	for (int i = 0; i < 4; i++)
		env->sector[0].neighbor[i] = -1; //PARSER
	env->cam.pos.z = env->sector[env->cam.sector].floor + EyeHeight;
}
void		game(t_env *env)
{
	if (!env->setup)
	{
		SDL_SetWindowTitle(env->sdl.win, TITLE_GAME);
		engine_setup(env);
	}
//	graphic_engine(env);
//	physics_engine(env);
}
