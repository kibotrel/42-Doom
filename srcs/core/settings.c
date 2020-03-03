/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/03 17:03:06 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"
#include "utils.h"
#include "texture.h"
#include "settings.h"
#include "libft.h"

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
	draw_fly_mode(env);
	draw_mode(env);
	draw_resolution(env);
	draw_fov(env);
	draw_fps(env);
	draw_light_intensity(env);
}
