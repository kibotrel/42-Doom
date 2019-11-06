/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:29:24 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/06 08:27:28 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "libft.h"

t_vertex	*create_vertex(int x, int y)
{
	t_vertex 	*new;

	if (!(new = (t_vertex*)ft_memalloc(sizeof(t_vertex))))
		exit(1);
	new->x = x;
	new->y = y;
	return (new);
}

void		add_vertex(t_vertex *vertex, t_vertex *new, int count)
{
	static int	vertex_number = 0;
	t_vertex 	*prev_vertex;

	if (count)
		new->vertex_number = vertex_number++;
	if (!vertex)
		vertex = new;
	else
	{
		prev_vertex = vertex;
		while (prev_vertex->next)
			prev_vertex = prev_vertex->next;
		prev_vertex->next = new;
	}
}

static t_vertex	*is_vertex_double(t_vertex *vertex, int x, int y)
{
	t_vertex	*vert;

	if (!vertex)
		return (NULL);
	vert = vertex;
	while (vert)
	{
		if (vert->x == x && vert->y == y)
			return (vert);
		vert = vert->next;
	}
	return (NULL);
}

t_vertex 	*get_vertex(t_editor *editor, int x, int y)
{
	t_vertex 	*new_vertex;
	
	x = (x / editor->dist_grid) * editor->dist_grid;
	y = (y / editor->dist_grid) * editor->dist_grid;
	new_vertex = is_vertex_double(editor->vertex, x, y);
	if (!new_vertex)
	{
		new_vertex = create_vertex(x, y);
		add_vertex(editor->vertex, new_vertex, 1);
	}
	editor->last_vertex.x = new_vertex->x;
	editor->last_vertex.y = new_vertex->y;
	return (new_vertex);
}