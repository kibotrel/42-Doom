/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:05 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/19 15:27:57 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "SDL_ttf.h"
#include "doom.h"

void	clean_sdl(t_sdl *sdl)
{
	unsigned int	subsystems;

	subsystems = SDL_INIT_VIDEO | SDL_INIT_AUDIO;
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
	if (SDL_WasInit(subsystems) == subsystems)
		TTF_Quit();
	SDL_Quit();
}
