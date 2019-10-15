/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:21:13 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 19:26:58 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "clean.h"

void	selector(t_env *env)
{
	if (env->win == MENU)
		menu(env);
	else if (env->win == GAME)
		game(env);
	else if (env->win == EDITOR)
		editor(env);
	else if (env->win == SETTINGS)
		settings(env);
	else if (env->win == QUIT)
		clean(env, NOTHING);
}
