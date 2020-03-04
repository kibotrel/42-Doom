/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:06:01 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/03 17:40:42 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"
#include "texture.h"
#include "settings.h"
#include "libft.h"

void	my_draw_background(t_env *e, t_sdl *s, t_bmp img)
{
	t_pos	p;

	p.y = -1;
	while (++p.y < img.height)
	{
		p.x = -1;
		while (++p.x < img.width)
			if (p.x < e->w && p.y < e->h)
				draw_pixel(e, s->screen, p, color_light(
							img.pixels[p.x + p.y * img.width], 0x303030, 75));
	}
}

void	my_police_color(SDL_Color *color, uint32_t color_hex)
{
	color->r = (color_hex >> 16 & 0xFF);
	color->g = (color_hex >> 8 & 0xFF);
	color->b = (color_hex & 0xFF);
}

void	draw_on_off
	(t_env *env, t_vec2d start, uint32_t color_1, uint32_t color_2)
{
	my_police_color(&env->sdl.color, color_1);
	info(env, ft_strdup("on"), v2d(start.x, start.y), 0);
	my_police_color(&env->sdl.color, color_2);
	info(env, ft_strdup("off"), v2d(start.x + 2, start.y), 0);
	my_police_color(&env->sdl.color, RESET);
}

void	fov_update(t_env *env, int mode)
{
	if (mode == 0)
	{
		if (env->cam.fov.x < env->h * 2 && env->cam.fov.y < env->h * 2)
		{
			env->cam.fov.x += (0.0375 * env->h);
			env->cam.fov.y += (0.01 * env->h);
		}
	}
	else if (mode == 1)
	{
		if (env->cam.fov.x > env->h / 16 && env->cam.fov.y > env->h / 16)
		{
			env->cam.fov.x -= (0.0375 * env->h);
			env->cam.fov.y -= (0.01 * env->h);
		}
	}
}
