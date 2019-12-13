/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:04:00 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/12/13 15:20:45 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	move_in_sector(t_sector **sector, bool way)
{
	t_sector *tmp;

	if (!*sector)
		return ;
	tmp = *sector;
	if (way == true)
	{
		if (tmp->next->next)
			tmp = tmp->next;
	}
	else
	{
		if (tmp->prev)
			tmp = tmp->prev;
	}
	*sector = tmp;
}

void	next_display_sector(t_sdl *sdl, t_sector *sectors)
{
	t_sector	*sect;
	int			i;
	t_vertex	*vertex;

	sect = sectors;
	while (sect)
	{
		i = 0;
		vertex = sect->vertex;
		while (vertex && ++i)
		{
			draw_walls(sdl, sect, vertex, get_wall_color(sect, &i, false));
			vertex = vertex->next;
		}
		sect = sect->next;
	}
	sect = sectors;
	while (sect)
	{
		i = 0;
		vertex = sect->vertex;
		while (vertex && ++i)
		{
			draw_walls(sdl, sect, vertex, get_wall_color(sect, &i, false));
			vertex = vertex->next;
		}
		sect = sect->prev;
	}
}
