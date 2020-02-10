/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:26:14 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 13:01:52 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "core.h"

void	editor_keyboard(t_env *env, t_editor *edit)
{
	if (env->input[SDL_SCANCODE_BACKSPACE])
	{
		if (is_saved(edit) == true)
		{
			SDL_SetWindowSize(env->sdl.win, env->w, env->h);
			env->sdl.screen = SDL_GetWindowSurface(env->sdl.win);
			env->win = MENU;
			env->setup = 0;
		}
	}
	if(env->input[SDL_SCANCODE_DELETE])
		clear_editor(edit, env);
	if (env->input[SDL_SCANCODE_END])
		edit->grid = !edit->grid;
	if (env->input[SDL_SCANCODE_ESCAPE])
		if (is_saved(edit) == true)
			clear_editor(edit, env);
	if (env->input[SDL_SCANCODE_RETURN])
		create_map(edit);
	if (edit->sect_is_closed == true)
		blank_menu(env->sdl.screen, edit->sett, edit, edit->presets, env);
}
