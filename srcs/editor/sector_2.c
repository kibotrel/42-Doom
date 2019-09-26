/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 09:46:53 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/09/26 09:47:41 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int			get_wall_color(t_sector *sect, int *i)
{
	int 	color;

	if (sect->is_portal != NULL && *i >= sect->num_vertex)
		*i = 0;
	if (sect->is_portal != NULL && sect->is_portal[*i] != -1)
		color = 0x00ff00;
	else
		color = 0x0000ff;
	return (color);
}

int			is_sector_complete(t_vertex *first, t_vertex *last)
{
	if (!first || !last)
		return (0);
	if (first->x == last->x && first->y == last->y)
		return (1);
	return (0);
}