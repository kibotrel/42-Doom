/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:53:54 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/23 17:26:22 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "game.h"
#include "libft.h"
#include "clean.h"
#include "setup.h"
#include "utils.h"

//
//	If ac == 2, a map is sent to the program
//	replace ft_isvalidname by a parser call + check the name inside
//	function prototype should be modified to get env in this scope
//

static int	prechecks(int ac, char **av)
{
	return ((ac == 2 ? ft_isvalidname(av[1], ".data") : 1));
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac <= 2)
	{
		env_setup(&env);
		if (prechecks(ac, av))
		// {
		// 	if (ac == 2)
		// 		main_parse(av[1], &env);
			graphic_setup(&env, &env.sdl);
		// }
		else
			clean(&env, E_FILENAME);
		while (1)
		{
			selector(&env);
			if (env.win == GAME)
				physics(&env);
			global_hooks(&env, &env.sdl);
			if (SDL_UpdateWindowSurface(env.sdl.win))
				clean(&env, E_SDL_UPDATE);
			SDL_Delay(16);
		}
	}
	else
		usage();
	return (0);
}
