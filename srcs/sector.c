/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:55:53 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/14 10:04:38 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

static int		count_vertex_in_sector(t_vertex *vertex)
{
	int			count;
	t_vertex	*vert;

	count = 0;
	vert = vertex;
	while (vert)
	{
		vert = vert->next;
		++count;
	}
	return (count);
}

static bool		is_sector_complete(t_vertex *first, t_vertex *last)
{
	if (!first || !last)
		return (false);
	if (first->x == last->x && first->y == last->y)
		return (true);
	return (false);
}

static t_sector	*get_last_sector(t_editor *editor)
{
	t_sector	*sect;

	if (!(editor->sector))
	{
		editor->sector = create_sector(editor);
		return (editor->sector);
	}
	sect = editor->sector;
	while (sect->next)
		sect = sect->next;
	return (sect);
}

void			next_place_sector(t_editor *edit, t_sector *sect)
{
	sect->vertex_count = count_vertex_in_sector(sect->vertex);
	if (!(sect->is_portal = (int*)ft_memalloc(sizeof(int)
					* sect->vertex_count)))
		clean(edit);
	sect->is_portal = ft_memset(sect->is_portal, -1, sizeof(int)
			* sect->vertex_count);
	if (!(sect->portal_type = (int*)ft_memalloc(sizeof(int)
			* sect->vertex_count)))
		clean(edit);
	sect->portal_type = ft_memset(sect->portal_type, -1, sizeof(int)
			* sect->vertex_count);
	sect->next = create_sector(edit);
	sect->next->prev = sect;
	edit->sect_is_closed = true;
	edit->last_vertex = init_vertex(-1, -1);
}

void			place_sector(t_editor *editor, int x, int y)
{
	t_vertex	*new;
	t_sector	*sect;

	x = (x / editor->dist_grid) * editor->dist_grid;
	y = (y / editor->dist_grid) * editor->dist_grid;
	new = get_vertex(editor, x, y);
	sect = get_last_sector(editor);
	if (is_sector_complete(sect->vertex, new) == true)
		next_place_sector(editor, sect);
	else
	{
		add_vertex(&sect->vertex, init_vertex(x, y), false, editor);
		editor->sect_is_closed = false;
	}
}
