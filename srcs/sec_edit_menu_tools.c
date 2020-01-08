/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_edit_menu_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:31:57 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/08 14:53:23 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	sec_clic_menu_editor_tool(int y, t_editor *editor)
{
	if (y >= 240 && y <= 310)
	{
		if (editor->sett == PLAYER)
		{
			rotate_player(&editor->player, false);
			editor->map_save = false;
		}
		else if (editor->sett == ENEMY)
			move_in_entities(&editor->enemy, true);
		else if (editor->sett == OBJECT)
			move_in_entities(&editor->object, true);
		else if (editor->sett == SECTOR)
			move_in_sector(&editor->sector, true);
		editor->presets = NONE;
	}
}

void	next_sec_clic_menu_editor_tool(int y, t_editor *editor)
{
	if (y >= 440 && y <= 510)
	{
		if (editor->sett == ENEMY)
			rotate_entity(editor->enemy, false);
		if (editor->sett == ENEMY)
			editor->map_save = false;
		if (editor->sett == OBJECT)
			rotate_entity(editor->object, false);
		if (editor->sett == OBJECT)
			editor->map_save = false;
		if (editor->sett != SECTOR)
			editor->presets = NONE;
		else
			editor->presets = SECTOR_CEIL;
	}
}
