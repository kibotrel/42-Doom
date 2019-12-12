/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/12 04:19:54 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "env.h"
#include "game.h"
#include "clean.h"
#include "libft.h"
#include "utils.h"

static void	temporary_setup(t_env *env)
{
	env->setup = 1;
	env->zones = 3; //PARSER
	ft_bzero(&env->cam, sizeof(t_cam));
	env->cam.pos = v3d(2, 6, 0); //PARSER
	env->cam.fov = v2d(0.75 * env->h, 0.2 * env->h);
	env->cam.angle = 0;//PARSER
	env->cam.cos = cos(env->cam.angle);
	env->cam.sin = sin(env->cam.angle);
	env->cam.sector = 0; //PARSER
	env->cam.fall = 1;
	if (!(env->sector = (t_sector*)malloc(sizeof(t_sector) * env->zones)))
		clean(env, E_MALLOC);
	if (!(env->sector[0].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 6)))
		clean(env, E_MALLOC);
	if (!(env->sector[0].neighbor = (int32_t*)malloc(sizeof(int32_t) * 6)))
		clean(env, E_MALLOC);
	if (!(env->sector[1].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 9)))
		clean(env, E_MALLOC);
	if (!(env->sector[1].neighbor = (int32_t*)malloc(sizeof(int32_t) * 9)))
		clean(env, E_MALLOC);
	if (!(env->sector[2].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 5)))
		clean(env, E_MALLOC);
	if (!(env->sector[2].neighbor = (int32_t*)malloc(sizeof(int32_t) * 5)))
		clean(env, E_MALLOC);

	env->sector[0].ceil = 20;
	env->sector[0].floor = 5;
	env->sector[0].points = 6;
	env->sector[0].vertex[0] = v2d(0,0); //PARSER
	env->sector[0].vertex[1] = v2d(10,0); //PARSER
	env->sector[0].vertex[2] = v2d(10,3); //PARSER
	env->sector[0].vertex[3] = v2d(10,7); //PARSER
	env->sector[0].vertex[4] = v2d(10,10); //PARSER
	env->sector[0].vertex[5] = v2d(0,10); //PARSER

	env->sector[1].ceil = 16;
	env->sector[1].floor = -2;
	env->sector[1].points = 9;
	env->sector[1].vertex[0] = v2d(10,0); //PARSER
	env->sector[1].vertex[1] = v2d(15,0); //PARSER
	env->sector[1].vertex[2] = v2d(15,2.5); //PARSER
	env->sector[1].vertex[3] = v2d(17.5,5); //PARSER
	env->sector[1].vertex[4] = v2d(20,5); // PARSER
	env->sector[1].vertex[5] = v2d(20,10); //PARSER
	env->sector[1].vertex[6] = v2d(10,10); // PARSER
	env->sector[1].vertex[7] = v2d(10,7); //PARSER
	env->sector[1].vertex[8] = v2d(10,3); //PARSER

	env->sector[2].ceil = 26;
	env->sector[2].floor = 0;
	env->sector[2].points = 5;
	env->sector[2].vertex[0] = v2d(15,0); //PARSER
	env->sector[2].vertex[1] = v2d(20,0); //PARSER
	env->sector[2].vertex[2] = v2d(20,5); //PARSER
	env->sector[2].vertex[3] = v2d(17.5,5); //PARSER
	env->sector[2].vertex[4] = v2d(15,2.5); //PARSER

	for (unsigned i = 0; i < 9; i++)
	{
		if (i < env->sector[0].points)
			env->sector[0].neighbor[i] = -1;
		if (i < env->sector[1].points)
			env->sector[1].neighbor[i] = -1;
		if (i < env->sector[2].points)
			env->sector[2].neighbor[i] = -1;
	}
	env->sector[0].neighbor[2] = 1;
	env->sector[1].neighbor[1] = 2;
	env->sector[1].neighbor[2] = 2;
	env->sector[1].neighbor[3] = 2;
	env->sector[1].neighbor[7] = 0;
	env->sector[2].neighbor[2] = 1;
	env->sector[2].neighbor[3] = 1;
	env->sector[2].neighbor[4] = 1;
	env->cam.pos.z = env->sector[env->cam.sector].floor + CAM_H;
}

void		game(t_env *env)
{
	if (!env->setup)
	{
		SDL_SetWindowTitle(env->sdl.win, TITLE_GAME);
		temporary_setup(env);
	}
	t_item queue[32], *head=queue, *tail=queue;
	int ytop[1280]={0}, ybottom[1280], renderedsectors[env->zones], i = 0;

	for(int x = 0; x < env->w; ++x)
		ybottom[x] = env->h - 1;
	for(unsigned n = 0; n < env->zones; ++n)
		renderedsectors[n] = 0;
	*head = (t_item){env->cam.sector, 0, env->w - 1};
	if (++head == queue + 32)
		head = queue;
    while(i == 0 || head != tail)
	{
		i = 1;
		const t_item now = *tail;
		if (++tail == queue + 32)
			tail = queue;
		if (renderedsectors[now.sector] > 31)
			continue;
		++renderedsectors[now.sector];
		const t_sector* const sect = &env->sector[now.sector];
		for(unsigned s = 0; s < sect->points; ++s)
		{
			float vx1 = sect->vertex[s].x - env->cam.pos.x;
			float vy1 = sect->vertex[s].y - env->cam.pos.y;
			float vx2 = sect->vertex[(s + 1) % sect->points].x - env->cam.pos.x;
			float vy2 = sect->vertex[(s + 1) % sect->points].y - env->cam.pos.y;
			float tx1 = vx1 * env->cam.sin - vy1 * env->cam.cos;
			float tz1 = vx1 * env->cam.cos + vy1 * env->cam.sin;
			float tx2 = vx2 * env->cam.sin - vy2 * env->cam.cos;
			float tz2 = vx2 * env->cam.cos + vy2 * env->cam.sin;
			if (tz1 <= 0 && tz2 <= 0)
				continue;
			if (tz1 <= 0 || tz2 <= 0)
			{
				float nearz = 1e-4f;
				float farz = 5;
				float nearside = 1e-5f;
				float farside = 20.f;
				t_vec2d i1 = Intersect(tx1,tz1,tx2,tz2, -nearside,nearz, -farside,farz);
	 			t_vec2d i2 = Intersect(tx1,tz1,tx2,tz2,  nearside,nearz,  farside,farz);
				if (tz1 < nearz)
				{
					if (i1.y > 0)
					{
						tx1 = i1.x;
						tz1 = i1.y;
					}
					else
					{
						tx1 = i2.x;
						tz1 = i2.y;
					}
				}
 				if (tz2 < nearz)
				{
					if (i1.y > 0)
					{
						tx2 = i1.x;
						tz2 = i1.y;
					}
					else
					{
						tx2 = i2.x;
						tz2 = i2.y;
					}
				}
			}
			float xscale1 = env->cam.fov.x / tz1;
			float yscale1 = env->cam.fov.y / tz1;
			float xscale2 = env->cam.fov.x / tz2;
			float yscale2 = env->cam.fov.y / tz2;
			int x1 = env->w / 2 - (int)(tx1 * xscale1);
			int x2 = env->w / 2 - (int)(tx2 * xscale2);
			if (x1 >= x2 || x2 < now.sx1 || x1 > now.sx2)
				continue;
			float yceil = sect->ceil - env->cam.pos.z;
			float yfloor = sect->floor - env->cam.pos.z;
			int neighbor = sect->neighbor[s];
			float nyceil = 0;
			float nyfloor = 0;
			if (neighbor >= 0)
			{
				nyceil  = env->sector[neighbor].ceil  - env->cam.pos.z;
				nyfloor = env->sector[neighbor].floor - env->cam.pos.z;
			}
			#define Yaw(y , z) (y + z * env->cam.gap)
			int y1a = env->h / 2 - (int)(Yaw(yceil, tz1) * yscale1);
			int y1b = env->h / 2 - (int)(Yaw(yfloor, tz1) * yscale1);
			int y2a = env->h / 2 - (int)(Yaw(yceil, tz2) * yscale2);
			int y2b = env->h / 2 - (int)(Yaw(yfloor, tz2) * yscale2);
			int ny1a = env->h / 2 - (int)(Yaw(nyceil, tz1) * yscale1);
			int ny1b = env->h / 2 - (int)(Yaw(nyfloor, tz1) * yscale1);
			int ny2a = env->h / 2 - (int)(Yaw(nyceil, tz2) * yscale2);
			int ny2b = env->h / 2 - (int)(Yaw(nyfloor, tz2) * yscale2);
			int beginx = max(x1, now.sx1);
			int endx = min(x2, now.sx2);
			for(int x = beginx; x <= endx; ++x)
			{
				int z = ((x - x1) * (tz2 - tz1) / (x2 - x1) + tz1) * 8;
				int ya = (x - x1) * (y2a - y1a) / (x2 - x1) + y1a;
				int cya = clamp(ya, ytop[x],ybottom[x]);
				int yb = (x - x1) * (y2b - y1b) / (x2 - x1) + y1b;
				int cyb = clamp(yb, ytop[x], ybottom[x]);
				draw_slice(env, x, ytop[x], cya - 1, 0x111111 ,0x222222,0x111111);
				draw_slice(env, x, cyb + 1, ybottom[x], 0x0000FF,0x0000AA,0x0000FF);
				if (neighbor >= 0)
				{
					int nya = (x - x1) * (ny2a - ny1a) / (x2 - x1) + ny1a;
					int cnya = clamp(nya, ytop[x],ybottom[x]);
					int nyb = (x - x1) * (ny2b - ny1b) / (x2 - x1) + ny1b;
					int cnyb = clamp(nyb, ytop[x], ybottom[x]);
					unsigned r1 = 0x010101 * (255 - z), r2 = 0x040007 * (31 - z / 8);
					draw_slice(env, x, cya, cnya - 1, 0, x == x1 || x == x2 ? 0 : r1, 0);
					ytop[x] = clamp(max(cya, cnya), ytop[x], env->h - 1);
					draw_slice(env, x, cnyb + 1, cyb, 0, x == x1 || x == x2 ? 0 : r2, 0);
					ybottom[x] = clamp(min(cyb, cnyb), 0, ybottom[x]);
				}
				else
				{
					unsigned r = 0x010101 * (255-z);
					draw_slice(env, x, cya, cyb, 0, x == x1 || x == x2 ? 0 : r, 0);
				}
			}
			if ( neighbor >= 0 && endx >= beginx && (head - tail + 33) % 32)
			{
				*head = (t_item){neighbor, beginx, endx};
				if (++head == queue + 32)
					head = queue;
			}
		}
		++renderedsectors[now.sector];
	}
}
