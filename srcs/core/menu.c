/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:56:17 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/05 13:21:00 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"

void	draw_button(t_env *env, t_ui ui, uint32_t color, uint8_t n)
{
	t_pos	p;

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
	uint8_t	i;

	i = 1;
	while (i < RATIO_UI_Y)
	{
		if (i != env->data.ui.button)
		{
			draw_button(env, env->data.ui, WHITE, i);
			text_to_screen(env, &env->sdl, get_string(i), i);
		}
		i += 2;
	}
}

void	menu(t_env *env)
{
	if (env->setup < 2)
	{
		env->setup = 2;
		env->data.ui.button = 0;
		SDL_SetWindowTitle(env->sdl.win, TITLE_MENU);
		draw_background(env, &env->sdl, env->sdl.bmp[BG_MENU]);
	}
	draw_ui(env);
}
