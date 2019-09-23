/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:53:54 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/23 18:57:47 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "doom.h"

static int	prechecks(int ac, char **av)
{
	if (ac == 2)
		return (ft_isvalidname(av[1], ".data"));
	else
		return (1);
}

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
