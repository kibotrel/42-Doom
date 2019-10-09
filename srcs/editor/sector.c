/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:12:52 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/10/09 08:49:59 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "editor.h"

void		print_sector(t_editor *edit)
{
	int			i;
	int 		color;
	t_sector	*sect;
	t_vertex	*vertex;

	sect = edit->sector;
	while (sect)
	{
		i = 0;
		vertex = sect->vertex;
		while (vertex && ++i)
		{
			color = get_wall_color(sect, &i);
			draw_walls(edit->sdl, sect, vertex, color);
			vertex = vertex->next;
		}
		sect = sect->next;
	}
}

int			count_vertex_in_sector(t_vertex *vertex)
{
	int			count;
	t_vertex 	*vert;

	count = 0;
	vert = vertex;
	while (vert)
	{
		count++;
		vert = vert->next;
	}
	return (count);
}

t_sector	*new_sector(void)
{
	static int	sector_num = 0;
	t_sector	*sect;

	sect = NULL;
	if (!(sect = (t_sector*)ft_memalloc(sizeof(t_sector))))
		exit(0);
	if (sect)
	{
		sect->number = sector_num++;
		sect->is_child = -1;
		sect->h_ceil = 20;
		sect->h_floor = 0;
	}
	return (sect);
}

t_sector	*get_last_sector(t_editor **edit)
{
	t_sector	*sect;

	if (!((*edit)->sector))
	{
		(*edit)->sector = new_sector();
		return ((*edit)->sector);
	}
	sect = (*edit)->sector;
	while (sect->next)
		sect = sect->next;
	return (sect);
}

void		get_sector(t_editor **edit, int x, int y)
{
	t_vertex		*new;
	t_vertex		*in_new_sect;
	t_sector		*sect;

	new = get_vertex(edit, x, y);
	sect = get_last_sector(edit);
	if (is_sector_complete(sect->vertex, new))
	{
		sect->num_vertex = count_vertex_in_sector(sect->vertex);
		sect->is_portal = (int*)ft_memalloc(sizeof(int) * sect->num_vertex);
		sect->is_portal = ft_memset(sect->is_portal, -1, sizeof(int) * sect->num_vertex);
		if (sect->is_child != -1)
			sect->is_portal[1] = sect->is_child;
		sect->next = new_sector();
		(*edit)->sect_is_closed = 1;
		(*edit)->last_vertex = create_vertex(-1, -1);
	}
	else
	{
		in_new_sect = (t_vertex*)ft_memalloc(sizeof(t_vertex));
		in_new_sect = ft_memcpy(in_new_sect, new, sizeof(new));
		add_vertex(&sect->vertex, in_new_sect, 0);
		(*edit)->sect_is_closed = 0;
	}
	
}