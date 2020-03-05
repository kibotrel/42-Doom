/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_selector_setting.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:29:47 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/05 14:43:14 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"
#include "utils.h"
#include "texture.h"
#include "settings.h"
#include "libft.h"

static void	select_great_mode(t_env *env)
{
	if (env->setting.mode == EASY)
	{
		my_police_color(&env->sdl.color, RESET);
		info(env, ft_strdup("Easy"),
				v2d(MODE_START_X + MODE_SIZE, MODE_START_Y), 0);
	}
	else if (env->setting.mode == NORMAL)
	{
		my_police_color(&env->sdl.color, RESET);
		info(env, ft_strdup("Normal"),
				v2d(MODE_START_X + MODE_SIZE + 3, MODE_START_Y), 0);
	}
	else if (env->setting.mode == HARD)
	{
		my_police_color(&env->sdl.color, RESET);
		info(env, ft_strdup("Hard"),
				v2d(MODE_START_X + MODE_SIZE + 6, MODE_START_Y), 0);
	}
}

void		draw_mode(t_env *env)
{
	info(env, ft_strdup("Mode"), v2d(MODE_START_X, MODE_START_Y), 0);
	my_police_color(&env->sdl.color, HIDE);
	info(env, ft_strdup("Easy"),
			v2d(MODE_START_X + MODE_SIZE, MODE_START_Y), 0);
	info(env, ft_strdup("Normal"),
			v2d(MODE_START_X + MODE_SIZE + 3, MODE_START_Y), 0);
	info(env, ft_strdup("Hard"),
			v2d(MODE_START_X + MODE_SIZE + 6, MODE_START_Y), 0);
	select_great_mode(env);
	my_police_color(&env->sdl.color, RESET);
}

void		draw_fps(t_env *env)
{
	info(env, ft_strdup("FPS"), v2d(FPS_START_X, FPS_START_Y), 0);
	my_police_color(&env->sdl.color, HIDE);
	info(env, ft_strdup("30"), v2d(FPS_START_X + 4, FPS_START_Y), 0);
	info(env, ft_strdup("60"), v2d(FPS_START_X + 6, FPS_START_Y), 0);
	info(env, ft_strdup("Unlimited"), v2d(FPS_START_X + 8, FPS_START_Y), 0);
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
		info(env, ft_strdup("Unlimited"), v2d(FPS_START_X + 8, FPS_START_Y), 0);
	}
	my_police_color(&env->sdl.color, RESET);
}
