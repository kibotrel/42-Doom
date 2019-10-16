/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:21:04 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/16 06:01:54 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	reset_view(t_env *env)
{
	env->player.pos = env->cam.pos;
	env->cam.angle = 0;
}

void	update_angle(t_env *env, double *angle)
{
	if (env->input[SDL_SCANCODE_RIGHT])
		*angle = (*angle < 0.125 ? 359.975 : *angle - 0.125);
	if (env->input[SDL_SCANCODE_LEFT])
		*angle = (*angle > 359.875 ? 0.125 : *angle + 0.125);
}
