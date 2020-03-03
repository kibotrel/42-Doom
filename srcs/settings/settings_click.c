/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_click.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:03:15 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/03 17:38:55 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"
#include "settings.h"
#include "libft.h"
#include "setup.h"
#include "clean.h"

static void	click_mode(t_env *env, t_vec2d start, int size)
{
	if (check_great_click(env, start, size, 2))
		env->setting.mode = EASY;
	else if (check_great_click(env, start, size + 3, 2))
		env->setting.mode = NORMAL;
	else if (check_great_click(env, start, size + 6, 2))
		env->setting.mode = HARD;
}

static void	click_resolution(t_env *env)
{
	click_arrow(env, v3d(RES_START_X, RES_START_Y, RES_SIZE),
			&env->setting.index_format, 4);
	if (check_great_click(env, v2d(RES_START_X, RES_START_Y), 0, 1) ||
			check_great_click(env, v2d(RES_START_X, RES_START_Y),
				RES_SIZE + 1, 1))
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

void		settings_click(t_env *env)
{
	click_on_off(env, v2d(FOG_START_X, FOG_START_Y), FOG_SIZE,
			&env->setting.fog_on_off);
	click_arrow(env, v3d(FOG_START_X, FOG_START_Y + 2, FOG_INTENSITY_SIZE),
			&env->setting.fog_intensity, 10);
	click_on_off(env, v2d(BORDER_START_X, BORDER_START_Y), BORDER_SIZE,
			&env->setting.border_on_off);
	click_on_off(env, v2d(FLY_START_X, FLY_START_Y), FLY_SIZE,
			&env->setting.fly_mode);
	click_mode(env, v2d(MODE_START_X, MODE_START_Y), MODE_SIZE);
	click_resolution(env);
	click_fov(env);
	click_fps(env);
	click_arrow(env, v3d(LIGHT_START_X, LIGHT_START_Y, LIGHT_SIZE),
			&env->setting.light_intensity, 100);
}
