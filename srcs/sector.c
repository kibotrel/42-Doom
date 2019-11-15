/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:55:53 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/15 08:03:13 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

static int			count_vertex_in_sector(t_vertex *vertex)
{
	int			count;
	t_vertex	*vert;

	count = 0;
	vert = vertex;
	while (vert && count++)
		vert = vert->next;
	return (count);
}

static bool			is_sector_complete(t_vertex *first, t_vertex *last)
{
	if (!first || !last)
		return (false);
	if (first->x == last->x && first->y == last->y)
		return (true);
	return (false);
}

static t_sector		*get_last_sector(t_editor *editor)
{
	t_sector	*sect;

	if (!(editor->sector))
	{
		editor->sector = create_sector();
		return (editor->sector);
	}
	sect = editor->sector;
	while (sect->next)
		sect = sect->next;
	return (sect);
}
#include <stdio.h>
void	oui(t_sector *editor)
{
	t_vertex *vertex;

	vertex = editor->vertex;
	while (vertex)
	{
		printf("%i\n", vertex->x);
		vertex = vertex->next;
	}
}

void				place_sector(t_editor *editor, int x, int y)
{
	t_vertex	*new;
	t_sector	*sect;

	x = (x / editor->dist_grid) * editor->dist_grid;
	y = (y / editor->dist_grid) * editor->dist_grid;
	new = get_vertex(editor, x, y);
	sect = get_last_sector(editor);
	if (is_sector_complete(sect->vertex, new) == true)
	{
		sect->vertex_count = count_vertex_in_sector(sect->vertex);
		if (!(sect->is_portal = (int*)ft_memalloc(sizeof(int)
			* sect->vertex_count)))
			exit(1);
		sect->is_portal = ft_memset(sect->is_portal, -1, sizeof(int)
			* sect->vertex_count);
		if (sect->is_child != -1)
			sect->is_portal[1] = sect->is_child;
		sect->next = create_sector();
		editor->sect_is_closed = true;
		editor->last_vertex.x = -1;
		editor->last_vertex.y = -1;
	}
	else
	{
		add_vertex(&sect->vertex, x, y, false, &new->vertex_number);
		editor->sect_is_closed = false;
	}
	// oui(editor->sector);
}
