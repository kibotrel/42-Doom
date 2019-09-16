/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:45:38 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/16 13:23:16 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "doom.h"

void	hooks(t_env *env, t_sdl *sdl)
{
	while (env->run)
	{
		while (SDL_PollEvent(&sdl->event))
		{
			if (sdl->event.type == SDL_QUIT)
				env->run = 0;
			else if (sdl->event.type == SDL_KEYDOWN
				&& sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				env->run = 0;
		}
		if (SDL_UpdateWindowSurface(sdl->win))
			exit(5);
	}
	clean_sdl(sdl);
}
