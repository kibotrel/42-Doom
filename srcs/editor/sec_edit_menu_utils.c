/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_edit_menu_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:38:50 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/04 10:05:42 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	blank_sect_part2(int set, int effect, int preset, SDL_Surface *s)
{
	int		clr;

	if (set == EFFECTOR && effect == EFF_PLATE)
	{
		square(1600, 500, 0x00ffff, s);
		clr = ((preset != EFF_S_PLATE) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 440), init_vertex(1710, 510), clr, s);
		square(1600, 600, 0x124079, s);
		clr = ((preset != EFF_S_DOOR) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 540), init_vertex(1710, 610), clr, s);
	}
}

void	sec_blank_menu_part2(int preset, int set, SDL_Surface *s)
{
	int		clr;

	if (set == EFFECTOR)
	{
		clr = ((preset != EFF_EFFECT) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), clr, s);
		clr = ((preset != EFF_MOVE) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 240), init_vertex(1710, 310), clr, s);
		clr = ((preset != EFF_DATA) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 340), init_vertex(1710, 410), clr, s);
	}
	if (preset != NONE && preset != SECTOR_MOVE && preset != EFF_MOVE
		&& preset != EFF_S_DOOR && preset != EFF_S_PLATE)
	{
		rectangle(init_vertex(1399, 49), init_vertex(1450, 100), 0xffa500, s);
		rectangle(init_vertex(1599, 49), init_vertex(1650, 100), 0xffa500, s);
		square(1450, 100, 0x8d33ff, s);
		square(1650, 100, 0x8d33ff, s);
	}
}

void	sec_clic_menu_editor_tool(int y, t_editor *edit)
{
	if (y >= 240 && y <= 310)
	{
		if (edit->sett == PLAYER)
			delete_player(&edit->player);
		else if (edit->sett == ENEMY || edit->sett == OBJECT)
			edit->presets = ENTITY_ROTATE;
		else if (edit->sett == SECTOR)
			edit->presets = SECTOR_FLOOR;
		else if (edit->sett == EFFECTOR && edit->effects.effects != EFF_PLATE)
			edit->presets = EFF_MOVE;
		if (edit->sett == PLAYER)
			edit->presets = NONE;
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
		else if (editor->sett == EFFECTOR)
			editor->presets = EFF_S_PLATE;
		else
			editor->presets = NONE;
	}
}
