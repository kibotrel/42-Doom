/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:53:54 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 10:04:13 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "setup.h"
#include "utils.h"
#include "parse.h"

//
//__attribute__((destructor)) void no_end(void);
//void no_end(){while(1);}
//

static void	update_screen(t_env *env)
{
	if (SDL_UpdateWindowSurface(env->sdl.win))
		clean(env, E_SDL_UPDATE);
	fps_counter(env);
}

static int	process_next_frame(t_env *env)
{
	int		next;
	int		process;

	if (env->setting.fps_max < 0)
		return (1);
	next = 1000 / env->setting.fps_max;
	process = 0;
	env->tick.lock.new = SDL_GetTicks();
	if (env->tick.lock.new >= env->tick.lock.old + next)
	{
		process = 1;
		env->tick.lock.old = env->tick.lock.new;
	}
	return (process);
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac <= 2)
	{
		env_setup(&env);
		graphic_setup(&env, &env.sdl);
		while (1)
		{
			if (process_next_frame(&env))
			{
				selector(&env, ac, av);
				if (env.win == GAME)
					physics(&env);
				global_hooks(&env, &env.sdl);
				update_screen(&env);
			}
		}
	}
	else
		usage();
	return (0);
}
