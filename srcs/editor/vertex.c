/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:06:21 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/09/16 15:41:11 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

t_vertex 	*create_vertex(int x, int y)
{
	t_vertex	*new;

	if (!(new = (t_vertex*)ft_memalloc(sizeof(t_vertex))))
		exit(1);
	new->x = x;
	new->y = y;
	return (new);
}

void		add_vertex(t_vertex **vertex, t_vertex *new)
{
	static int		vertex_num = 0;
	t_vertex		*prev_vertex;

	new->number = vertex_num++;
	if ((*vertex) == NULL)
		(*vertex) = new;
	else
	{
		prev_vertex = (*vertex);
		while (prev_vertex->next)
			prev_vertex = prev_vertex->next;
		prev_vertex->next = new;
	}
}

void	get_vertex(t_editor *edit, int x, int y)
{
	t_vertex	*new_vertex;

	x = (x / edit->dist_grid) * edit->dist_grid;
	y = (y / edit->dist_grid) * edit->dist_grid;
	new_vertex = create_vertex(x, y);
	add_vertex(&edit->vertex, new_vertex);
}