/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:08:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/26 02:31:40 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "utils.h"

void	draw_pixel(t_env *env, SDL_Surface *win, t_pos p, uint32_t color)
{
	int			*px;

	if ((p.x >= 0 && p.x < env->w) && (p.y >= 0 && p.y < env->h))
	{
		px = win->pixels + p.y * win->pitch + p.x * win->format->BytesPerPixel;
		*px = color;
	}
}

void	text_to_screen(t_env *env, t_sdl *sdl, char *text, uint8_t pos)
{
	SDL_Rect	where;
	SDL_Surface	*tmp;

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
	t_pos		p;

	p.y = -1;
	while (++p.y < img.height)
	{
		p.x = -1;
		while (++p.x < img.width)
			if (p.x < e->w && p.y < e->h)
				draw_pixel(e, s->screen, p, img.pixels[p.x + p.y * img.width]);
	}
}

void	draw_line(t_env *env, t_pos start, t_pos end, uint32_t color)
{
	t_pos		p;
	t_line		line;

	line_params(&line, start, end);
	p = start;
	while (p.y != end.y || p.x != end.x)
	{
		if (p.x >= 0 && p.x <= env->w && p.y >= 0 && p.y <= env->h)
			draw_pixel(env, env->sdl.screen, p, color);
		if ((line.error = line.offset * 2) > -line.delta.y)
		{
			line.offset -= line.delta.y;
			p.x += line.sign.x;
		}
		if (line.error < line.delta.x)
		{
			line.offset += line.delta.x;
			p.y += line.sign.y;
		}
		if (p.x >= 0 && p.x <= env->w && p.y >= 0 && p.y <= env->h)
			draw_pixel(env, env->sdl.screen, p, color);
	}
}

void	draw_slice(t_env *env, int x, int y1, int y2, int top, int middle, int bottom)
{
	t_pos		p;

	y1 = clamp(y1, 0, env->h - 1);
	y2 = clamp(y2, 0, env->h - 1);
	p.x = x;
	p.y = y1;
	if(y2 == y1)
		draw_pixel(env, env->sdl.screen, p, middle);
	else if(y2 > y1)
	{
		draw_pixel(env, env->sdl.screen, p, top);
		while (++p.y < y2)
			draw_pixel(env, env->sdl.screen, p, middle);
		draw_pixel(env, env->sdl.screen, p, bottom);
	}
}
