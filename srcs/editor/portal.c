/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:15:06 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/24 12:03:32 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static int	is_portal_close(t_sector *sector, t_vertex *start, t_vertex *end)
{
	int			postion_closing_portal;
	t_vertex	*sector_vertex;
	t_vertex	*vertex;

	postion_closing_portal = 0;
	sector_vertex = sector->vertex;
	vertex = sector->vertex;
	if (vertex == NULL)
		return (-1);
	while (vertex)
	{
		if ((vertex->next == NULL) && ((vertex == start && sector_vertex == end)
			|| (vertex == end && sector_vertex == end)))
			return (sector->vertex_count - 1);
		if ((vertex == start && vertex->next == end)
			|| (vertex == end && vertex->next == start))
			return (postion_closing_portal);
		++postion_closing_portal;
		vertex = vertex->next;
	}
	return (-1);
}

static void	save_vertex(t_editor *editor, t_sector *sector,
		t_vertex *first_point, t_vertex *last_point)
{
	int			from;
	int			dest;

	if (editor->which_sector == NULL)
	{
		editor->which_sector = sector;
		editor->ab = first_point;
		editor->cd = last_point;
	}
	else
	{
		if (compare_coordinates(first_point, editor->ab, editor->cd) == 0
			|| compare_coordinates(last_point, editor->ab, editor->cd) == 0)
			init_portals(editor);
		else
		{
			dest = is_portal_close(sector, first_point, last_point);
			sector->is_portal[dest] = editor->which_sector->sector_number;
			from = is_portal_close(editor->which_sector, editor->ab,
				editor->cd);
			editor->which_sector->is_portal[from] = sector->sector_number;
			add_portal(&editor->portals, *first_point, *last_point, editor);
			add_portal(&sector->portal, *first_point, *last_point, editor);
			add_portal(&editor->which_sector->portal, *last_point, *first_point,
				editor);
		}
	}
}

static int	check_vertex(t_editor *editor, t_vertex *vertex, t_sector *sector)
{
	if (vertex->next == NULL)
	{
		if (intersects_count(*vertex, *(sector->vertex),
			editor->portal_points[0], editor->portal_points[1]))
		{
			save_vertex(editor, sector, vertex, sector->vertex);
			++editor->count.portal;
		}
	}
	else if (intersects_count(*vertex, *(vertex->next),
		editor->portal_points[0], editor->portal_points[1]))
	{
		save_vertex(editor, sector, vertex, vertex->next);
		++editor->count.portal;
	}
	if (editor->count.portal == 2)
	{
		editor->count.portal = 0;
		return (1);
	}
	return (0);
}

static int	vertex_intersect(t_editor *editor, t_sector *sector)
{
	t_vertex	*vertex;

	vertex = sector->vertex;
	while (vertex)
	{
		if (check_vertex(editor, vertex, sector))
			return (1);
		vertex = vertex->next;
	}
	return (0);
}

void		place_portal(t_editor *editor, int x, int y)
{
	t_vertex	*point;
	t_sector	*sector;

	if (count_sector(editor->sector) < 2)
		return ;
	point = create_vertex(init_vertex(x, y), editor);
	if (editor->portal_points[0].x == -1)
		editor->portal_points[0] = *point;
	else if (editor->portal_points[1].x == -1)
	{
		editor->portal_points[1] = *point;
		sector = editor->sector;
		while (sector->prev)
			sector = sector->prev;
		while (sector)
		{
			if (vertex_intersect(editor, sector))
			{
				init_portals(editor);
				break ;
			}
			sector = sector->next;
		}
		if (sector == NULL)
			init_portals(editor);
	}
	free(point);
}
