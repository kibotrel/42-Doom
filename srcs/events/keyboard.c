/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:23:52 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/05 08:58:09 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "clean.h"
#include "utils.h"
#include "editor.h"
#include "settings.h"

void	handle_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_ESCAPE])
		clean(env, NOTHING);
	if (env->win == GAME)
		game_keyboard(env);
	else if (env->win == EDITOR)
		editor_keyboard(env, &env->editor, &env->tick.editor);
	else if (env->win == SETTINGS)
		settings_keyboard(env);
}
