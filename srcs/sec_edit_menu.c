/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_edit_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:39:32 by reda-con          #+#    #+#             */
/*   Updated: 2019/12/13 14:48:20 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			sec_blank_menu(SDL_Surface *s, int set, int preset)
{
	int		clr;

	if (set == SECTOR)
	{
		clr = ((preset != SECTOR_FLOOR) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 340), init_vertex(1710, 410), clr, s);
		clr = ((preset != SECTOR_CEIL) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 440), init_vertex(1710, 510), clr, s);
		clr = ((preset != SECTOR_TEXT) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 540), init_vertex(1710, 610), clr, s);
	}
	if (set == ENEMY || set == OBJECT)
	{
		clr = ((preset != ENTITY_TYPE) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 640), init_vertex(1710, 710), clr, s);
	}
	if (preset != NONE)
	{
		rectangle(init_vertex(1399, 49), init_vertex(1450, 100), 0xffa500, s);
		rectangle(init_vertex(1599, 49), init_vertex(1650, 100), 0xffa500, s);
		square(1450, 100, 0x8d33ff, s);
		square(1650, 100, 0x8d33ff, s);
	}
}

void			next_next_sec_clic_menu_editor(int y, t_editor *editor)
{
	if (y >= 540 && y <= 610)
	{
		if (editor->sett == ENEMY)
			del_entity(&editor->enemy);
		else if (editor->sett == OBJECT)
			del_entity(&editor->object);
		else if (editor->sett == SECTOR)
			editor->presets = SECTOR_TEXT;
	}
	else if (y >= 640 && y <= 710)
	{
		if (editor->sett == ENEMY || editor->sett == OBJECT)
			editor->presets = ENTITY_TYPE;
	}
}

void			next_sec_clic_menu_editor(int y, t_editor *editor)
{
	if (y >= 340 && y <= 410)
	{
		if (editor->sett == PLAYER)
			delete_player(&editor->player);
		else if (editor->sett == ENEMY)
			rotate_entity(editor->enemy, true);
		else if (editor->sett == OBJECT)
			rotate_entity(editor->object, true);
		else if (editor->sett == SECTOR)
			editor->presets = SECTOR_FLOOR;
	}
	else if (y >= 440 && y <= 510)
	{
		if (editor->sett == ENEMY)
			rotate_entity(editor->enemy, false);
		else if (editor->sett == OBJECT)
			rotate_entity(editor->object, false);
		else if (editor->sett == SECTOR)
			editor->presets = SECTOR_CEIL;
	}
	next_next_sec_clic_menu_editor(y, editor);
}

void			sec_clic_menu_editor(int y, t_editor *editor)
{
	if (y >= 140 && y <= 210)
	{
		if (editor->sett == PLAYER)
			rotate_player(&editor->player, true);
		else if (editor->sett == ENEMY)
			move_in_entities(&editor->enemy, false);
		else if (editor->sett == OBJECT)
			move_in_entities(&editor->object, false);
		else if (editor->sett == SECTOR)
			move_in_sector(&editor->sector, false);
		editor->presets = NONE;
	}
	else if (y >= 240 && y <= 310)
	{
		if (editor->sett == PLAYER)
			rotate_player(&editor->player, false);
		else if (editor->sett == ENEMY)
			move_in_entities(&editor->enemy, true);
		else if (editor->sett == OBJECT)
			move_in_entities(&editor->object, true);
		else if (editor->sett == SECTOR)
			move_in_sector(&editor->sector, true);
		editor->presets = NONE;
	}
	next_sec_clic_menu_editor(y, editor);
}
