/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/16 21:13:49 by demonwaves       ###   ########.fr       */
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
	env->sector[0].floor = 2;
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
	t_game	var;

	if (!env->setup)
	{
		SDL_ShowCursor(SDL_DISABLE);
		SDL_SetWindowTitle(env->sdl.win, TITLE_GAME);
		temporary_setup(env); // Won't last since parsing should replace it
	}
	game_setup(env, &var);
	graphics(env, &var);
}
