/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/03 02:27:48 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include "env.h"
#include "game.h"
#include "clean.h"
#include "libft.h"
#include "setup.h"
#include "utils.h"
#include "parse.h"

static void		audio(t_env *env)
{
	int			i;
	int			tmp;
	int			read[2];

	while (1)
	{
		read[1] = 0;
		read[0] = sf_read_short(env->audio.stream[1], env->audio.buffer[1], STREAM_SIZE);
		if (!read[0])
			sf_seek(env->audio.stream[1], 0, SEEK_SET);
		if (env->audio.fire)
		{
			read[1] = sf_read_short(env->audio.stream[0], env->audio.buffer[0], STREAM_SIZE);
			if (!read[1])
			{
				env->audio.fire = 0;
				sf_seek(env->audio.stream[0], 0, SEEK_SET);
			}
		}
		if (read[1])
		{
			i = -1;
			while (++i < STREAM_SIZE)
			{
				tmp = env->audio.buffer[1][i] + env->audio.buffer[0][i];
				if (tmp > SHRT_MAX)
					tmp = SHRT_MAX;
				else if (tmp < SHRT_MIN)
					tmp = SHRT_MIN;
				env->audio.buffer[1][i] = (short)tmp;
			}
		}
		if (read[0] && env->win == GAME && !env->data.closed)
			ao_play(env->audio.device, (char *)env->audio.buffer[1], (uint_32) (read[0] * sizeof(short)));
		else
			break;
	}
	pthread_exit(NULL);
}

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
