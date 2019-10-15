/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:23:52 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 21:21:48 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "clean.h"
#include "editor.h"

void	handle_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_ESCAPE])
		clean(env, NOTHING);
	if (env->win == GAME)
		game_keyboard(env);
	if (env->win == EDITOR)
		editor_keyboard(env);
}
