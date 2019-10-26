/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:47:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/27 00:45:09 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "structs.h"

void	update_position(t_env *env, double angle, double speed)
{
	// Need to add where is x and y
	if (env->input[SDL_SCANCODE_W])
	{
		x += (cos(ft_radians(angle)) * speed);
		y += (sin(ft_radians(angle)) * speed);
	}
	if (env->input[SDL_SCANCODE_S])
	{
		x -= (cos(ft_radians(angle)) * speed);
		y -= (sin(ft_radians(angle)) * speed);
	}
	if (env->input[SDL_SCANCODE_A])
	{
		x -= (cos(ft_radians(angle + 90)) * speed);
		y -= (sin(ft_radians(angle + 90)) * speed);
	}
	if (env->input[SDL_SCANCODE_D])
	{
		x += (cos(ft_radians(angle + 90)) * speed);
		y += (sin(ft_radians(angle + 90)) * speed);
	}
}
