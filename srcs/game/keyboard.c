/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:44 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/27 13:58:47 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"

/*
** 	env->setup in Backspace to hide cursor again if user goes back into game
*/

void	game_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_BACKSPACE])
	{
		env->win = MENU;
		SDL_ShowCursor(SDL_ENABLE);
	}
	if (env->input[SDL_SCANCODE_F])
	{
		env->tick.fly.new = SDL_GetTicks();
		if (env->tick.fly.new > env->tick.fly.old + 160)
			env->cam.fly *= -1;
		env->tick.fly.old = env->tick.fly.new;
	}
	if (env->input[SDL_SCANCODE_SPACE])
		jump(env, &env->cam);
	cam_height(env, env->input[SDL_SCANCODE_LSHIFT]);
}
