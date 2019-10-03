/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:51:13 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 15:29:04 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "env.h"
#include "doom.h"

static void	left_click(t_env *env, t_point ui, int x, int y)
{
	int	n;
	int	box;
	int	size;

	n = 1;
	box = 0;
	while (n < 8)
	{
		box++;
		if (y >= ui.y * n && y <= ui.y * (n + 1)
			&& x >= ui.x * MIN_UI_X && x <= ui.x * MAX_UI_X)
		{
			env->win = box;
			size = env->sdl.screen->h * env->sdl.screen->pitch;
			ft_bzero(env->sdl.screen->pixels, size);
			selector(env);
			break ;
		}
		n += 2;
	}
}

static void	mouse_motion(t_env *env, t_point ui, int x, int y)
{
	int	n;

	n = 1;
	while (n < 8)
	{
		if (y >= ui.y * n && y <= ui.y * (n + 1)
			&& x >= ui.x * MIN_UI_X && x <= ui.x * MAX_UI_X)
		{
			draw_rectangle(&env->sdl, ui, RED, n);
			police_color(&env->sdl.color, 255, 0, 0);
			text_to_screen(env, &env->sdl, get_string(n), n);
			return ;
		}
		n += 2;
	}
	police_color(&env->sdl.color, 255, 255, 255);
	draw_buttons(ui, &env->sdl, WHITE);
	draw_text(env, &env->sdl);
}

void		handle_mouse(t_env *e, t_sdl *sdl)
{
	if (sdl->event.button.button == SDL_BUTTON_LEFT && e->win == MENU)
		left_click(e, e->data.ui, sdl->event.button.x, sdl->event.button.y);
	else if (sdl->event.type == SDL_MOUSEMOTION && e->win == MENU)
		mouse_motion(e, e->data.ui, sdl->event.motion.x, sdl->event.motion.y);
}
