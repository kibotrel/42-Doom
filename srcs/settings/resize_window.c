/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:33:07 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/03 17:37:57 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"
#include "settings.h"
#include "libft.h"
#include "setup.h"
#include "clean.h"

static void	setup_great_format(t_env *env)
{
	if (env->setting.index_format == 0)
	{
		SDL_SetWindowSize(env->sdl.win, 1280, 720);
		env_setup(env, 1280, 720, false);
	}
	else if (env->setting.index_format == 1)
	{
		SDL_SetWindowSize(env->sdl.win, 1366, 768);
		env_setup(env, 1366, 768, false);
	}
	else if (env->setting.index_format == 2)
	{
		SDL_SetWindowSize(env->sdl.win, 1440, 900);
		env_setup(env, 1440, 900, false);
	}
	else
	{
		SDL_SetWindowSize(env->sdl.win, 1920, 1080);
		env_setup(env, 1920, 1080, false);
	}
}

void		resize_window(t_env *env)
{
	int	win_pos;

	win_pos = SDL_WINDOWPOS_CENTERED;
	SDL_SetWindowTitle(env->sdl.win, TITLE_SETTINGS);
	sdl_clean(&env->sdl);
	setup_great_format(env);
	graphic_setup(env, &env->sdl);
	env->win = SETTINGS;
	env->sdl.screen = SDL_GetWindowSurface(env->sdl.win);
	SDL_SetWindowPosition(env->sdl.win, win_pos, win_pos);
}
