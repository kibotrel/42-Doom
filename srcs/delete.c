/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:46:27 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/12/02 11:20:29 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

static void	delete_vertex(t_vertex **vertex)
{
	t_vertex 	*tmp;
	t_vertex	*del;

	tmp = *vertex;
	del = tmp;
	while (tmp)
	{
		tmp = tmp->next;
		free(del);
		del = NULL;
		del = tmp;
	}
}

static void	delete_entity(t_entity **entity)
{
	t_entity 	*tmp;
	t_entity	*del;

	tmp = *entity;
	del = tmp;
	while (tmp)
	{
		tmp = tmp->next;
		free(del);
		del = NULL;
		del = tmp;
	}
}

static void	delete_sector(t_sector **sectors)
{
	t_sector 	*tmp;
	t_sector 	*next;

	tmp = *sectors;
	next = tmp;
	while (next)
	{
		next = next->next;
		delete_vertex(&tmp->vertex);
		free(tmp);
		tmp = NULL;
		tmp = next;
	}
}

void	clear_editor(t_editor *editor)
{
	delete_player(&editor->player);
	if (editor->sector)
		delete_sector(&editor->sector);
	if (editor->vertex)
		delete_vertex(&editor->vertex);
	if (editor->enemy)
		delete_entity(&editor->enemy);
	if (editor->object)
		delete_entity(&editor->object);
	editor->sett = SECTOR;
	editor->last_vertex.x = -1;
	editor->last_vertex.y = -1;
	init_portals(editor);
	editor->sect_is_closed = false;
}