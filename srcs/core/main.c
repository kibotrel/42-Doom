/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:53:54 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/05 18:00:26 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "game.h"
#include "libft.h"
#include "clean.h"
#include "setup.h"
#include "utils.h"
#include "parse.h"

/*
 __attribute__((destructor)) void no_end(void);
 void no_end(){while(1);}
 */

static void	update_screen(t_env *env)
{
	if (SDL_UpdateWindowSurface(env->sdl.win))
		clean(env, E_SDL_UPDATE);
	fps_counter(env);
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
			selector(&env, ac, av);
			if (env.win == GAME)
				physics(&env);
			global_hooks(&env, &env.sdl);
			update_screen(&env);
		}
	}
	else
		usage();
	return (0);
}
