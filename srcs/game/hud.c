/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:32:06 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/10 02:54:11 by vivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "utils.h"

void	hud(t_env *env)
{
	if (env->data.hud.debug > 0)
		debug_hud(env);
	if (env->state == PLAY)
	{
		crosshair(env);
		lifebar(env);
		weapon(env);
	}
}
