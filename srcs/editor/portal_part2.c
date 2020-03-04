/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:47:09 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/04 09:50:28 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	place_portal_part2(t_vertex *point, t_env *env, t_editor *editor)
{
	t_ed_sector	*sector;

	editor->portal_points[1] = *point;
	sector = editor->sector;
	while (sector->prev)
		sector = sector->prev;
	while (sector)
	{
		if (vertex_intersect(env, sector))
		{
			init_portals(editor);
			break ;
		}
		sector = sector->next;
	}
	if (sector == NULL)
		init_portals(editor);
}

void		place_portal(t_editor *editor, int x, int y, t_env *env)
{
	t_vertex	*point;

	if (count_sector(editor->sector) < 2)
		return ;
	point = create_vertex(init_vertex(x, y), env, -1);
	if (editor->portal_points[0].x == -1)
		editor->portal_points[0] = *point;
	else if (editor->portal_points[1].x == -1)
		place_portal_part2(point, env, editor);
	free(point);
}
