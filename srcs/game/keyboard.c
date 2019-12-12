/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:44 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/12 10:50:17 by demonwaves       ###   ########.fr       */
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
}
