/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/26 02:36:13 by demonwaves       ###   ########.fr       */
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
	env->setup = 0;
	env->zones = 1; //PARSER
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
	if (!(env->sector[0].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 5)))
		clean(env, E_MALLOC);
	if (!(env->sector[0].neighbor = (int32_t*)malloc(sizeof(int32_t) * 4)))
		clean(env, E_MALLOC);
	env->sector[0].ceil = 20;
	env->sector[0].floor = 0;
	env->sector[0].vertex[0] = v2d(0,0); //PARSER
	env->sector[0].vertex[1] = v2d(10,0); //PARSER
	env->sector[0].vertex[2] = v2d(10,10); //PARSER
	env->sector[0].vertex[3] = v2d(0,10); //PARSER
	env->sector[0].points = 4;
	for (unsigned i = 0; i < env->sector[0].points; i++)
		env->sector[0].neighbor[i] = -1; //PARSER
	env->cam.pos.z = env->sector[env->cam.sector].floor + CAM_H;
}

void		game(t_env *env)
{
	if (!env->setup)
	{
		SDL_SetWindowTitle(env->sdl.win, TITLE_GAME);
		temporary_setup(env);
	}
	engine(env);
}
