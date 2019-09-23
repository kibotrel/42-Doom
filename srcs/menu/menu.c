/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:45:57 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/23 19:06:37 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include "env.h"
#include "doom.h"

void		draw_rectangle(t_sdl *sdl, t_point ui, int color, int n)
{
	t_point	p;

	p.y = ui.y * n;
	while (p.y <= ui.y * (n + 1))
	{
		p.x = ui.x - 1;
		while (++p.x <= ui.x * 2)
		{
			if (p.y == ui.y * n || p.y == ui.y * (n + 1))
				draw_pixel(sdl->screen, p.x, p.y, color);
			if (p.x == ui.x || p.x == ui.x * 2)
				draw_pixel(sdl->screen, p.x, p.y, color);
		}
		p.y++;
	}
}

void		draw_buttons(t_point ui, t_sdl *sdl, int color)
{
	int		n;

	n = -1;
	while (++n < 8)
		draw_rectangle(sdl, ui, color, ++n);
}

static void	draw_text(t_env *env, t_sdl *sdl)
{
	text_to_screen(env, sdl, "GAME", 1);
	text_to_screen(env, sdl, "EDITOR", 3);
	text_to_screen(env, sdl, "SETTINGS", 5);
	text_to_screen(env, sdl, "QUIT", 7);
}

void		menu(t_env *env)
{
	SDL_SetWindowTitle(env->sdl.win, TITLE_MENU);
	draw_buttons(env->data.ui, &env->sdl, WHITE);
	draw_text(env, &env->sdl);
}
