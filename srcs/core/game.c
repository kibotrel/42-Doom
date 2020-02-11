/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/11 10:33:08 by reda-con         ###   ########.fr       */
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
