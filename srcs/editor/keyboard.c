/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 09:18:19 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/06 10:09:29 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "editor.h"

static int		check_button(t_tick *tick, uint32_t offset)
{
	uint32_t	time;

	time = tick->old;
	tick->new = SDL_GetTicks();
	tick->old = tick->new;
	if (tick->new >= time + offset)
		return (1);
	return (0);
}

void			editor_keyboard(t_env *env, t_editor *edit, t_tick *button)
{
	int		win_pos;

	if (env->input[SDL_SCANCODE_BACKSPACE] && edit->sect_is_closed == true)
	{
		win_pos = SDL_WINDOWPOS_CENTERED;
		SDL_SetWindowSize(env->sdl.win, env->w, env->h);
		env->sdl.screen = SDL_GetWindowSurface(env->sdl.win);
		SDL_SetWindowPosition(env->sdl.win, win_pos, win_pos);
		env->win = MENU;
		env->setup = 0;
	}
	else if (env->input[SDL_SCANCODE_END])
		check_tick(&env->tick.editor, &edit->grid, 160);
	else if (env->input[SDL_SCANCODE_P])
		check_tick(&env->tick.editor, &edit->display_portal, 160);
	else if (env->input[SDL_SCANCODE_SPACE])
	{
		if (check_button(button, 160))
			delete_sector_in_progress(&env->editor.sector, &env->editor);
	}
}
