/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:05:16 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/06 10:41:43 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "settings.h"
#include "texture.h"

void	setting_setup(t_env *env)
{
	env->setting.fog_on_off = true;
	env->setting.border_on_off = false;
	env->setting.fly_mode = false;
	env->setting.format = ft_strsplit(
			"1280x720 1366x768 1440x900 1920x1080", ' ');
	env->setting.mode = NORMAL;
	env->setting.fps_max = 60;
	env->setting.fog_intensity = 7;
	env->setting.light_intensity = LIGHT;
	if (env->w == 1280 && env->h == 720)
		env->setting.index_format = 0;
	else if (env->w == 1366 && env->h == 768)
		env->setting.index_format = 1;
	else if (env->w == 1440 && env->h == 900)
		env->setting.index_format = 2;
	else
		env->setting.index_format = 3;
}
