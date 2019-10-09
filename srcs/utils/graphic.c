/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:08:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/09 02:55:11 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "env.h"
#include "doom.h"

void	draw_pixel(t_env *env, SDL_Surface *win, t_point p, int color)
{
	int		*px;

	if ((p.x >= 0 && p.x < env->w) && (p.y >= 0 && p.y < env->h))
	{
		px = win->pixels + p.y * win->pitch + p.x * win->format->BytesPerPixel;
		*px = color;
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

void	draw_background(t_env *e, t_sdl *s, t_bmp img)
{
	t_point			p;

	p.y = -1;
	while (++p.y < img.height)
	{
		p.x = -1;
		while (++p.x < img.width)
			if (p.x < e->w && p.y < e->h)
				draw_pixel(e, s->screen, p, img.pixels[p.x + p.y * img.width]);
	}
}
