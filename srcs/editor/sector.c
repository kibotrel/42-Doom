/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:06:05 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/06 10:11:38 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "libft.h"
#include "editor.h"

int					count_vertex_in_sector(t_vertex *vertex)
{
	int			count;
	t_vertex	*vert;

	count = 0;
	vert = vertex;
	while (vert)
	{
		vert = vert->next;
		++count;
	}
	return (count);
}

static bool			is_sector_complete(t_vertex *first, t_vertex *last)
{
	if (!first || !last)
		return (false);
	if (first->x == last->x && first->y == last->y)
		return (true);
	return (false);
}

static t_ed_sector	*get_last_sector(t_editor *editor, t_env *env)
{
	t_ed_sector	*sect;

	if (!(editor->sector))
		editor->sector = create_sector(env, editor);
	sect = editor->sector;
	while (sect->next)
		sect = sect->next;
	return (sect);
}

static void			next_place_sector(t_ed_sector *sect, t_env *env,
	t_editor *edit)
{
	sect->vertex_count = count_vertex_in_sector(sect->vertex);
	if (!(sect->is_portal = (int*)ft_memalloc(sizeof(int)
					* sect->vertex_count)))
		clean(env, E_EDIT_SECT_PORTAL);
	sect->is_portal = ft_memset(sect->is_portal, -1, sizeof(int)
			* sect->vertex_count);
	sect->next = create_sector(env, edit);
	sect->next->prev = sect;
	edit->sect_is_closed = true;
	edit->last_vertex = init_vertex(-1, -1);
}

void				place_sector(t_editor *editor, int x, int y, t_env *env)
{
	t_vertex	*new;
	t_ed_sector	*sect;

	x = (x / editor->true_grid) * editor->true_grid;
	y = (y / editor->true_grid) * editor->true_grid;
	new = get_vertex(editor, x, y, env);
	sect = get_last_sector(editor, env);
	if (is_sector_complete(sect->vertex, new) == true)
	{
		next_place_sector(sect, env, editor);
		free(new);
	}
	else
	{
		add_vertex(&sect->vertex, new);
		editor->sect_is_closed = false;
	}
}
