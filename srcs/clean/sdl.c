/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:05 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/16 11:54:07 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "doom.h"

void	clean_sdl(t_sdl *sdl)
{
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
	SDL_Quit();
}
