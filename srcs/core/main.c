/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:53:54 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/12 10:41:51 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"
#include "game.h"
#include "libft.h"
#include "clean.h"
#include "setup.h"
#include "utils.h"

static int	prechecks(int ac, char **av)
{
	return ((ac == 2 ? ft_isvalidname(av[1], ".data") : 1));
}

/*
**	Don't forget to add a map parser there if ac == 2
*/

int			main(int ac, char **av)
{
	t_env	env;

	if (ac <= 2)
	{
		env_setup(&env);
		if (prechecks(ac, av))
			graphic_setup(&env, &env.sdl);
		else
			clean(&env, E_FILENAME);
		while (1)
		{
			selector(&env);
			if (SDL_UpdateWindowSurface(env.sdl.win))
				clean(&env, E_SDL_UPDATE);
			if (env.win != GAME)
				global_hooks(&env, &env.sdl);
			else
				game_hooks(&env);
		}
	}
	else
		usage();
	return (0);
}
