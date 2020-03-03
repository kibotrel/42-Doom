/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:13:40 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/03 15:18:46 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int32_t	get_thread(t_env *env)
{
	int			i;
	pthread_t	s;

	i = 0;
	s = pthread_self();
	while (s != env->sdl.thread[i])
		i++;
	return (i);
}

char	*skybox_asset(int w, int h)
{
	if (w == 1280 && h == 720)
		return ("./assets/skybox_720.bmp");
	else if (w == 1366 && h == 768)
		return ("./assets/skybox_768.bmp");
	else if (w == 1440 && h == 900)
		return ("./assets/skybox_900.bmp");
	else if (w == 1920 && h == 1080)
		return ("./assets/skybox_1080.bmp");
	else
		return (NULL);
}

void	scaled_assets(t_env *env)
{
	env->asset[SHOTGUN] = shotgun_asset(env->w, env->h);
	env->asset[MAGAZINE] = magazine_asset(env->w, env->h);
	env->asset[SHELL] = shell_asset(env->w, env->h);
	env->asset[COIN] = coins_asset(env->w, env->h);
	env->asset[SKYBOX] = skybox_asset(env->w, env->h);
}
