/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:21:13 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 10:44:00 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "clean.h"

void	selector(t_env *env)
{
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
