/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:29:45 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/24 14:27:05 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "clean.h"

static void	hud_clean(t_env *env)
{
	printf("%p | %s\n", env->data.hud.fly, env->data.hud.fly);
	if (env->data.hud.fly)
		free(env->data.hud.fly);
	printf("%p | %s\n", env->data.hud.fps, env->data.hud.fps);
	if (env->data.hud.fps)
		free(env->data.hud.fps);
	printf("%p | %s\n", env->data.hud.pos, env->data.hud.pos);
	if (env->data.hud.pos)
		free(env->data.hud.pos);
	printf("%p | %s\n", env->data.hud.angle, env->data.hud.angle);
	if (env->data.hud.angle)
		free(env->data.hud.angle);
	printf("%p | %s\n", env->data.hud.height, env->data.hud.height);
	if (env->data.hud.height)
		free(env->data.hud.height);
	printf("%p | %s\n", env->data.hud.sector, env->data.hud.sector);
	if (env->data.hud.sector)
		free(env->data.hud.sector);
	printf("%p | %s\n", env->data.hud.gravity, env->data.hud.gravity);
	if (env->data.hud.gravity)
		free(env->data.hud.gravity);
	printf("%p | %s\n", env->data.hud.friction, env->data.hud.friction);
	if (env->data.hud.friction)
		free(env->data.hud.friction);
}

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
	hud_clean(env);
	error ? ft_print_error(env->error[error], error) : exit(0);
}
