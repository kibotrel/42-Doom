/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:45:38 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/12 10:27:35 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"
#include "game.h"
#include "clean.h"
#include "utils.h"
#include "events.h"

void	global_hooks(t_env *env, t_sdl *sdl)
{
	while (SDL_PollEvent(&sdl->event))
	{
		if (sdl->event.type == SDL_QUIT)
			clean(env, NOTHING);
		if (env->sdl.event.type == SDL_KEYDOWN)
		{
			//printf("%d\n", sdl->event.key.keysym.scancode);
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
}

void	game_hooks(t_env *env)
{
	SDL_Event ev;
	int x = 0,y = 0;
	while(SDL_PollEvent(&ev))
		switch(ev.type)
		{
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				switch(ev.key.keysym.scancode)
				{
					case SDL_SCANCODE_W: env->input[SDL_SCANCODE_W] = ev.type==SDL_KEYDOWN; break;
					case SDL_SCANCODE_S: env->input[SDL_SCANCODE_S] = ev.type==SDL_KEYDOWN; break;
					case SDL_SCANCODE_A: env->input[SDL_SCANCODE_A] = ev.type==SDL_KEYDOWN; break;
					case SDL_SCANCODE_D: env->input[SDL_SCANCODE_D] = ev.type==SDL_KEYDOWN; break;
					case SDL_SCANCODE_BACKSPACE: {env->win = MENU; SDL_ShowCursor(SDL_ENABLE); break;}
					case SDL_SCANCODE_ESCAPE: clean(env, NOTHING);
					default: break;
				}
				break;
			case SDL_MOUSEMOTION: {x -= ((env->w / 2 - ev.motion.x) / 8); y += ((env->h / 2 - ev.motion.y) / 8); break;}
			case SDL_QUIT: clean(env, NOTHING);
		}
	env->cam.angle += x * 0.03f;
	env->cam.gap = bound(env->cam.gap - y * 0.05, -10, 10) - env->cam.v.z * 0.5;
	move(env, 0, 0);
	float move_vec[2] = {0.f, 0.f};
	// printf("%f, %f\n", env->cam.cos, env->cam.sin);
	if (env->input[SDL_SCANCODE_W])
	{
		move_vec[0] += env->cam.cos * 0.2f;
		move_vec[1] += env->cam.sin * 0.2f;
	}
	if (env->input[SDL_SCANCODE_S])
	{
		move_vec[0] -= env->cam.cos * 0.2f;
		move_vec[1] -= env->cam.sin * 0.2f;
	}
	if (env->input[SDL_SCANCODE_A])
	{
		move_vec[0] += env->cam.sin * 0.2f;
		move_vec[1] -= env->cam.cos * 0.2f;
	}
	if (env->input[SDL_SCANCODE_D])
	{
		move_vec[0] -= env->cam.sin * 0.2f;
		move_vec[1] += env->cam.cos * 0.2f;
	}
	int pushing = env->input[SDL_SCANCODE_W] || env->input[SDL_SCANCODE_S] || env->input[SDL_SCANCODE_A] || env->input[SDL_SCANCODE_D];
	float acceleration = pushing ? 0.4 : 0.2;

	env->cam.v.x = env->cam.v.x * (1 - acceleration) + move_vec[0] * acceleration;
	env->cam.v.y = env->cam.v.y * (1 - acceleration) + move_vec[1] * acceleration;
	if (pushing)
		env->cam.move = 1;
}
