/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_click.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:03:15 by lojesu            #+#    #+#             */
/*   Updated: 2020/02/26 17:25:32 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"
#include "settings.h"
#include "libft.h"
#include "setup.h"
#include "clean.h"

#define NB_FORMAT 4

static bool	check_great_click(t_env *env, t_vec2d start, int size, int size_click)
{
	return (env->sdl.event.motion.x <= (start.x + size) * env->data.grid.min.x +
			env->data.grid.min.x  * size_click && env->sdl.event.motion.x >= (start.x + size)
			* env->data.grid.min.x && env->sdl.event.motion.y >= start.y *
			env->data.grid.min.y && env->sdl.event.motion.y <= start.y *
			env->data.grid.min.y + env->data.grid.min.y);
}

static void click_on_off(t_env *env, t_vec2d start, int size, bool *on_off)
{
	if (check_great_click(env, start, size, 1))
		*on_off = true;
	else if (check_great_click(env, start, size + 2, 1))
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
}

static void	click_mode(t_env *env, t_vec2d start, int size)
{
	if (check_great_click(env, start, size, 2))
		env->setting.mode = NORMAL;
	else if (check_great_click(env, start, size + 3, 2))
		env->setting.mode = HARD;
}

static void	click_arrow(t_env *env, t_vec3d start, int8_t *index, int8_t index_max)
{
	if (check_great_click(env, v2d(start.x, start.y), 0, 1))
	{
		*index -= 1;
		if (*index < 0)
			*index = index_max - 1;
	}
	else if (check_great_click(env, v2d(start.x, start.y), start.z + 1, 1))
	{
		*index += 1;
		if (*index >= index_max)
			*index = 0;
	}
}
static void	click_resolution(t_env *env)
{
	click_arrow(env, v3d(RES_START_X, RES_START_Y, RES_SIZE),
			&env->setting.index_format, NB_FORMAT);
	if (check_great_click(env, v2d(RES_START_X, RES_START_Y), 0, 1) ||
			check_great_click(env, v2d(RES_START_X, RES_START_Y), RES_SIZE + 1, 1))
	{
		resize_window(env);
	}
}

static void	click_fov(t_env *env)
{
	int8_t	index_tmp;

	index_tmp = 1;
	click_arrow(env, v3d(FOV_START_X, FOV_START_Y, FOV_SIZE), &index_tmp, 3);
	if (index_tmp == 0)
		fov_update(env, 0);
	else if (index_tmp == 2)
		fov_update(env, 1);
}

static void	click_fps(t_env *env)
{
	if (check_great_click(env, v2d(FPS_START_X, FPS_START_Y), 4, 1))
		env->setting.fps_max = 30;
	else if (check_great_click(env, v2d(FPS_START_X, FPS_START_Y), 6, 1))
		env->setting.fps_max = 60;
	else if (check_great_click(env, v2d(FPS_START_X, FPS_START_Y), 8, 3))
		env->setting.fps_max = FPS_UNLIMITED;
}

void        settings_click(t_env *env)
{
	click_on_off(env, v2d(FOG_START_X, FOG_START_Y), FOG_SIZE,
			&env->setting.fog_on_off);
	click_on_off(env, v2d(BORDER_START_X, BORDER_START_Y), BORDER_SIZE,
			&env->setting.border_on_off);
	click_mode(env, v2d(MODE_START_X, MODE_START_Y), MODE_SIZE);
	click_resolution(env);
	click_fov(env);
	click_fps(env);
}
