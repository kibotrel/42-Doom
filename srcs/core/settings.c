/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/20 14:56:15 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"
#include "utils.h"
#include "editor.h"
#include "texture.h"

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

void	settings(t_env *env)
{
	if (!env->setup)
	{
		SDL_SetWindowTitle(env->sdl.win, TITLE_SETTINGS);
		my_draw_background(env, &env->sdl, env->sdl.bmp[BG_MENU]);
		rectangle(init_vertex(env->w - 500, 400), init_vertex(env->w - 150, 480), 0x0000ff, env->sdl.screen);
		rectangle(init_vertex(env->w - 500, 500), init_vertex(env->w - 150, 580), 0x0000ff, env->sdl.screen);
		rectangle(init_vertex(env->w - 500, 600), init_vertex(env->w - 150, 680), 0x0000ff, env->sdl.screen);
		env->setup = 1;
	}
}
