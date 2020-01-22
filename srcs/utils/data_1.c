/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:34:24 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/14 14:05:19 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
