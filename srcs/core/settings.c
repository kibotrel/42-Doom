/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/26 17:27:28 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"
#include "utils.h"
#include "texture.h"
#include "settings.h"
#include "libft.h"

static void		draw_fog_of_war(t_env *env)
{
	info(env, ft_strdup("fog of war"), v2d(FOG_START_X, FOG_START_Y), 0);
	if (env->setting.fog_on_off == true)
		draw_on_off(env, v2d(FOG_START_X + FOG_SIZE, FOG_START_Y), RESET, HIDE);
	else
		draw_on_off(env, v2d(FOG_START_X + FOG_SIZE, FOG_START_Y), HIDE, RESET);
}

static void		draw_sector_borders(t_env *env)
{
	info(env, ft_strdup("sector borders"), v2d(BORDER_START_X, BORDER_START_Y), 0);
	if (env->setting.border_on_off == true)
		draw_on_off(env, v2d(BORDER_START_X + BORDER_SIZE, BORDER_START_Y),
				RESET, HIDE);
	else
		draw_on_off(env, v2d(BORDER_START_X + BORDER_SIZE, BORDER_START_Y),
				HIDE, RESET);
}

static void		draw_resolution(t_env *env)
{
	info(env, ft_strdup("<"), v2d(RES_START_X, RES_START_Y), 0);
	info(env, ft_strdup(" resolution"), v2d(RES_START_X + 1, RES_START_Y), 0);
	info(env, ft_strdup(" >"), v2d(RES_START_X + RES_SIZE + 1, RES_START_Y), 0);
	info(env, ft_strdup(env->setting.format[env->setting.index_format]),
			v2d(RES_START_X + RES_SIZE + 3, RES_START_Y), 0);
}

static void		draw_mode(t_env *env)
{
	info(env, ft_strdup("mode"), v2d(MODE_START_X, MODE_START_Y), 0);
	if (env->setting.mode == NORMAL)
	{
		info(env, ft_strdup("normal"), v2d(MODE_START_X + MODE_SIZE, MODE_START_Y), 0);
		my_police_color(&env->sdl.color, HIDE);
		info(env, ft_strdup("hard"), v2d(MODE_START_X + MODE_SIZE + 3, MODE_START_Y), 0);
		my_police_color(&env->sdl.color, RESET);
	}
	else if (env->setting.mode == HARD)
	{
		my_police_color(&env->sdl.color, HIDE);
		info(env, ft_strdup("normal"), v2d(MODE_START_X + MODE_SIZE, MODE_START_Y), 0);
		my_police_color(&env->sdl.color, RESET);
		info(env, ft_strdup("hard"), v2d(MODE_START_X + MODE_SIZE + 3, MODE_START_Y), 0);
	}
}

static void		draw_fov(t_env *env)
{
	info(env, ft_strdup("FOV"), v2d(FOV_START_X + 1, FOV_START_Y), 0);
	info(env, ft_strdup("<"), v2d(FOV_START_X, FOV_START_Y), 0);
	info(env, ft_strdup(">"), v2d(FOV_START_X + FOV_SIZE + 1, FOV_START_Y), 0);
	info(env, ft_strdup(ft_itoa((inter(round((1 / (env->cam.fov.x / env->h)) * 56), 30, 245)))),
			v2d(FOV_START_X + FOV_SIZE + 3, FOV_START_Y), 0);
}

static void		draw_fps(t_env *env)
{
	info(env, ft_strdup("FPS"), v2d(FPS_START_X, FPS_START_Y), 0);
	my_police_color(&env->sdl.color, HIDE);
	info(env, ft_strdup("30"), v2d(FPS_START_X + 4, FPS_START_Y), 0);
	info(env, ft_strdup("60"), v2d(FPS_START_X + 6, FPS_START_Y), 0);
	info(env, ft_strdup("unlimited"), v2d(FPS_START_X + 8, FPS_START_Y), 0);
	if (env->setting.fps_max == 30)
	{
		my_police_color(&env->sdl.color, RESET);
		info(env, ft_strdup("30"), v2d(FPS_START_X + 4, FPS_START_Y), 0);
	}
	else if (env->setting.fps_max == 60)
	{
		my_police_color(&env->sdl.color, RESET);
		info(env, ft_strdup("60"), v2d(FPS_START_X + 6, FPS_START_Y), 0);
	}
	else if (env->setting.fps_max == -1)
	{
		my_police_color(&env->sdl.color, RESET);
		info(env, ft_strdup("unlimited"), v2d(FPS_START_X + 8, FPS_START_Y), 0);
	}
		my_police_color(&env->sdl.color, RESET);
}

void			settings(t_env *env)
{
	if (!env->setup)
	{
		SDL_SetWindowTitle(env->sdl.win, TITLE_SETTINGS);
		env->setup = 1;
	}
	my_draw_background(env, &env->sdl, env->sdl.bmp[BG_MENU]);
	draw_fog_of_war(env);
	draw_sector_borders(env);
	draw_mode(env);
	draw_resolution(env);
	draw_fov(env);
	draw_fps(env);
}
