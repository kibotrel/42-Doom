/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:44 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/26 15:05:44 by lojesu           ###   ########.fr       */
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
		env->setup = 0;
		env->win = MENU;
		SDL_ShowCursor(SDL_ENABLE);
		return ;
	}
	if (env->input[SDL_SCANCODE_SPACE])
		jump(env, &env->cam);
	env->setup ? cam_height(env, env->input[SDL_SCANCODE_LSHIFT]) : 0;
	env->old_st_fl = env->st_fl;
	if (env->input[SDL_SCANCODE_E])
		check_tick(&env->tick.sector_triger, &env->st_fl, 160);
	if (env->input[SDL_SCANCODE_GRAVE])
		toggle_infos(env);
	if (env->input[SDL_SCANCODE_F])
		fly(env);
	if (env->input[SDL_SCANCODE_R])
		reload(env);
	if (env->input[SDL_SCANCODE_F1])
		toggle_hud(env);
}
