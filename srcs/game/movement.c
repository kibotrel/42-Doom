/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:47:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/14 17:25:04 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "SDL.h"
#include "libft.h"
#include "doom.h"

void	update_position(t_env *env)
{
	if (env->input[SDL_SCANCODE_W])
	{
		env->player.position.x += (cos(ft_radians(env->player.angle)) * env->player.speed);
		env->player.position.y += (sin(ft_radians(env->player.angle)) * env->player.speed);
	}
	if (env->input[SDL_SCANCODE_S])
	{

		env->player.position.x -= (cos(ft_radians(env->player.angle)) * env->player.speed);
		env->player.position.y -= (sin(ft_radians(env->player.angle)) * env->player.speed);
	}
	if (env->input[SDL_SCANCODE_A])
	{
		env->player.position.x += (cos(ft_radians(env->player.angle + 90)) * env->player.speed);
		env->player.position.y -= (sin(ft_radians(env->player.angle + 90)) * env->player.speed);
	}
	if (env->input[SDL_SCANCODE_D])
	{
		env->player.position.x -= (cos(ft_radians(env->player.angle + 90)) * env->player.speed);
		env->player.position.y += (sin(ft_radians(env->player.angle + 90)) * env->player.speed);
	}
}
