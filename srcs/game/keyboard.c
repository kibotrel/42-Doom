/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:44 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 21:28:57 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
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
	if (env->input[SDL_SCANCODE_W] || env->input[SDL_SCANCODE_A]
		|| env->input[SDL_SCANCODE_S] || env->input[SDL_SCANCODE_D])
		update_position(env);
	if (env->input[SDL_SCANCODE_RIGHT] || env->input[SDL_SCANCODE_LEFT])
		update_angle(env);
	ft_bzero(env->sdl.screen->pixels, env->sdl.screen->h * env->sdl.screen->pitch);
	if (env->input[SDL_SCANCODE_LSHIFT])
		env->player.speed = 5.0;
	else
		env->player.speed = 1.0;
	if (env->input[SDL_SCANCODE_R])
	{
		env->player.position.x = env->w / 2;
		env->player.position.y = env->h / 2;
		env->player.angle = 0;
	}
	game(env);
}
