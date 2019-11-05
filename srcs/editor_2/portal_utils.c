/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:15:33 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/05 15:40:48 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		init_portals(t_editor *editor)
{
	editor->portal_points[0].x = -1;
	editor->portal_points[0].y = -1;
	editor->portal_points[1].x = -1;
	editor->portal_points[1].y = -1;
	editor->which_sector = NULL;
	editor->ab = NULL;
	editor->cd = NULL;
}

int			compare_coordinates(t_vertex *point, t_vertex *a, t_vertex *b)
{
	if (point->x == a->x && point->y == a->y)
		return (1);
	if (point->x == b->x && point->y == b->y)
		return (1);
	return (0);
}