/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:34:24 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/23 20:16:15 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"

void		fps_counter(t_env *env)
{
	env->tick.frame.new = SDL_GetTicks();
	env->tick.fps.new = env->tick.frame.new;
	if (env->tick.fps.new > env->tick.fps.old + 250)
	{
		env->data.fps = 1000 / (env->tick.frame.new - env->tick.frame.old);
		env->tick.fps.old = env->tick.fps.new;
	}
}

void		side_infos(t_game *var)
{
	var->nearz = 0.0001;
	var->farz = 5;
	var->nearside = 0.00001;
	var->farside = 20;
}

t_item		item(uint32_t sector, uint32_t min, uint32_t max)
{
	t_item		item;

	item.sector = sector;
	item.min = min;
	item.max = max;
	return (item);
}

t_height	lim(int y1, int y2)
{
	t_height	h;

	h.top = y1;
	h.bottom = y2;
	return (h);
}

t_palette	flat(int top, int middle, int bottom)
{
	t_palette	c;

	c.top = top;
	c.middle = middle;
	c.bottom = bottom;
	return (c);
}
