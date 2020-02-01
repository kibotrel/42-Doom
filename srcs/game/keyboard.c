/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:44 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/31 23:00:17 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"

//
// 	env->setup in Backspace to hide cursor again if user goes back into game
//

void	game_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_BACKSPACE])
	{
		env->win = MENU;
		SDL_ShowCursor(SDL_ENABLE);
	}
	fov_update(env);
	if (env->win == GAME && env->input[SDL_SCANCODE_SPACE])
		jump(env, &env->cam);
	cam_height(env, env->input[SDL_SCANCODE_LSHIFT]);
	if (env->win == GAME && env->input[SDL_SCANCODE_GRAVE])
		check_tick(&env->tick.debug, &env->data.hud.debug, 160);
	if (env->win == GAME && env->input[SDL_SCANCODE_F])
		fly(env);
}
