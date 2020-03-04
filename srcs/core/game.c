/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/04 19:27:48 by kibotrel         ###   ########.fr       */
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

static void	multithreaded_engine(t_env *env)
{
	int	i;

	i = -1;
	env->data.sky = 0;
	while (++i < NB_THREADS)
		if (pthread_create(&env->sdl.thread[i], NULL, (void*)graphics, env))
			clean(env, E_SDL_THREAD);
	i = -1;
	while (++i < NB_THREADS)
		pthread_join(env->sdl.thread[i], NULL);
	if (env->crash)
		clean(env, E_FLOAT);
	if (env->data.sky)
		draw_skybox(env);
}

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
		pthread_create(&env->sound, NULL, (void*)audio, env);
	}
	sector_triger(env);
	multithreaded_engine(env);
	hud(env);
}
