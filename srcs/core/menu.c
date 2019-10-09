/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:56:17 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/09 02:27:02 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "env.h"
#include "doom.h"

void	draw_button(t_env *env, t_ui ui, int color, int n)
{
	t_point	p;

	p.y = ui.min.y * n;
	while (p.y <= ui.min.y * (n + 1))
	{
		p.x = ui.min.x - 1;
		while (++p.x <= ui.max.x)
		{
			if (p.y == ui.min.y * n || p.y == ui.min.y * (n + 1))
				draw_pixel(env, env->sdl.screen, p, color);
			if (p.x == ui.min.x || p.x == ui.max.x)
				draw_pixel(env, env->sdl.screen, p, color);
		}
		p.y++;
	}
}

void	draw_ui(t_env *env)
{
	int	i;

	i = 1;
	while (i < RATIO_UI_Y)
	{
		draw_button(env, env->data.ui, WHITE, i);
		text_to_screen(env, &env->sdl, get_string(i), i);
		i += 2;
	}
}

void	menu(t_env *env)
{
	SDL_SetWindowTitle(env->sdl.win, TITLE_MENU);
	draw_background(env, &env->sdl, env->sdl.bmp);
	draw_ui(env);
}
