/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:44 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/11 13:13:41 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "doom.h"

void	game_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_BACKSPACE])
	{
		env->win = MENU;
		menu(env);
	}
	else if (env->input[SDL_SCANCODE_W] || env->input[SDL_SCANCODE_A]
		|| env->input[SDL_SCANCODE_S] || env->input[SDL_SCANCODE_D])
		update_position(env);
}
