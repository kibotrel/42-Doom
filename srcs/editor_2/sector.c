/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:55:53 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/05 15:43:44 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static int			count_vertex_in_sector(t_vertex *vertex)
{
	int			count;
	t_vertex 	*vert;

	count = 0;
	vert = vertex;
	while (vert && count++)
		vert = vert->next;
	return (count);
}

static int			is_sector_complete(t_vertex *first, t_vertex *last)
{
	if (!first || !last)
		return (0);
	if (first->x == last->x && first->y == last->y)
		return (1);
	return (0);
}

static t_sector	*get_last_sector(t_editor *editor)
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

void	place_sector(t_editor *editor, int x, int y)
{
	t_vertex	*new;
	t_vertex	*in_new_sect;
	t_sector	*sect;

	new = get_vertex(editor, x, y);
	sect = get_last_sector(editor);
	if (is_sector_complete(sect->vertex, new))
	{
		sect->vertex_count = count_vertex_in_sector(sect->vertex);
		if (!(sect->is_portal = (int*)ft_memalloc(sizeof(int) * sect->vertex_count)))
			exit(1);
		sect->is_portal = ft_memset(sect->is_portal, -1, sizeof(int) * sect->vertex_count);
		if (sect->is_child != -1)
			sect->is_portal[1] = sect->is_child;
		sect->next = new_sector();
		editor->sect_is_closed = 1;
		editor->last_vertex.x = -1;
		editor->last_vertex.y = -1;
	}
	else
	{
		add_vertex(&sect->vertex, new, 0);
		editor->sect_is_closed = 0;
	}
}