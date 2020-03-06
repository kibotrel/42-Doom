/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:36:07 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 09:59:22 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "editor.h"

void	editor(t_env *env, int ac, char **av)
{
	int	win_pos;

	if (!env->setup)
	{
		if (ac != 2)
			env->editor.map_path = "editor_map.data";
		else
			env->editor.map_path = av[1];
		win_pos = SDL_WINDOWPOS_CENTERED;
		SDL_SetWindowTitle(env->sdl.win, TITLE_EDITOR);
		SDL_SetWindowSize(env->sdl.win, 1780, 820);
		if (!(env->sdl.screen = SDL_GetWindowSurface(env->sdl.win)))
			clean(env, E_SDL_WINSURF);
		SDL_SetWindowPosition(env->sdl.win, win_pos, win_pos);
		env->setup = 1;
	}
	events(&env->editor, env);
}
