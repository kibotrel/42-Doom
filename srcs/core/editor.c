/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:36:07 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 13:33:06 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"
#include "editor.h"

void	editor(t_env *env)
{
	int	win_pos;

	if (!env->setup)
	{
		win_pos = SDL_WINDOWPOS_CENTERED;
		SDL_SetWindowTitle(env->sdl.win, TITLE_EDITOR);
		SDL_SetWindowSize(env->sdl.win, 1780, 720);
		env->sdl.screen = SDL_GetWindowSurface(env->sdl.win);
		SDL_SetWindowPosition(env->sdl.win, win_pos, win_pos);
		env->setup = 1;
	}

	events(&env->editor, env);
}
