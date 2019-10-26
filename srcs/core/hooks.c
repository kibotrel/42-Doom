/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:45:38 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/26 22:54:12 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"
#include "clean.h"
#include "events.h"

void	hooks(t_env *env, t_sdl *sdl)
{
	while (1)
	{
		while (SDL_PollEvent(&sdl->event))
		{
			if (sdl->event.type == SDL_QUIT)
				clean(env, NOTHING);
			if (env->sdl.event.type == SDL_KEYDOWN)
			{
			//	printf("%d\n", sdl->event.key.keysym.scancode);
				env->input[sdl->event.key.keysym.scancode] = 1;
			}
			if (env->sdl.event.type == SDL_KEYUP)
				env->input[sdl->event.key.keysym.scancode] = 0;
			if (sdl->event.type == SDL_MOUSEBUTTONDOWN)
				handle_mouse(env, sdl);
			if (sdl->event.type == SDL_MOUSEMOTION)
				handle_motion(env, sdl);
			if (env->sdl.event.window.event == SDL_WINDOWEVENT_CLOSE)
				clean(env, NOTHING);
		}
		handle_keyboard(env);
		if (SDL_UpdateWindowSurface(sdl->win))
			clean(env, E_SDL_UPDATE);
	}
}
