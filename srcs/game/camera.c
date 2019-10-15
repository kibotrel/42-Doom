/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:21:04 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 21:27:37 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	update_angle(t_env *env)
{
	if (env->input[SDL_SCANCODE_RIGHT])
		env->player.angle -= 2;
	if (env->input[SDL_SCANCODE_LEFT])
		env->player.angle += 2;
}
