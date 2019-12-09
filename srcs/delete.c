/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:46:27 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/12/09 13:37:09 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

static void	delete_vertex(t_vertex **vertex)
{
	t_vertex	*tmp;
	t_vertex	*to_del;

	if (*vertex == NULL)
		return ;
	to_del = NULL;
	tmp = NULL;
	to_del = *vertex;
	tmp = to_del;
	while (tmp)
	{
		tmp = to_del->next;
		free(to_del);
		to_del = tmp;
	}
	*vertex = NULL;
}

static void	delete_sector(t_sector **sectors)
{
	t_sector		*tmp;
	t_sector		*to_del;

	if (*sectors == NULL)
		return ;
	to_del = NULL;
	tmp = NULL;
	to_del = *sectors;
	tmp = to_del;
	while (tmp)
	{
		tmp = to_del->next;
		delete_vertex(&to_del->vertex);
		free(to_del);
		to_del = tmp;
	}
	*sectors = NULL;
}

static void	delete_entity(t_entity **entity)
{
	t_entity	*tmp;
	t_entity	*to_del;

	if (*entity == NULL)
		return ;
	to_del = NULL;
	tmp = NULL;
	to_del = *entity;
	tmp = to_del;
	while (tmp)
	{
		tmp = to_del->next;
		free(to_del);
		to_del = tmp;
	}
	*entity = NULL;
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