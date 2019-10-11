/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:26:14 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/11 13:13:44 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "doom.h"

void	editor_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_BACKSPACE])
	{
		env->win = MENU;
		menu(env);
	}
}
