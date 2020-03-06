/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:32:06 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 10:17:36 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"

void	toggle_hud(t_env *env)
{
	env->tick.hud.new = SDL_GetTicks();
	if (env->tick.hud.new > env->tick.hud.old + 160)
	{
		if (env->state != SCREENSHOT)
		{
			env->data.hud.last_display = env->state;
			env->state = SCREENSHOT;
		}
		else
			env->state = env->data.hud.last_display;
	}
	env->tick.hud.old = env->tick.hud.new;
}

void	toggle_infos(t_env *env)
{
	env->tick.debug.new = SDL_GetTicks();
	if (env->tick.debug.new > env->tick.debug.old + 160)
	{
		if (env->state == DEBUG)
			env->state = PLAY;
		else if (env->state == PLAY)
			env->state = DEBUG;
	}
	env->tick.debug.old = env->tick.debug.new;
}

void	hud(t_env *env)
{
	if (env->state <= DEBUG)
	{
		if (env->state == DEBUG)
			debug_hud(env);
		crosshair(env);
		lifebar(env);
		weapon(env);
		purse(env);
	}
}
