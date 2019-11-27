/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:01:10 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/27 10:38:14 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static int	is_left(t_vertex p0, t_vertex p1, t_vertex p2)
{
	int		value;

	value = (p1.y - p0.y) * (p2.x - p1.x) - (p1.x - p0.x) * (p2.y - p1.y);
	/*if (value == 0)
		return (0);
	 else */if (value > 0)
		return (1);
	else
		return (2);
}

int			intersects_count(t_vertex v1, t_vertex v2, t_vertex p1, t_vertex p2)
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

static int	inters(t_vertex *prev_vertex, t_vertex point, t_vertex extreme)
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

#include <stdio.h>
void	oui(t_sector *tmp)
{
	t_sector *sect;

	sect = tmp;
	while (sect)
	{
		printf("%d\n", sect->sector_number);
		sect = sect->next;
	}
}

int			is_in_sector(t_editor *edit, t_vertex point)
{
	int			intersects;
	t_sector	*sect;
	t_vertex	*vertex;
	t_vertex	extreme;
	t_sector	*tmp;

	sect = edit->sector;
	tmp = NULL;
	while (sect)
	{
		extreme.x = EDIT_W;
		extreme.y = point.y;
		vertex = sect->vertex;
		intersects = inters(vertex, point, extreme);
		if (intersects % 2 == 1)
			add_tmp_sector(sect, &tmp);
		sect = sect->next;
	}
	if (!tmp)
		return (-1);
	else
		return (check_which_sector(tmp));
}

bool	is_in_this_sector(t_vertex point, t_sector *sector)
{
	int			intersects;
	t_vertex	*vertex;
	t_vertex	extreme;

	extreme.x = EDIT_W;
	extreme.y = point.y;
	vertex = sector->vertex;
	intersects = inters(vertex, point, extreme);
	if (intersects % 2 == 1)
		return (true);
	return (false);
}