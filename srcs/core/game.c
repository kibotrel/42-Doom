/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/21 16:38:55 by demonwaves       ###   ########.fr       */
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
#include "parse.h"

void		game(t_env *env, int ac, char **av)
{
	if (!env->setup)
	{
		main_parse(av, env, ac);
		env->setup = 1;
		SDL_ShowCursor(SDL_DISABLE);
		SDL_SetWindowTitle(env->sdl.win, TITLE_GAME);
		env->cam.cos = cos(env->cam.angle);
		env->cam.sin = sin(env->cam.angle);
		env->cam.pos.z = env->sector[env->cam.sector].floor + CAM_H;
	}
	sector_triger(env);
	graphics(env);
	if (env->data.sky)
		draw_skybox(env);
	hud(env);
}
