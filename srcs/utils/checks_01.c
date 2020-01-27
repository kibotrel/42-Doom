/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:34:39 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/27 14:08:01 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	speed_check(t_env *env)
{
	if (SDL_GetModState() & KMOD_LCTRL)
		env->cam.speed *= 2;
}

void	check_tick(t_tick *tick, int8_t *flag, uint32_t  offset)
{
	tick->new = SDL_GetTicks();
	if (tick->new > tick->old + offset)
		*flag *= -1;
	tick->old = tick->new;
}
