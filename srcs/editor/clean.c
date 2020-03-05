/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:51:32 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/04 13:22:55 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

void			delete_vertex(t_vertex **vertex)
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

void			init_count(t_count *count)
{
	count->vertex = 0;
	count->sector = 0;
	count->enemy = 0;
	count->portal = 0;
	count->object = 0;
	count->button.new = 0;
	count->button.old = 0;
	ft_bzero(&count->eff_data, sizeof(int) * ALL_EFFECTS);
}

void			clean_editor(t_editor *editor)
{
	clear_editor(editor);
	if (editor->which_sector)
	{
		delete_sector(&editor->which_sector);
		free(editor->which_sector);
	}
	if (editor->sector)
		free(editor->sector);
	if (editor->object)
		free(editor->object);
	if (editor->enemy)
		free(editor->enemy);
	if (editor->portals)
		free(editor->portals);
	if (editor->ab)
	{
		delete_vertex(&editor->ab);
		free(editor->ab);
	}
	if (editor->cd)
	{
		delete_vertex(&editor->cd);
		free(editor->ab);
	}
}
