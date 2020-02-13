/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:21:13 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/13 12:00:00 by reda-con         ###   ########.fr       */
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
		editor(env);
	else if (env->win == SETTINGS)
		settings(env);
	else if (env->win == QUIT)
		clean(env, NOTHING);
}
