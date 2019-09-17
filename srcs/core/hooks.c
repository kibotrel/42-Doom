/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:45:38 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/17 18:47:26 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "env.h"
#include "doom.h"

void	hooks(t_env *env, t_sdl *sdl)
{
	while (env->run)
	{
		while (SDL_PollEvent(&sdl->event))
		{
			if (sdl->event.type == SDL_QUIT)
				env->run = 0;
			else if (sdl->event.type == SDL_KEYDOWN)
				handle_keyboard(env, sdl);
			else if (sdl->event.type == SDL_MOUSEBUTTONDOWN || sdl->event.type == SDL_MOUSEMOTION)
				handle_mouse(env, sdl);
		}
		if (SDL_UpdateWindowSurface(sdl->win))
		{
			env->run = 0;
			env->status = E_SDL_UPDATE;
		}
	}
	clean_sdl(sdl);
	if (env->status)
		ft_print_error(env->error[env->status], env->status);
}
