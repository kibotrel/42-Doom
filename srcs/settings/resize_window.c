/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:33:07 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/04 17:17:40 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"
#include "settings.h"
#include "libft.h"
#include "setup.h"
#include "clean.h"
#include "enums.h"
#include "core.h"

static void	clean_and_init_asset(t_env *env)
{
	int			i;

	i = SHOTGUN - 1;
	while (++i < NB_ASSETS)
	{
		free(env->sdl.bmp[i].pixels);
		if (bmp_to_array(env->asset[i], &env->sdl.bmp[i]))
			clean(env, E_BMP_PARSE);
	}
	free(env->sdl.bmp[BG_MENU].pixels);
	if (bmp_to_array(env->asset[BG_MENU], &env->sdl.bmp[BG_MENU]))
		clean(env, E_BMP_PARSE);
}

static void	update_data(t_env *env)
{
	t_pos		p;
	int			config;

	p = (t_pos){env->w, env->h};
	config = SDL_WINDOWPOS_CENTERED;
	TTF_CloseFont(env->sdl.font[0]);
	TTF_CloseFont(env->sdl.font[1]);
	env->sdl.font[0] = TTF_OpenFont("assets/atlas.ttf", env->data.f_size);
	env->sdl.font[1] = TTF_OpenFont("assets/KeepCalm-Medium.ttf",
			env->data.g_size);
	SDL_DestroyWindow(env->sdl.win);
	env->sdl.win = 0;
	env->sdl.screen = 0;
	config = SDL_WINDOWPOS_CENTERED;
	if (!(env->sdl.win = SDL_CreateWindow("", config, config, p.x, p.y, 0)))
		clean(env, E_SDL_WIN);
	if (!(env->sdl.screen = SDL_GetWindowSurface(env->sdl.win)))
		clean(env, E_SDL_WINSURF);
	clean_and_init_asset(env);
	env->data.w_size = env->sdl.screen->h * env->sdl.screen->pitch;
}

static void	setup_resize(t_env *env, t_pos win)
{
	env->setup = 0;
	env->w = win.x;
	env->h = win.y;
	env->cam.fov = v2d(0.75 * env->h, 0.2 * env->h);
	env->data.ui.min.y = floor(env->h / RATIO_UI_Y);
	env->data.ui.min.x = floor(env->w / RATIO_UI_X) * 5;
	env->data.ui.max.y = env->h;
	env->data.ui.max.x = floor(env->w / RATIO_UI_X) * 7;
	env->data.grid.min.y = floor(env->h / RATIO_GRID_Y);
	env->data.grid.min.x = floor(env->w / RATIO_GRID_X);
	env->data.grid.max.y = floor(env->h - RATIO_GRID_Y);
	env->data.grid.max.x = floor(env->w - RATIO_GRID_X);
	if ((get_dimensions(env->h)) == -1)
		clean(env, E_BKGD);
	env->data.f_size = floor(env->w * MAX_FONT_SIZE / MAX_WIDTH);
	env->data.g_size = env->data.f_size / 3;
	env->data.hud.coin.shift = coin_shift(env->w, env->h);
	env->data.hud.shotgun.shift = shotgun_shift(env->w, env->h);
	env->asset[BG_MENU] = background_path(env->w, env->h);
	env->asset[SHOTGUN] = shotgun_asset(env->w, env->h);
	env->asset[MAGAZINE] = magazine_asset(env->w, env->h);
	env->asset[SHELL] = shell_asset(env->w, env->h);
	env->asset[COIN] = coins_asset(env->w, env->h);
	//env->asset[SKYBOX] = skybox_asset(env->w, env->h);
}

static void	setup_great_format(t_env *env)
{
	t_pos	win;

	if (env->setting.index_format == 0)
		win = (t_pos){1280, 720};
	else if (env->setting.index_format == 1)
		win = (t_pos){1366, 768};
	else if (env->setting.index_format == 2)
		win = (t_pos){1440, 900};
	else
		win = (t_pos){1920, 1080};
	setup_resize(env, win);
}

void		resize_window(t_env *env)
{
	setup_great_format(env);
	update_data(env);
	SDL_SetWindowInputFocus(env->sdl.win);
	settings(env);
}
