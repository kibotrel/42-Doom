/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:51:13 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/17 18:46:23 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include <math.h>
#include "doom.h"

static void	left_click(t_env *env, t_point ui, int x, int y)
{
	int		n;
	int		box;

	n = 1;
	box = 0;
	while (n < 8)
	{
		box++;
		if (y >= ui.y * n && y <= ui.y * (n + 1) && x >= ui.x && x <= ui.x * 2)
		{
			printf("Button : %d\n", box);
			return ;
		}
		n += 2;
	}
	(void)env;
}

static void	mouse_motion(t_env *env, t_point ui, int x, int y)
{
	int		n;

	n = 1;
	while (n < 8)
	{
		if (y >= ui.y * n && y <= ui.y * (n + 1) && x >= ui.x && x <= ui.x * 2)
		{
			draw_rectangle(&env->sdl, ui, RED, n);
			return ;
		}
		n += 2;
	}
	draw_buttons(ui, &env->sdl, WHITE);
}

void		handle_mouse(t_env *e, t_sdl *sdl)
{
	if (sdl->event.button.button == SDL_BUTTON_LEFT && e->win == MENU)
		left_click(e, e->data.ui, sdl->event.button.x, sdl->event.button.y);
	else if (sdl->event.type == SDL_MOUSEMOTION)
		mouse_motion(e, e->data.ui, sdl->event.motion.x, sdl->event.motion.y);
}
