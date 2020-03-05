/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:29:45 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/05 08:43:38 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "clean.h"
#include "editor.h"

void		free_map(t_env *env)
{
	uint32_t	i;

	i = 0;
	if (env->sector)
	{
		while (i < env->zones)
		{
			if (env->sector[i].vertex)
				free(env->sector[i].vertex);
			if (env->sector[i].neighbor)
				free(env->sector[i].neighbor);
			if (env->sector[i].door_neighbor)
				free(env->sector[i].door_neighbor);
			i++;
		}
		free(env->sector);
	}
}

static void	env_clean(t_env *env)
{
	uint32_t		i;

	i = 0;
	while (i < NB_ASSETS)
		if (env->sdl.bmp[i++].pixels)
			free(env->sdl.bmp[i - 1].pixels);
	if (env->win == GAME)
		free_map(env);
}

void		clean(t_env *env, uint8_t error)
{
	env->data.closed = 1;
	pthread_join(env->sound, NULL);
	SDL_Delay(500);
	clean_editor(&env->editor);
	ttf_clean(&env->sdl);
	sdl_clean(&env->sdl);
	audio_clean(&env->audio);
	env_clean(env);
	error ? ft_print_error(env->error[error], error) : exit(0);
}
