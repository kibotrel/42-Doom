/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:06:21 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/09/25 17:21:16 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

void		print_all_vertex(t_editor *edit)
{
	t_vertex	*vertex;
	t_vertex	*prev_vertex;

	vertex = edit->vertex;
	prev_vertex = NULL;
	while (vertex)
	{
		if (prev_vertex == NULL)
			put_pixel(edit->sdl, vertex->x, vertex->y, 0x0000FF);
		else
			draw_line(edit->sdl, *prev_vertex, *vertex, 0x0000FF);
		prev_vertex = vertex;
		vertex = vertex->next;
	}
}

void		add_vertex(t_vertex **vertex, t_vertex *new, int count)
{
	static int		vertex_num = 0;
	t_vertex		*prev_vertex;

	if (count)
		new->number = vertex_num++;
	if (!(*vertex))
		*vertex = new;
	else
	{
		prev_vertex = *vertex;
		while (prev_vertex->next)
			prev_vertex = prev_vertex->next;
		prev_vertex->next = new;
	}
}

t_vertex		*is_vertex_double(t_vertex *vertex, int x, int y)
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

t_vertex		*get_vertex(t_editor **edit, int x, int y)
{
	t_vertex	*new_vertex;

	x = (x / (*edit)->dist_grid) * (*edit)->dist_grid;
	y = (y / (*edit)->dist_grid) * (*edit)->dist_grid;
	new_vertex = is_vertex_double((*edit)->vertex, x, y);
	if (!new_vertex)
	{
		new_vertex = create_vertex(x, y);
		add_vertex(&(*edit)->vertex, new_vertex, 1);
	}
	return (new_vertex);
}