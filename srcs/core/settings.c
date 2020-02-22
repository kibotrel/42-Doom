/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/22 15:33:06 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"
#include "utils.h"
#include "editor.h"
#include "texture.h"
#include "settings.h"
#include "libft.h"

static void    my_draw_background(t_env *e, t_sdl *s, t_bmp img)
{
	t_pos       p;

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

void		settings_click(t_env *env, SDL_Event event)
{
	if (event.motion.x <= env->w - 650 && event.motion.x >= env->w - 800 &&
			event.motion.y >= 200 && event.motion.y <= 280)
		printf("CONARD\n");
}

void		settings(t_env *env)
{
	if (!env->setup)
	{
		SDL_SetWindowTitle(env->sdl.win, TITLE_SETTINGS);
		my_draw_background(env, &env->sdl, env->sdl.bmp[BG_MENU]);
		info(env, ft_strdup("Fog of War\t\t\t\ton\toff"), v2d(35, 5), 0);
		info(env, ft_strdup("sector borders\t\t\ton\toff"), v2d(35, 7), 0);
		info(env, ft_strdup("mode :\t\tnormal\t\thard"), v2d(35, 9), 0);
		info(env, ft_strdup(" <\tresolution\t>"), v2d(36, 11), 0);
		info(env, ft_strdup("<\tFOV\t>"), v2d(37, 13), 0);
		info(env, ft_strdup("<\tFPS \t>"), v2d(37, 15), 0);
		env->setup = 1;
	}
}
