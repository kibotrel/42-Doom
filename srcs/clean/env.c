/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:29:45 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/20 12:14:19 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "clean.h"

static void	env_clean(t_env *env)
{
	uint32_t	i;

	i = 0;
	while (i < NB_ASSETS)
		if (env->sdl.bmp[i++].pixels)
			free(env->sdl.bmp[i - 1].pixels);
	i = 0;
	if (env->sector)
	{
		while (i < env->zones)
		{
			if (env->sector[i].vertex)
				free(env->sector[i].vertex);
			if (env->sector[i].neighbor)
				free(env->sector[i].neighbor);
			if (env->sector[i].num_link > 0)
				free(env->sector[i].link);
			if (env->sector[i].doors_neighbor)
				free(env->sector[i].doors_neighbor);
			i++;
		}
		free(env->sector);
	}
}

void		clean(t_env *env, uint8_t error)
{
	ttf_clean(&env->sdl);
	sdl_clean(&env->sdl);
	env_clean(env);
	error ? ft_print_error(env->error[error], error) : exit(0);
}
