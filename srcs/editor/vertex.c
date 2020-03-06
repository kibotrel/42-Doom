/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:37:26 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/06 10:12:52 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "editor.h"
#include "libft.h"

t_vertex		init_vertex(int x, int y)
{
	t_vertex	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_vertex		*create_vertex(t_vertex v, t_env *env, int num)
{
	t_vertex	*new;

	if (!(new = (t_vertex*)ft_memalloc(sizeof(t_vertex))))
		clean(env, E_EDIT_VERTEX);
	new->x = v.x;
	new->y = v.y;
	if (num >= 0)
		new->vertex_number = num;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			add_vertex(t_vertex **vertex, t_vertex *v)
{
	t_vertex	*prev_vertex;

	if (!*vertex)
		*vertex = v;
	else
	{
		prev_vertex = *vertex;
		while (prev_vertex->next)
			prev_vertex = prev_vertex->next;
		v->prev = prev_vertex;
		prev_vertex->next = v;
	}
}

static t_vertex	*is_vertex_double(t_ed_sector *sector, int x, int y)
{
	t_ed_sector	*sect;
	t_vertex	*vert;

	if (!sector)
		return (NULL);
	sect = sector;
	while (sect->prev)
		sect = sect->prev;
	while (sect)
	{
		vert = sect->vertex;
		while (vert)
		{
			if (vert->x == x && vert->y == y)
				return (vert);
			vert = vert->next;
		}
		sect = sect->next;
	}
	return (NULL);
}

t_vertex		*get_vertex(t_editor *editor, int x, int y, t_env *env)
{
	t_vertex	*new_vertex;

	new_vertex = is_vertex_double(editor->sector, x, y);
	if (!new_vertex)
	{
		new_vertex = create_vertex(init_vertex(x, y), env,
			editor->count.vertex++);
		editor->last_vertex.x = new_vertex->x;
		editor->last_vertex.y = new_vertex->y;
		return (new_vertex);
	}
	editor->last_vertex.x = new_vertex->x;
	editor->last_vertex.y = new_vertex->y;
	return (create_vertex(init_vertex(x, y), env, new_vertex->vertex_number));
}
