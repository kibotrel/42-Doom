/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/05 09:57:50 by reda-con         ###   ########.fr       */
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
#include "editor.h"

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

void		tuto(t_env *env)
{
	int		check[5];
	int		i;

	i = -1;
	while (++i < 5)
		check[i] = 0;
	if (env->test.all_move || (env->test.move[0] && env->test.move[1] && env->test.move[2] && env->test.move[3]))
	{
		env->test.all_move = 1;
		if (env->test.door)
		{
			if (env->test.jump)
			{
				if (env->test.crouch)
				{
					if (env->cam.sector == 3)
						display_text(WHITE, init_vertex(env->w / 2 - 400, env->h / 2 - 50), "You are taking dommage, sprint with [CONTROL]", env);
					else if (env->test.jetpack)
					{
						if (!env->test.elevator)
							display_text(WHITE, init_vertex(env->w / 2 - 400, env->h / 2 - 50), "Now go to elevator and use [Q] or [E] to go down or up", env);
						if (env->sector[env->cam.sector].type == 5)
							env->test.elevator = 1;
					}
					else if (env->sector[env->cam.sector].type == 1)
					{
						display_text(WHITE, init_vertex(env->w / 2 - 400, env->h / 2 - 50), "You will need money to activate the Jetpack", env);
						display_text(WHITE, init_vertex(env->w / 2 - 400, env->h / 2 - 100), "Go to the hard brown room to earn money", env);
						display_text(WHITE, init_vertex(env->w / 2 - 400, env->h / 2), "Then use it with [SPACE]", env);
					}
				}
				else
					display_text(WHITE, init_vertex(env->w / 2 - 400, env->h / 2 - 50), "To continue, use [SHIFT] to crouch", env);
			}
			else
			display_text(WHITE, init_vertex(env->w / 2 - 400, env->h / 2 - 50), "To go to the next room you have to jump with [SPACE]", env);
		}
		else
			display_text(WHITE, init_vertex(env->w / 2 - 400, env->h / 2 - 50), "Go to the green room and press [E] to open the door", env);
	}
	else
		display_text(WHITE, init_vertex(env->w / 2 - 200, env->h / 2 - 50), "Use [W] [Q] [S] [D] to move", env);
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
	multithreaded_engine(env);
	hud(env);
	sector_triger(env);
	if (env->tuto == 1)
		tuto(env);
}
