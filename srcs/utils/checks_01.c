/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:34:39 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/04 20:02:12 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	speed_check(t_env *env)
{
	if (SDL_GetModState() & KMOD_LCTRL)
		env->cam.speed *= 2;
}

void	check_tick(t_tick *tick, int8_t *flag, uint32_t offset)
{
	tick->new = SDL_GetTicks();
	if (tick->new > tick->old + offset)
		*flag *= -1;
	tick->old = tick->new;
}

char	*background_path(int w, int h)
{
	if (w == 1280 && h == 720)
		return ("assets/menu_720.bmp");
	else if (w == 1366 && h == 768)
		return ("assets/menu_768.bmp");
	else if (w == 1440 && h == 900)
		return ("assets/menu_900.bmp");
	else if (w == 1920 && h == 1080)
		return ("assets/menu_1080.bmp");
	else
		return ("");
}
