/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:23:52 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/11 13:12:28 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "doom.h"

void	handle_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_ESCAPE])
		clean(env, NOTHING);
	if (env->win == GAME)
		game_keyboard(env);
	if (env->win == EDITOR)
		editor_keyboard(env);
}
