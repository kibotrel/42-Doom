/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 07:59:57 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 10:14:37 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"

void	game_click(t_env *env, int x, int y)
{
	(void)x;
	(void)y;
	if (!env->data.shot && env->data.ammos)
	{
		env->tick.shot.old = SDL_GetTicks();
		env->data.shot = 1;
		env->audio.fire = 1;
		if (env->setting.mode != EASY)
			env->data.ammos--;
	}
}
