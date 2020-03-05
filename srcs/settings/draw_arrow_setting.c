/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arrow_setting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:27:23 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/05 14:42:33 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"
#include "utils.h"
#include "texture.h"
#include "settings.h"
#include "libft.h"

void	draw_resolution(t_env *env)
{
	info(env, ft_strdup("<"), v2d(RES_START_X, RES_START_Y), 0);
	info(env, ft_strdup(" Resolution"), v2d(RES_START_X + 1, RES_START_Y), 0);
	info(env, ft_strdup(" >"), v2d(RES_START_X + RES_SIZE + 1, RES_START_Y), 0);
	info(env, ft_strdup(env->setting.format[env->setting.index_format]),
			v2d(RES_START_X + RES_SIZE + 3, RES_START_Y), 0);
}

void	draw_fov(t_env *env)
{
	info(env, ft_strdup("FOV"), v2d(FOV_START_X + 1, FOV_START_Y), 0);
	info(env, ft_strdup("<"), v2d(FOV_START_X, FOV_START_Y), 0);
	info(env, ft_strdup(">"), v2d(FOV_START_X + FOV_SIZE + 1, FOV_START_Y), 0);
	info(env, ft_itoa((inter(
					round((1 / (env->cam.fov.x / env->h)) * 56), 30, 245))),
			v2d(FOV_START_X + FOV_SIZE + 3, FOV_START_Y), 0);
}

void	draw_light_intensity(t_env *env)
{
	info(env, ft_strdup("Light intensity"),
			v2d(LIGHT_START_X + 1, LIGHT_START_Y), 0);
	info(env, ft_strdup("<"), v2d(LIGHT_START_X, LIGHT_START_Y), 0);
	info(env, ft_strdup(">"),
			v2d(LIGHT_START_X + LIGHT_SIZE + 1, LIGHT_START_Y), 0);
	info(env, ft_itoa(env->setting.light_intensity),
			v2d(LIGHT_START_X + LIGHT_SIZE + 3, LIGHT_START_Y), 0);
}
