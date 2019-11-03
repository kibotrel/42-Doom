/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/03 19:55:43 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "env.h"
#include "core.h"
#include "game.h"
#include "libft.h"
#include "utils.h"


static t_pos	pos(uint32_t x, uint32_t y)
{
	t_pos		pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

static void		temporary_setup(t_env *env)
{
	ft_bzero(&env->cam, sizeof(t_cam));
	env->setup = 1;
	env->zones = 1; // FROM PARSING
	env->cam.angle = 0.4; // FROM PARSING
	env->cam.cos = cos(env->cam.angle);
	env->cam.sin = sin(env->cam.angle);
	env->cam.pos.x = 50.0; // FROM PARSING
	env->cam.pos.y = 50.0; // FROM PARSING
	env->cam.pos.z = 0 + CAM_STANDING; // FROM PARSING
	env->cam.sector = 0; // FROM PARSING
	env->cam.fov.x = HORIZONTAL_FOV * env->h;
	env->cam.fov.y = VERTICAL_FOV * env->h;
	env->sector = (t_sector*)malloc(sizeof(t_sector) * env->zones);
	env->sector[0].points = 4; //FROM PARSING
	env->sector[0].vertex = (t_pos*)malloc(sizeof(t_pos) * env->sector[0].points);
	env->sector[0].neighbor = (int32_t*)malloc(sizeof(int32_t) * env->sector[0].points);
	env->sector[0].vertex[0] = pos(0, 0); //FROM PARSING
	env->sector[0].vertex[1] = pos(100, 0); //FROM PARSING
	env->sector[0].vertex[2] = pos(100, 100); //FROM PARSING
	env->sector[0].vertex[3] = pos(0, 100); //FROM PARSING
	env->sector[0].neighbor[0] = -1; //FROM PARSING
	env->sector[0].neighbor[1] = -1; //FROM PARSING
	env->sector[0].neighbor[2] = -1; //FROM PARSING
	env->sector[0].neighbor[3] = -1; //FROM PARSING
	env->sector[0].ceil = 20; //FROM PARSING
	env->sector[0].floor = 0; //FROM PARSING
}

static void		local_setup(t_env *env, t_local *local)
{
	ft_bzero(local, sizeof(t_local));
	local->zone = env->cam.sector;
	local->x1 = env->w - 1;
	local->sector = &env->sector[local->zone];
}

static void draw_slice(t_env *env, int x, int y1, int y2, t_palette color)
{
	int		y;
	t_pos	p;

	p.x = x;
	y1 = bound(y1, 0, env->h - 1);
	y2 = bound(y2, 0, env->h - 1);
	p.y = y1;
	if (y2 == y1)
		draw_pixel(env, env->sdl.screen, p, color.wall);
	else if(y2 > y1)
	{
		draw_pixel(env, env->sdl.screen, p, color.ceil);
		y = y1;
		while (++y < y2)
		{
			p.y = y;
			draw_pixel(env, env->sdl.screen, p, color.wall);
		}
		p.y = y2;
		draw_pixel(env, env->sdl.screen, p, color.floor);
	}
}

static t_palette	palette(uint8_t n, int i, int x[2])
{
	t_palette	color;

	if (!n)
	{
		color.ceil = 0x111111;
		color.wall = 0x222222;
		color.floor = 0x111111;
	}
	else if (n == 1)
	{
		color.ceil = 0x0000FF;
		color.wall = 0x0000AA;
		color.floor = 0x0000FF;
	}
	else
	{
		color.ceil = 0x0;
		color.wall = (i == x[0] || i == x[1] ? 0 : 0xAAAAAA);
		color.floor = 0x0;
	}
	return (color);
}

void			game(t_env *env)
{
	int			j;
	int			k;
	int			x[2];
	int			y[2];
	int			cy[2];
	int			ya[2];
	int			yb[2];
	int			endx;
	int			beginx;
	int			top[env->w];
	int			bottom[env->w];
	double		yceil;
	double		yfloor;
	t_local		local;
	t_vec2d		v[2];
	t_vec2d		t[2];
	t_vec2d		s[2];
	t_vec2d		i[2];

	if (!env->setup)
	{
		SDL_SetWindowTitle(env->sdl.win, TITLE_GAME);
		temporary_setup(env);
	}
	j = 0;
	local_setup(env, &local);
	while (j < env->w)
	{
		top[j] = 0;
		bottom[j++] = env->h - 1;
	}
	j = 0;
	while(j < (int)local.sector->points)
	{
		v[0] = vector2d(local.sector->vertex[j].x - env->cam.pos.x, local.sector->vertex[j].y - env->cam.pos.y);
		v[1] = vector2d(local.sector->vertex[j + 1].x - env->cam.pos.x, local.sector->vertex[j + 1].y - env->cam.pos.y);
		t[0] = vector2d(v[0].x * env->cam.sin - v[0].y * env->cam.cos, v[0].x * env->cam.cos + v[0].y * env->cam.sin);
		t[1] = vector2d(v[1].x * env->cam.sin - v[1].y * env->cam.cos, v[1].x * env->cam.cos + v[1].y * env->cam.sin);
		if (t[0].y <= 0 && t[1].y <= 0)
		{
			j++;
			continue;
		}
		i[0] = intersect(t[0], t[1], vector2d(-1e-5, 1e-4), vector2d(-20, 5));
		i[1] = intersect(t[0], t[1], vector2d(1e-5, 1e-4), vector2d(20, 5));
		if (t[0].y < 1e-4)
		{
			if (i[0].y > 0)
				t[0] = i[0];
			else
				t[0] = i[1];
		}
		if (t[1].y < 1e-4)
		{
			if (i[0].y > 0)
			 	t[1] = i[0];
			else
				t[1] = i[1];
		}
		s[0] = vector2d(env->cam.fov.x / t[0].y, env->cam.fov.y / t[0].y);
		s[1] = vector2d(env->cam.fov.x / t[1].y, env->cam.fov.y / t[1].y);
		x[0] = env->w / 2 - floor(t[0].x * s[0].x);
		x[1] = env->w / 2 - floor(t[1].x * s[1].x);
		if (x[0] >= x[1] || x[1] < local.x0 || x[0] > local.x1)
		{
			j++;
			continue;
		}
		yceil = local.sector->ceil - env->cam.pos.z;
		yfloor = local.sector->floor - env->cam.pos.z;
		ya[0] = env->h / 2 - floor(yceil * s[0].y);
		yb[0] = env->h / 2 - floor(yfloor * s[0].y);
		ya[1] = env->h / 2 - floor(yceil * s[1].y);
		yb[1] = env->h / 2 - floor(yfloor * s[1].y);
		beginx = fmin(x[0], local.x0);
		endx = fmax(x[1], local.x1);
		k = beginx - 1;
		while (++k <= endx)
		{
			y[0] = (k - x[0]) * (ya[1] - ya[0]) / (x[1] - x[0]) + ya[0];
			y[1] = (k - x[0]) * (yb[1] - yb[0]) / (x[1] - x[0]) + yb[0];
			cy[0] = bound(y[0], top[k], bottom[k]);
			cy[1] = bound(y[1], top[k], bottom[k]);
			draw_slice(env, k, top[k], cy[0] - 1, palette(0, k, x));
			draw_slice(env, k, cy[1] + 1, bottom[k], palette(1, k, x));
			if (local.sector->neighbor[j] == -1)
				draw_slice(env, k, cy[0], cy[1], palette(2, k, x));
		}
		j++;
	}
}
