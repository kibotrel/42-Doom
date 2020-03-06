/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_off_setting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:26:49 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/06 10:31:18 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "settings.h"
#include "libft.h"

void	draw_fog_of_war(t_env *env)
{
	info(env, ft_strdup("Fog of war"), v2d(FOG_START_X, FOG_START_Y), 0);
	info(env, ft_strdup("<"), v2d(FOG_START_X, FOG_START_Y + 2), 0);
	info(env, ft_strdup("  >"),
			v2d(FOG_START_X + FOG_INTENSITY_SIZE + 1, FOG_START_Y + 2), 0);
	info(env, ft_strdup("Distance"), v2d(FOG_START_X + 1, FOG_START_Y + 2), 0);
	info(env, ft_itoa(env->setting.fog_intensity),
			v2d(FOG_START_X + FOG_INTENSITY_SIZE + 3, FOG_START_Y + 2), 0);
	if (env->setting.fog_on_off == true)
		draw_on_off(env, v2d(FOG_START_X + FOG_SIZE, FOG_START_Y), RESET, HIDE);
	else
		draw_on_off(env, v2d(FOG_START_X + FOG_SIZE, FOG_START_Y), HIDE, RESET);
}

void	draw_sector_borders(t_env *env)
{
	info(env, ft_strdup("Sector borders"),
			v2d(BORDER_START_X, BORDER_START_Y), 0);
	if (env->setting.border_on_off == true)
		draw_on_off(env, v2d(BORDER_START_X + BORDER_SIZE, BORDER_START_Y),
				RESET, HIDE);
	else
		draw_on_off(env, v2d(BORDER_START_X + BORDER_SIZE, BORDER_START_Y),
				HIDE, RESET);
}

void	draw_fly_mode(t_env *env)
{
	info(env, ft_strdup("Fly mode"), v2d(FLY_START_X, FLY_START_Y), 0);
	if (env->setting.fly_mode == true)
		draw_on_off(env, v2d(FLY_START_X + FLY_SIZE, FLY_START_Y),
				RESET, HIDE);
	else
		draw_on_off(env, v2d(FLY_START_X + FLY_SIZE, FLY_START_Y),
				HIDE, RESET);
}
