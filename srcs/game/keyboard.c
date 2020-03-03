/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:44 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/03 13:40:53 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "clean.h"
#include "utils.h"

void	game_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_BACKSPACE])
	{
		env->setup = 0;
		env->win = MENU;
		free_map(env);
		SDL_ShowCursor(SDL_ENABLE);
		return ;
	}
	fov_update(env);
	if (env->input[SDL_SCANCODE_SPACE])
		jump(env, &env->cam);
	env->setup ? cam_height(env, env->input[SDL_SCANCODE_LSHIFT]) : 0;
	if (env->input[SDL_SCANCODE_GRAVE])
		toggle_infos(env);
	if (env->input[SDL_SCANCODE_F])
		fly(env);
	if (env->input[SDL_SCANCODE_R])
		reload(env);
	if (env->input[SDL_SCANCODE_F1])
		toggle_hud(env);
}
