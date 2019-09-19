/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:08:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/19 19:21:17 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
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
	scale_text(env, sdl, text, pos);
	if (!(sdl->text = TTF_RenderText_Blended(sdl->font, text, sdl->color)))
		env->status = E_TTF_RENDER;
	if (!env->status && SDL_BlitSurface(sdl->text, 0, sdl->screen, &sdl->pos))
		env->status = E_SDL_BLIT;
	if (env->status)
	{
		clean_sdl(sdl);
		ft_print_error(env->error[env->status], env->status);
	}
}
