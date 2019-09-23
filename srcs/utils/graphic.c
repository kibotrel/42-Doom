/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:08:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/23 18:59:19 by kibotrel         ###   ########.fr       */
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

void	text_to_screen(t_env *env, t_sdl *sdl, char *text, int pos)
{
	SDL_Rect		where;
	SDL_Surface		*tmp;

	scale_text(env, &where, text, pos);
	if (!(tmp = TTF_RenderText_Solid(sdl->font, text, sdl->color)))
		clean(env, E_TTF_RENDER);
	if (SDL_BlitSurface(tmp, 0, sdl->screen, &where))
		clean(env, E_SDL_BLIT);
	else
		SDL_FreeSurface(tmp);
}
