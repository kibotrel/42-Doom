/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:23:52 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/27 15:11:32 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "clean.h"
#include "utils.h"
#include "editor.h"

void	handle_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_ESCAPE])
		clean(env, NOTHING);
	if (env->win == GAME)
		game_keyboard(env);
	else if (env->win == EDITOR)
		editor_keyboard(env, &env->editor);
}
