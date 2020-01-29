/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:21:13 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 12:00:20 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "clean.h"

void	selector(t_env *env)
{
	env->tick.frame.old = env->tick.frame.new;
	if (env->win == MENU)
		menu(env);
	else if (env->win == GAME)
	{
		SDL_WarpMouseInWindow(env->sdl.win, env->w / 2, env->h / 2);
		game(env);
	}
	else if (env->win == EDITOR)
		main_editor(env);
	else if (env->win == SETTINGS)
		settings(env);
	else if (env->win == QUIT)
		clean(env, NOTHING);
}
