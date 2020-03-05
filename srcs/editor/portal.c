/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:39:52 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/04 09:54:55 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static int	is_portal_close(t_ed_sector *sector, t_vertex *start, t_vertex *end)
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

static void	save_vertex_part2(t_env *env, t_ed_sector *sector,
		t_vertex *first, t_vertex *last)
{
	int		from;
	int		dest;

	if (compare_coordinates(first, env->editor.ab, env->editor.cd) == 0
		|| compare_coordinates(last, env->editor.ab, env->editor.cd) == 0)
		init_portals(&env->editor);
	else
	{
		dest = is_portal_close(sector, first, last);
		from = is_portal_close(env->editor.which_sector, env->editor.ab,
			env->editor.cd);
		if (sector->is_portal[dest] == -1)
		{
			sector->is_portal[dest] = env->editor.which_sector->sector_number;
			env->editor.which_sector->is_portal[from] = sector->sector_number;
			add_portal(&env->editor.portals, *first, *last, env);
		}
		else
		{
			sector->is_portal[dest] = -1;
			env->editor.which_sector->is_portal[from] = -1;
			delete_portal(&env->editor.portals, *first, *last);
		}
	}
}

static void	save_vertex(t_env *env, t_ed_sector *sector,
		t_vertex *first, t_vertex *last)
{
	if (env->editor.which_sector == NULL)
	{
		env->editor.which_sector = sector;
		env->editor.ab = first;
		env->editor.cd = last;
	}
	else
		save_vertex_part2(env, sector, first, last);
}

static int	check_vertex(t_env *env, t_vertex *vertex, t_ed_sector *sector)
{
	if (vertex->next == NULL)
	{
		if (intersects_count(*vertex, *(sector->vertex),
			env->editor.portal_points[0], env->editor.portal_points[1]))
		{
			save_vertex(env, sector, vertex, sector->vertex);
			++env->editor.count.portal;
		}
	}
	else if (intersects_count(*vertex, *(vertex->next),
		env->editor.portal_points[0], env->editor.portal_points[1]))
	{
		save_vertex(env, sector, vertex, vertex->next);
		++env->editor.count.portal;
	}
	if (env->editor.count.portal == 2)
	{
		env->editor.count.portal = 0;
		return (1);
	}
	return (0);
}

int			vertex_intersect(t_env *env, t_ed_sector *sector)
{
	t_vertex	*vertex;

	vertex = sector->vertex;
	while (vertex)
	{
		if (check_vertex(env, vertex, sector))
			return (1);
		vertex = vertex->next;
	}
	return (0);
}
