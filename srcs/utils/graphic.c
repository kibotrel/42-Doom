/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:08:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/17 18:13:38 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "env.h"
#include "doom.h"

void	draw_pixel(SDL_Surface *win, int x, int y, int color)
{
	int		*pixel;

	if ((x >= 0 && x < WIN_W) && (y >= 0 && y < WIN_H))
	{
		pixel = win->pixels + y * win->pitch + x * win->format->BytesPerPixel;
		*pixel = color;
	}
}

void	draw_rectangle(t_sdl *sdl, t_point ui, int color, int n)
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
void	draw_buttons(t_point ui, t_sdl *sdl, int color)
{
	int		n;

	n = -1;
	while (++n < 8)
		draw_rectangle(sdl, ui, color, ++n);
}
