/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:45:38 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/30 11:30:32 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "clean.h"
#include "events.h"

//
// printf("%d\n", sdl->event.key.keysym.scancode);
//

void	global_hooks(t_env *env, t_sdl *sdl)
{
	while (SDL_PollEvent(&sdl->event))
	{
		if (sdl->event.type == SDL_QUIT)
			clean(env, NOTHING);
		if (env->sdl.event.type == SDL_KEYDOWN)
			env->input[sdl->event.key.keysym.scancode] = 1;
		if (env->sdl.event.type == SDL_KEYUP)
			env->input[sdl->event.key.keysym.scancode] = 0;
		if (sdl->event.type == SDL_MOUSEBUTTONDOWN)
			handle_mouse(env, sdl);
		if (sdl->event.type == SDL_MOUSEMOTION)
			handle_motion(env, sdl);
		if (sdl->event.type == SDL_MOUSEWHEEL)
			handle_mousewheel(env, sdl);
		if (env->sdl.event.window.event == SDL_WINDOWEVENT_CLOSE)
			clean(env, NOTHING);
	}
	handle_keyboard(env);
	if (env->win == GAME)
		move(env);
}
