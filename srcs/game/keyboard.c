/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:44 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 00:05:47 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "clean.h"
#include "utils.h"
#include "libft.h"

void	game_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_BACKSPACE] && env->setup)
	{
		env->setup = 0;
		env->win = MENU;
		free_map(env);
		pthread_join(env->sound, NULL);
		SDL_ShowCursor(SDL_ENABLE);
		return ;
	}
	if (env->input[SDL_SCANCODE_SPACE])
		jump(env, &env->cam);
	env->setup ? cam_height(env, env->input[SDL_SCANCODE_LSHIFT]) : 0;
	if (env->input[SDL_SCANCODE_GRAVE])
		toggle_infos(env);
	if (env->input[SDL_SCANCODE_F] && !env->tuto && env->setting.fly_mode)
		fly(env);
	if (env->input[SDL_SCANCODE_R])
		reload(env);
	if (env->input[SDL_SCANCODE_F1])
		toggle_hud(env);
}
