/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_portal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:51:14 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/10/15 21:53:18 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		init_portals(t_editor **edit)
{
	(*edit)->portal_points[0].x = -1;
	(*edit)->portal_points[0].y = -1;
	(*edit)->portal_points[1].x = -1;
	(*edit)->portal_points[1].y = -1;
	(*edit)->which_sector = NULL;
	(*edit)->ab = NULL;
	(*edit)->cd = NULL;
}

int			compare_coordinates(t_vertex *point, t_vertex *a, t_vertex *b)
{
	if (point->x == a->x && point->y == a->y)
		return (1);
	if (point->x == b->x && point->y == b->y)
		return (1);
	return (0);
}

int			is_portal_closed(t_sector *sector, t_vertex *start, t_vertex *end)
{
	int			postion_closing_portal;
	t_vertex	*sector_vertex;
	t_vertex	*vertex;

	postion_closing_portal = 1;
	sector_vertex = sector->vertex;
	vertex = sector->vertex;
	if (vertex == NULL)
		return (-1);
	while (vertex)
	{
		if ((vertex->next == NULL) && ((vertex == start && sector_vertex == end) || (vertex == end && sector_vertex == end)))
			return (0);
		if ((vertex == start && vertex->next == end) || (vertex == end && vertex->next == start))
			return (postion_closing_portal);
		++postion_closing_portal;
		vertex = vertex->next;
	}
	return (-1);
}

void		save_vertex(t_editor **edit, t_sector *sector, t_vertex *first_point, t_vertex *last_point)
{
	int		from;
	int		dest;

	if ((*edit)->which_sector == NULL)
	{
		(*edit)->which_sector = sector;
		(*edit)->ab = first_point;
		(*edit)->cd = last_point;
	}
	else
	{
		if (compare_coordinates(first_point, (*edit)->ab, (*edit)->cd) == 0 || compare_coordinates(last_point, (*edit)->ab, (*edit)->cd) == 0)
			init_portals(edit);
		else
		{
			dest = is_portal_closed(sector, first_point, last_point);
			sector->is_portal[at] = (*edit)->which_sector->number;
			from = is_portal_closed((*edit)->which_sector, (*edit)->ab, (*edit)->cd);
			(*edit)->which_sector->is_portal[wc] = sector->number;
		}
		
	}
}

int			check_vertex(t_editor **edit, t_vertex *vertex, t_sector *sector)
{
	static int	n = 0;

	if (vertex->next == NULL)
	{
		if (intersects_count(*vertex, *(sector->vertex), (*edit)->portal_points[0], (*edit)->portal_points[1]))
		{
			save_vertex(edit, sector, vertex, sector->vertex);
			++n;
		}
	}
	else if (intersects_count(*vertex, *(vertex->next), (*edit)->portal_points[0], (*edit)->portal_points[1]))
	{
		save_vertex(edit, sector, vertex, vertex->next);
		n++;
	}
	if (n == 2)
	{
		n = 0;
		return (1);
	}
	return (0);
}

int			vertex_intersect(t_editor **edit, t_sector *sector)
{
	t_vertex	*vertex;

	vertex = sector->vertex;
	while (vertex)
	{
		if (check_vertex(edit, vertex, sector))
			return (1);
		vertex = vertex->next;
	}
	return (0);
}

void		create_portal(t_editor **edit, int x, int y)
{
	t_vertex	*point;
	t_sector	*sector;

	point = create_vertex(x, y);
	if ((*edit)->portal_points[0].x == -1)
		(*edit)->portal_points[0] = *point;
	else if ((*edit)->portal_points[1].x == -1)
	{
		(*edit)->portal_points[1] = *point;
		sector = (*edit)->sector;
		while (sector)
		{
			if (vertex_intersect(edit, sector))
			{
				init_portals(edit);
				break ;
			}
			sector = sector->next;
		}
		if (sector == NULL)
			init_portals(edit);
	}
}