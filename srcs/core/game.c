/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/11 09:39:30 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "env.h"
#include "game.h"
#include "clean.h"
#include "libft.h"
#include "setup.h"
#include "utils.h"

static void	temporary_setup(t_env *env)
{
	unsigned int	i;

	i = 0;
	env->setup = 1;
//	env->cam.pos = v3d(4, 4, 0);
//	env->ca.angle = 0;
//	env->cam.sector = 0;
/*	if (!(env->sector = (t_sector*)malloc(sizeof(t_sector) * env->zones)))
		clean(env, E_MALLOC);
	if (!(env->sector[0].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 6)))
		clean(env, E_MALLOC);
	if (!(env->sector[0].neighbor = (int32_t*)malloc(sizeof(int32_t) * 6)))
		clean(env, E_MALLOC);
	if (!(env->sector[1].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[1].neighbor = (int32_t*)malloc(sizeof(int32_t) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[2].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[2].neighbor = (int32_t*)malloc(sizeof(int32_t) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[3].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[3].neighbor = (int32_t*)malloc(sizeof(int32_t) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[4].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[4].neighbor = (int32_t*)malloc(sizeof(int32_t) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[5].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 3)))
		clean(env, E_MALLOC);
	if (!(env->sector[5].neighbor = (int32_t*)malloc(sizeof(int32_t) * 3)))
		clean(env, E_MALLOC);
	if (!(env->sector[6].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 3)))
		clean(env, E_MALLOC);
	if (!(env->sector[6].neighbor = (int32_t*)malloc(sizeof(int32_t) * 3)))
		clean(env, E_MALLOC);
	if (!(env->sector[7].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 3)))
		clean(env, E_MALLOC);
	if (!(env->sector[7].neighbor = (int32_t*)malloc(sizeof(int32_t) * 3)))
		clean(env, E_MALLOC);
	if (!(env->sector[8].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 3)))
		clean(env, E_MALLOC);
	if (!(env->sector[8].neighbor = (int32_t*)malloc(sizeof(int32_t) * 3)))
		clean(env, E_MALLOC);
	if (!(env->sector[9].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[9].neighbor = (int32_t*)malloc(sizeof(int32_t) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[10].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 8)))
		clean(env, E_MALLOC);
	if (!(env->sector[10].neighbor = (int32_t*)malloc(sizeof(int32_t) * 8)))
		clean(env, E_MALLOC);
	if (!(env->sector[11].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[11].neighbor = (int32_t*)malloc(sizeof(int32_t) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[12].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[12].neighbor = (int32_t*)malloc(sizeof(int32_t) * 4)))
		clean(env, E_MALLOC);
	env->sector[0].ceil = 64;
	env->sector[0].floor = 16;
	env->sector[0].points = 6;
	env->sector[0].vertex[0] = v2d(0, 0);
	env->sector[0].vertex[1] = v2d(12, 0);
	env->sector[0].vertex[2] = v2d(12, 5);
	env->sector[0].vertex[3] = v2d(12, 10);
	env->sector[0].vertex[4] = v2d(12, 15);
	env->sector[0].vertex[5] = v2d(0, 15);
	env->sector[1].ceil = 36;
	env->sector[1].floor = 14;
	env->sector[1].points = 4;
	env->sector[1].vertex[0] = v2d(12, 5);
	env->sector[1].vertex[1] = v2d(18, 5);
	env->sector[1].vertex[2] = v2d(18, 10);
	env->sector[1].vertex[3] = v2d(12, 10);
	env->sector[2].ceil = 36;
	env->sector[2].floor = 16;
	env->sector[2].points = 4;
	env->sector[2].vertex[0] = v2d(12, 0);
	env->sector[2].vertex[1] = v2d(18, 0);
	env->sector[2].vertex[2] = v2d(18, 5);
	env->sector[2].vertex[3] = v2d(12, 5);
	env->sector[3].ceil = 36;
	env->sector[3].floor = 16;
	env->sector[3].points = 4;
	env->sector[3].vertex[0] = v2d(12, 10);
	env->sector[3].vertex[1] = v2d(18, 10);
	env->sector[3].vertex[2] = v2d(18, 15);
	env->sector[3].vertex[3] = v2d(12, 15);
	env->sector[4].ceil = 32;
	env->sector[4].floor = 12;
	env->sector[4].points = 4;
	env->sector[4].vertex[0] = v2d(18, 5);
	env->sector[4].vertex[1] = v2d(21, 5);
	env->sector[4].vertex[2] = v2d(21, 10);
	env->sector[4].vertex[3] = v2d(18, 10);
	env->sector[5].ceil = 30;
	env->sector[5].floor = 10;
	env->sector[5].points = 3;
	env->sector[5].vertex[0] = v2d(21, 5);
	env->sector[5].vertex[1] = v2d(24, 5);
	env->sector[5].vertex[2] = v2d(21, 10);
	env->sector[6].ceil = 28;
	env->sector[6].floor = 8;
	env->sector[6].points = 3;
	env->sector[6].vertex[0] = v2d(24, 5);
	env->sector[6].vertex[1] = v2d(27, 5);
	env->sector[6].vertex[2] = v2d(21, 10);
	env->sector[7].ceil = 26;
	env->sector[7].floor = 6;
	env->sector[7].points = 3;
	env->sector[7].vertex[0] = v2d(27, 5);
	env->sector[7].vertex[1] = v2d(30, 7.5);
	env->sector[7].vertex[2] = v2d(21, 10);
	env->sector[8].ceil = 24;
	env->sector[8].floor = 4;
	env->sector[8].points = 3;
	env->sector[8].vertex[0] = v2d(30, 7.5);
	env->sector[8].vertex[1] = v2d(30, 10);
	env->sector[8].vertex[2] = v2d(21, 10);
	env->sector[9].ceil = 22;
	env->sector[9].floor = 2;
	env->sector[9].points = 4;
	env->sector[9].vertex[0] = v2d(21, 10);
	env->sector[9].vertex[1] = v2d(30, 10);
	env->sector[9].vertex[2] = v2d(30, 12.5);
	env->sector[9].vertex[3] = v2d(21, 12.5);
	env->sector[10].ceil = 20;
	env->sector[10].floor = 0;
	env->sector[10].points = 8;
	env->sector[10].vertex[0] = v2d(21, 12.5);
	env->sector[10].vertex[1] = v2d(30, 12.5);
	env->sector[10].vertex[2] = v2d(30, 22.5);
	env->sector[10].vertex[3] = v2d(30, 25);
	env->sector[10].vertex[4] = v2d(30, 75);
	env->sector[10].vertex[5] = v2d(21, 75);
	env->sector[10].vertex[6] = v2d(21, 25);
	env->sector[10].vertex[7] = v2d(21, 22.5);
	env->sector[11].ceil = 20;
	env->sector[11].floor = 4;
	env->sector[11].points = 4;
	env->sector[11].vertex[0] = v2d(30, 22.5);
	env->sector[11].vertex[1] = v2d(40, 22.5);
	env->sector[11].vertex[2] = v2d(45, 25);
	env->sector[11].vertex[3] = v2d(30, 25);
	env->sector[12].ceil = 6;
	env->sector[12].floor = 0;
	env->sector[12].points = 4;
	env->sector[12].vertex[0] = v2d(10, 22.5);
	env->sector[12].vertex[1] = v2d(21, 22.5);
	env->sector[12].vertex[2] = v2d(21, 25);
	env->sector[12].vertex[3] = v2d(10, 25);
	while (i < 8)
	{
		if (i < env->sector[0].points)
			env->sector[0].neighbor[i] = -1;
		if (i < env->sector[1].points)
			env->sector[1].neighbor[i] = -1;
		if (i < env->sector[2].points)
			env->sector[2].neighbor[i] = -1;
		if (i < env->sector[3].points)
			env->sector[3].neighbor[i] = -1;
		if (i < env->sector[4].points)
			env->sector[4].neighbor[i] = -1;
		if (i < env->sector[5].points)
			env->sector[5].neighbor[i] = -1;
		if (i < env->sector[6].points)
			env->sector[6].neighbor[i] = -1;
		if (i < env->sector[7].points)
			env->sector[7].neighbor[i] = -1;
		if (i < env->sector[8].points)
			env->sector[8].neighbor[i] = -1;
		if (i < env->sector[9].points)
			env->sector[9].neighbor[i] = -1;
		if (i < env->sector[10].points)
			env->sector[10].neighbor[i] = -1;
		if (i < env->sector[11].points)
			env->sector[11].neighbor[i] = -1;
		if (i < env->sector[12].points)
			env->sector[12].neighbor[i] = -1;
		i++;
	}
	env->sector[0].neighbor[1] = 2;
	env->sector[0].neighbor[2] = 1;
	env->sector[0].neighbor[3] = 3;
	env->sector[1].neighbor[0] = 2;
	env->sector[1].neighbor[1] = 4;
	env->sector[1].neighbor[2] = 3;
	env->sector[1].neighbor[3] = 0;
	env->sector[2].neighbor[2] = 1;
	env->sector[2].neighbor[3] = 0;
	env->sector[3].neighbor[0] = 1;
	env->sector[3].neighbor[3] = 0;
	env->sector[4].neighbor[1] = 5;
	env->sector[4].neighbor[3] = 1;
	env->sector[5].neighbor[1] = 6;
	env->sector[5].neighbor[2] = 4;
	env->sector[6].neighbor[1] = 7;
	env->sector[6].neighbor[2] = 5;
	env->sector[7].neighbor[1] = 8;
	env->sector[7].neighbor[2] = 6;
	env->sector[8].neighbor[1] = 9;
	env->sector[8].neighbor[2] = 7;
	env->sector[9].neighbor[0] = 8;
	env->sector[9].neighbor[2] = 10;
	env->sector[10].neighbor[0] = 9;
	env->sector[10].neighbor[2] = 11;
	env->sector[10].neighbor[6] = 12;
	env->sector[11].neighbor[3] = 10;
	env->sector[12].neighbor[1] = 10;
	*/
}

#include "parse.h"

void		game(t_env *env)
{
	if (!env->setup)
	{
		SDL_ShowCursor(SDL_DISABLE);
		SDL_SetWindowTitle(env->sdl.win, TITLE_GAME);
		temporary_setup(env);
	env->cam.fov = v2d(0.75 * env->h, 0.2 * env->h);
	env->cam.cos = cos(env->cam.angle);
	env->cam.sin = sin(env->cam.angle);
	env->cam.pos.z = env->sector[env->cam.sector].floor + CAM_H;
	}
	sector_triger(env);
	graphics(env);
	hud(env);
}
