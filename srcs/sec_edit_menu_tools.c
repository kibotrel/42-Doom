/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_edit_menu_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:31:57 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/13 11:47:14 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	sec_clic_menu_editor_tool(int y, t_editor *editor)
{
	if (y >= 240 && y <= 310)
	{
		if (editor->sett == PLAYER)
		{
			delete_player(&editor->player);
			editor->map_save = false;
		}
		else if (editor->sett == ENEMY || editor->sett == OBJECT)
			editor->presets = ENTITY_ROTATE;
		else if (editor->sett == SECTOR)
			editor->presets = SECTOR_FLOOR;
		else if (editor->sett == PORTAL)
			editor->presets = PORTAL_TYPE;
		if (editor->sett == PLAYER)
			editor->presets = NONE;
	}
}

void	next_sec_clic_menu_editor_tool(int y, t_editor *editor)
{
	if (y >= 440 && y <= 510)
	{
		if (editor->sett == ENEMY)
			editor->presets = ENTITY_TYPE;
		else if (editor->sett == OBJECT)
			editor->presets = ENTITY_TYPE;
		else if (editor->sett == SECTOR)
			editor->presets = SECTOR_TEXT;
		else
			editor->presets = NONE;
	}
}
