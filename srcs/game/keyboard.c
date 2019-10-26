/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:44 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/27 00:48:50 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "game.h"
#include "libft.h"

void	game_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_BACKSPACE])
	{
		env->win = MENU;
		menu(env);
		return ;
	}

	// Movements
	// if (env->input[SDL_SCANCODE_W] || env->input[SDL_SCANCODE_A]
	// 	|| env->input[SDL_SCANCODE_S] || env->input[SDL_SCANCODE_D])
	// 	update_position(env, ...);

	// Camera rotations
	// if (env->input[SDL_SCANCODE_RIGHT] || env->input[SDL_SCANCODE_LEFT])
	// 	update_angle(env, &env->cam.angle);

	// Sprint
	// if (env->input[SDL_SCANCODE_LSHIFT])
	// 	.speed = 5.0;
	// else
	// 	.speed = 1.0;

	// Reset
	// if (env->input[SDL_SCANCODE_R])
	// 	reset_view(env);

	ft_bzero(env->sdl.screen->pixels, env->data.w_size);
	game(env);
}
