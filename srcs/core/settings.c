/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/24 18:32:09 by lojesu           ###   ########.fr       */
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
	info(env, ft_strdup("fog_of_war"), v2d(FOG_START_X, FOG_START_Y), 0);
	if (env->setting.fog_on_off == true)
		draw_on_off(env, v2d(FOG_START_X + FOG_SIZE, FOG_START_Y), RESET, HIDE);
	else
		draw_on_off(env, v2d(FOG_START_X + FOG_SIZE, FOG_START_Y), HIDE, RESET);
}

static void		draw_sector_borders(t_env *env)
{
	info(env, ft_strdup("sector borders"), v2d(BORDER_START_X, BORDER_START_Y), 0);
	if (env->setting.border_on_off == true)
		draw_on_off(env, v2d(BORDER_START_X + BORDER_SIZE, BORDER_START_Y), RESET, HIDE);
	else
		draw_on_off(env, v2d(BORDER_START_X + BORDER_SIZE, BORDER_START_Y), HIDE, RESET);
}

static void		draw_resolution(t_env *env)
{
	info(env, ft_strdup("<"), v2d(RES_START_X, RES_START_Y), 0);
	info(env, ft_strdup(" resolution"), v2d(RES_START_X + 1, RES_START_Y), 0);
	info(env, ft_strdup(" >"), v2d(RES_START_X + RES_SIZE + 1, RES_START_Y), 0);
	info(env, ft_strdup(env->setting.format[env->setting.index_format]),
			v2d(RES_START_X + RES_SIZE + 3, RES_START_Y), 0);
}

void		settings(t_env *env)
{
	if (!env->setup)
	{
		SDL_SetWindowTitle(env->sdl.win, TITLE_SETTINGS);
		env->setup = 1;
	}
		my_draw_background(env, &env->sdl, env->sdl.bmp[BG_MENU]);
		draw_fog_of_war(env);
		draw_sector_borders(env);
		draw_resolution(env);
		info(env, ft_strdup("mode \t\tnormal\t\thard"), v2d(35, 9), 0);
		info(env, ft_strdup("<\tFOV\t>"), v2d(37, 13), 0);
		info(env, ft_strdup("<\tFPS \t>"), v2d(37, 15), 0);
}
