/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:45:38 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/23 19:04:39 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "env.h"
#include "doom.h"

void	hooks(t_env *env, t_sdl *sdl)
{
	while (1)
	{
		while (SDL_PollEvent(&sdl->event))
		{
			if (sdl->event.type == SDL_QUIT)
				clean(env, NOTHING);
			else if (sdl->event.type == SDL_KEYDOWN)
				handle_keyboard(env, sdl);
			else if (sdl->event.type == SDL_MOUSEBUTTONDOWN
					|| sdl->event.type == SDL_MOUSEMOTION)
				handle_mouse(env, sdl);
		}
		if (SDL_UpdateWindowSurface(sdl->win))
			clean(env, E_SDL_UPDATE);
	}
}
