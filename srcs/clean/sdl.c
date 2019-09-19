/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:05 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/19 19:21:50 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "SDL_ttf.h"
#include "doom.h"

void	clean_sdl(t_sdl *sdl)
{
	if (sdl->screen)
		SDL_FreeSurface(sdl->screen);
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
	if (sdl->font)
		TTF_CloseFont(sdl->font);
	TTF_Quit();
	SDL_Quit();
}
