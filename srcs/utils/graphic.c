/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:08:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/17 13:00:23 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "env.h"

void	draw_pixel(SDL_Surface *win, int x, int y, int color)
{
	int	*pixel;

	if ((x >= 0 && x < WIN_W) && (y >= 0 && y < WIN_H))
	{
		pixel = win->pixels + y * win->pitch + x * win->format->BytesPerPixel;
		*pixel = color;
	}
}
