/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_click.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:03:15 by lojesu            #+#    #+#             */
/*   Updated: 2020/02/25 15:52:21 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"
#include "settings.h"
#include "libft.h"
#include "setup.h"
#include "clean.h"

#define NB_FORMAT 4

static bool	check_great_click(t_env *env, t_vec2d start, int size)
{
	return (env->sdl.event.motion.x <= (start.x + size) * env->data.grid.min.x +
			env->data.grid.min.x && env->sdl.event.motion.x >= (start.x + size)
			* env->data.grid.min.x && env->sdl.event.motion.y >= start.y *
			env->data.grid.min.y && env->sdl.event.motion.y <= start.y *
			env->data.grid.min.y + env->data.grid.min.y);
}

static void click_on_off(t_env *env, t_vec2d start, int size, bool *on_off)
{
	if (check_great_click(env, start, size))
		*on_off = true;
	else if (check_great_click(env, start, size + 2))
		*on_off = false;
}

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

static void	resize_window(t_env *env)
{
	int		win_pos;

	win_pos = SDL_WINDOWPOS_CENTERED;
	SDL_SetWindowTitle(env->sdl.win, TITLE_SETTINGS);
	sdl_clean(&env->sdl);
	setup_great_format(env);
	graphic_setup(env, &env->sdl);
	env->win = SETTINGS;
	env->sdl.screen = SDL_GetWindowSurface(env->sdl.win);
	SDL_SetWindowPosition(env->sdl.win, win_pos, win_pos);
	printf("%c\n", env->setting.fog_on_off + 48);
}

static void	click_arrow(t_env *env, t_vec2d start, int size)
{
	if (check_great_click(env, start, 0))
	{
		--env->setting.index_format;
		if (env->setting.index_format < 0)
			env->setting.index_format = NB_FORMAT - 1;
		resize_window(env);
	}
	else if (check_great_click(env, start, size + 1))
	{
		++env->setting.index_format;
		if (env->setting.index_format >= NB_FORMAT)
			env->setting.index_format = 0;
		resize_window(env);
	}
}

void        settings_click(t_env *env)
{
	click_on_off(env, v2d(FOG_START_X, FOG_START_Y), FOG_SIZE,
			&env->setting.fog_on_off);
	click_on_off(env, v2d(BORDER_START_X, BORDER_START_Y), BORDER_SIZE,
			&env->setting.border_on_off);
	click_arrow(env, v2d(RES_START_X, RES_START_Y), RES_SIZE);
}
