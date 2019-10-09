/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:53:54 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/09 02:24:54 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "doom.h"

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
		selector(&env);
		hooks(&env, &env.sdl);
	}
	else
		usage();
	return (0);
}
