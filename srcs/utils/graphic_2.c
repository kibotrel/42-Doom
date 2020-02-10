/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:35:56 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/10 03:39:12 by vivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

void	info(t_env *env, char *str, t_vec2d pos, uint32_t mode)
{
	t_vec		p;
	SDL_Rect	where;
	uint32_t	error;
	SDL_Surface	*tmp;

	error = 0;
	if (!str)
		return ;
	TTF_SizeText(env->sdl.font[1], str, &p.x, &p.y);
	where.x = env->data.grid.min.x * pos.x;
	where.y = env->data.grid.min.y * pos.y;
	if (mode)
	{
		where.x += (((where.x + env->data.grid.min.x) - (where.x + p.x)) / 2);
		where.y += (((where.y + env->data.grid.min.y) - (where.y + p.y)) / 2);
	}
	if (!(tmp = TTF_RenderText_Blended(env->sdl.font[1], str, env->sdl.color)))
		error = E_TTF_RENDER;
	if (!error && SDL_BlitSurface(tmp, 0, env->sdl.screen, &where))
		error = E_SDL_BLIT;
	if (tmp)
		SDL_FreeSurface(tmp);
	free(str);
}

void	draw_asset(t_env *env, t_bmp asset, t_pos shift)
{
	t_pos		p;
	t_pos		px;
	uint32_t	pos;

	p.y = -1;
	while (++p.y < asset.height)
	{
		p.x = -1;
		px.y = shift.y - asset.height + p.y;
		while (++p.x < asset.width)
		{
			px.x = shift.x + p.x;
			pos = p.x + p.y * asset.width;
			if (asset.pixels[pos] != 41704)
				draw_pixel(env, env->sdl.screen, px, asset.pixels[pos]);
		}
	}
}

void	blur_area(t_env *env, t_pos min, t_pos max)
{
	t_pos		p;

	p.y = min.y - 1;
	while (++p.y < max.y)
	{
		p.x = min.x - 1;
		while (++p.x < max.x)
			blur(env, env->sdl.screen, p);
	}
}
