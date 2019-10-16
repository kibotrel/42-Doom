/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:47:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/16 02:50:43 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "structs.h"

void	update_position(t_env *env, int angle, int speed)
{
	if (env->input[SDL_SCANCODE_W])
	{
		env->player.pos.x += (cos(ft_radians(angle)) * speed);
		env->player.pos.y += (sin(ft_radians(angle)) * speed);
	}
	if (env->input[SDL_SCANCODE_S])
	{

		env->player.pos.x -= (cos(ft_radians(angle)) * speed);
		env->player.pos.y -= (sin(ft_radians(angle)) * speed);
	}
	if (env->input[SDL_SCANCODE_A])
	{
		env->player.pos.x -= (cos(ft_radians(angle + 90)) * speed);
		env->player.pos.y -= (sin(ft_radians(angle + 90)) * speed);
	}
	if (env->input[SDL_SCANCODE_D])
	{
		env->player.pos.x += (cos(ft_radians(angle + 90)) * speed);
		env->player.pos.y += (sin(ft_radians(angle + 90)) * speed);
	}
}
