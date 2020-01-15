/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:15:33 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/15 09:42:03 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

static t_portal	*create_portal(t_vertex v1, t_vertex v2, t_editor *edit)
{
	t_portal	*new;

	if (!(new = (t_portal*)ft_memalloc(sizeof(t_portal))))
		clean(edit);
	new->extrems[0] = v1;
	new->extrems[1] = v2;
	new->type = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void		add_portal(t_portal **portal, t_vertex v1, t_vertex v2,
	t_editor *edit)
{
	t_portal	*new;
	t_portal	*prev_portal;

	new = create_portal(v1, v2, edit);
	if (!*portal)
		*portal = new;
	else
	{
		prev_portal = *portal;
		while (prev_portal->next)
			prev_portal = prev_portal->next;
		new->prev = prev_portal;
		prev_portal->next = new;
	}
}

void		move_in_portals(t_portal **portal, bool way)
{
	t_portal	*tmp;

	if (!*portal)
		return ;
	tmp = *portal;
	if (way == true)
	{
		if (tmp->next)
			tmp = tmp->next;
	}
	else
	{
		if (tmp->prev)
			tmp = tmp->prev;
	}
	*portal = tmp;
}