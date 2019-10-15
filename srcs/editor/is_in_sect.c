/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_sect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:19:25 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/10/15 14:31:55 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		is_left(t_vertex p0, t_vertex p1, t_vertex p2)
{
	int		value;

	value = (p1.y - p0.y) * (p2.x - p1.x) - (p1.x - p0.x) * (p2.y - p1.y);
	if (value == 0)
		return (0);
	else if (value > 0)
		return (1);
	else
		return (2);
}

int		intersects_count(t_vertex v1, t_vertex v2, t_vertex p1, t_vertex p2)
{
	int		tab[4];

	tab[0] = is_left(v1, v2, p1);
	tab[1] = is_left(v1, v2, p2);
	tab[2] = is_left(p1, p2, v1);
	tab[3] = is_left(p1, p2, v2);
	if (tab[0] != tab[1] && tab[2] != tab[3])
		return (1);
	return (0);	
}

int		inters(t_vertex *prev_vertex, t_vertex point, t_vertex extreme)
{
	int			intersections;
	t_vertex	*vertex;

	intersections = 0;
	vertex = prev_vertex;
	while (vertex)
	{
		if (vertex->next == NULL)
		{
			if (intersects_count(*vertex, *(prev_vertex), point, extreme))
				++intersections;
		}
		else if (intersects_count(*vertex, *(vertex->next), point, extreme))
			++intersections;
		vertex = vertex->next;
	}
	return (intersections);
}

int		is_in_sector(t_editor *edit, t_vertex point)
{
	int			intersects;
	t_sector		*sect;
	t_vertex	*vertex;
	t_vertex	extreme;

	sect = edit->sector;
	while (sect)
	{
		extreme.x = WIN_W;
		extreme.y = point.y;
		vertex = sect->vertex;
		intersects = inters(vertex, point, extreme);
		if (intersects % 2 == 1)
			return (sect->number);
		sect = sect->next;
	}
	return (-1);
}