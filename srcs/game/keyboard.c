/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:44 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/02 19:02:08 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "game.h"
#include "libft.h"
#include "utils.h"

void	game_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_BACKSPACE])
	{
		env->win = MENU;
		//env->setup = 0; // To hide cursor again if user goes back into game
		SDL_ShowCursor(SDL_ENABLE);
	}
	if (env->input[SDL_SCANCODE_SPACE])
		jump(&env->cam);
	cam_height(env, env->input[SDL_SCANCODE_LSHIFT]);
}
