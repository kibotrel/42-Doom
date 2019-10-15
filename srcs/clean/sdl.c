/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:05 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 21:29:28 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	sdl_clean(t_sdl *sdl)
{
	if (sdl->screen)
		SDL_FreeSurface(sdl->screen);
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
	SDL_Quit();
}
