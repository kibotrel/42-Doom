/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:29:45 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 01:25:47 by kibotrel         ###   ########.fr       */
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
	if (env->zones)
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
	if (env->bmp_error >= 0)
	{
		while (i < (uint32_t)env->bmp_error)
			if (env->sdl.bmp[i++].pixels)
				free(env->sdl.bmp[i - 1].pixels);
	}
	else
	{
		while (i < NB_ASSETS)
			if (env->sdl.bmp[i++].pixels)
				free(env->sdl.bmp[i - 1].pixels);
	}
	if (env->win == GAME)
		free_map(env);
}

/*
**	#include <time.h>
**	struct timespec	time;
**	time = (struct timespec){0, 250000000};
**	pthread_join(env->sound, NULL);
**	nanosleep(&time, 0);
**	audio_clean(&env->audio);
*/

void		clean(t_env *env, uint8_t error)
{
	env->data.closed = 1;
	clean_editor(&env->editor);
	ttf_clean(&env->sdl);
	sdl_clean(&env->sdl);
	env_clean(env);
	error ? ft_print_error(env->error[error], error) : exit(0);
}
