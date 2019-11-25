/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:45:38 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/25 23:36:24 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"
#include "clean.h"
#include "events.h"

#define HeadMargin	1
#define KneeHeight	2
#define EyeHeight	6
#define DuckHeight	2.5
#define min(a,b)										(((a) < (b)) ? (a) : (b))
#define max(a,b)										(((a) > (b)) ? (a) : (b))
#define clamp(a, mi,ma)									min(max(a,mi),ma)
#define vxs(x0, y0, x1, y1)								((x0) * (y1) - (x1) * (y0))
#define Overlap(a0,a1,b0,b1)							(min(a0, a1) <= max(b0, b1) && min(b0, b1) <= max(a0, a1))
#define IntersectBox(x0, y0, x1, y1, x2, y2, x3, y3)	(Overlap(x0, x1, x2, x3) && Overlap(y0, y1, y2, y3))
#define PointSide(px , py, x0 , y0, x1 , y1) 			vxs((x1) - (x0), (y1) - (y0), (px) - (x0), (py) - (y0))
#define Intersect(x1, y1, x2, y2, x3, y3, x4, y4) 		((t_vec2d) {vxs(vxs(x1, y1, x2, y2), (x1) - (x2), vxs(x3, y3, x4, y4), (x3) - (x4)) / vxs((x1) - (x2), (y1)- (y2), (x3)- (x4), (y3)- (y4)), vxs(vxs(x1, y1, x2, y2), (y1) - (y2), vxs(x3, y3, x4, y4), (y3) - (y4)) / vxs((x1) - (x2), (y1) - (y2), (x3) - (x4), (y3) - (y4))})


/* MovePlayer(dx,dy): Moves the player by (dx,dy) in the map, and
 * also updates their anglesin/anglecos/sector properties properly.
 */
static void MovePlayer(t_env *env, float dx, float dy)
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
		if (sect->neighbor[s] >= 0 && IntersectBox(px, py, px + dx, py + dy, vert[s].x, vert[s].y, vert[s + 1].x, vert[s + 1].y) && PointSide(px + dx, py + dy, vert[s].x, vert[s].y, vert[s + 1].x, vert[s + 1].y) < 0)
		{
			env->cam.sector = sect->neighbor[s];
			break;
		}
	env->cam.pos.x += dx;
	env->cam.pos.y += dy;
	env->cam.sin = sinf(env->cam.angle);
	env->cam.cos = cosf(env->cam.angle);
}

void	hooks(t_env *env, t_sdl *sdl)
{
	while (1)
	{
		while (SDL_PollEvent(&sdl->event))
		{
			if (sdl->event.type == SDL_QUIT)
				clean(env, NOTHING);
			if (env->sdl.event.type == SDL_KEYDOWN)
			{
			//	printf("%d\n", sdl->event.key.keysym.scancode);
				env->input[sdl->event.key.keysym.scancode] = 1;
			}
			if (env->sdl.event.type == SDL_KEYUP)
				env->input[sdl->event.key.keysym.scancode] = 0;
			if (sdl->event.type == SDL_MOUSEBUTTONDOWN)
				handle_mouse(env, sdl);
			if (sdl->event.type == SDL_MOUSEMOTION)
				handle_motion(env, sdl);
			if (env->sdl.event.window.event == SDL_WINDOWEVENT_CLOSE)
				clean(env, NOTHING);
		}
		handle_keyboard(env);
		if (SDL_UpdateWindowSurface(sdl->win))
			clean(env, E_SDL_UPDATE);
		if (env->win == GAME)
		{
			float eyeheight = env->cam.sneak ? DuckHeight : EyeHeight;
			// Vertical collisions
			env->cam.ground = !env->cam.fall;
			if (env->cam.fall) //gravity
			{
				env->cam.v.z -= 0.05f;
				float nextz = env->cam.pos.z + env->cam.v.z;
				//falling
				if (env->cam.v.z < 0 && nextz < env->sector[env->cam.sector].floor + eyeheight)
				{
					env->cam.pos.z = env->sector[env->cam.sector].floor + eyeheight;
					env->cam.v.z = 0;
					env->cam.fall = 0;
					env->cam.ground = 1;
				}
				// Jump or climbing
				else if (env->cam.v.z > 0 && nextz > env->sector[env->cam.sector].ceil)
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
			// Horizontal collisions
			if (env->cam.move)
			{
				float px = env->cam.pos.x;
				float py = env->cam.pos.y;
				float dx = env->cam.v.x;
				float dy = env->cam.v.y;
				const t_sector* const sect = &env->sector[env->cam.sector];
				const t_vec2d* const vert = sect->vertex;
				/* Check if the player is about to cross one of the sector's edges */
				for(unsigned s = 0; s < sect->points; ++s)
					if (IntersectBox(px , py, px + dx, py + dy, vert[s].x, vert[s].y, vert[s + 1].x, vert[s + 1].y) && PointSide(px + dx, py + dy, vert[s].x, vert[s].y, vert[s + 1].x, vert[s + 1].y) < 0)
					{
						/* Check where the hole is. */
						float hole_low = sect->neighbor[s] < 0 ?  9e9 : max(sect->floor, env->sector[sect->neighbor[s]].floor);
						float hole_high = sect->neighbor[s] < 0 ? -9e9 : min(sect->ceil, env->sector[sect->neighbor[s]].ceil);
						/* Check whether we're bumping into a wall. */
						if (hole_high < env->cam.pos.z + HeadMargin || hole_low > env->cam.pos.z - eyeheight + KneeHeight)
						{
							/* Bumps into a wall! Slide along the wall. */
							/* This formula is from Wikipedia article "vector projection". */
							float xd = vert[s + 1].x - vert[s].x;
							float yd = vert[s + 1].y - vert[s].y;
							dx = xd * (dx * xd + yd * dy) / (xd * xd + yd * yd);
							dy = yd * (dx * xd + yd * dy) / (xd * xd + yd * yd);
							env->cam.move = 0;
						}
					}
				MovePlayer(env, dx, dy);
				env->cam.fall = 1;
			}
			game(env);
		}
	}
}
