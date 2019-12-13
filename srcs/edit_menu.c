/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2009/11/19 13:07:32 by reda-con          #+#    #+#             */
/*   Updated: 2019/12/13 12:50:59 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			blank_menu(SDL_Surface *s, int set, t_sdl sdl, t_presets preset)
{
	int		clr;

	draw_back_ground(s);
	clr = ((set != SECTOR) ? 0xffffff : 0x289655);
	rectangle(init_vertex(1340, 140), init_vertex(1510, 210), clr, s);
	clr = ((set != PLAYER) ? 0xffffff : 0x177489);
	rectangle(init_vertex(1340, 240), init_vertex(1510, 310), clr, s);
	clr = ((set != ENEMY) ? 0xffffff : 0x090875);
	rectangle(init_vertex(1340, 340), init_vertex(1510, 410), clr, s);
	clr = ((set != OBJECT) ? 0xffffff : 0x146595);
	rectangle(init_vertex(1340, 440), init_vertex(1510, 510), clr, s);
	clr = ((set != PORTAL) ? 0xffffff : 0x177013);
	rectangle(init_vertex(1340, 540), init_vertex(1510, 610), clr, s);
	if (set == SECTOR)
	{
		clr = ((preset != SECTOR_FLOOR) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 340), init_vertex(1710, 410), clr, s);
		clr = ((preset != SECTOR_CEIL) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 440), init_vertex(1710, 510), clr, s);
		clr = ((preset != SECTOR_TEXT) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 540), init_vertex(1710, 610), clr, s);
	}
	next_blank_menu(set, s);
	rectangle(init_vertex(1350, 250), init_vertex(1400, 300), 0xffa500, s);
	rectangle(init_vertex(1350, 150), init_vertex(1400, 200), 0xffa500, s);
	rectangle(init_vertex(1350, 450), init_vertex(1400, 500), 0xffa500, s);
	rectangle(init_vertex(1350, 350), init_vertex(1400, 400), 0xffa500, s);
	rectangle(init_vertex(1350, 550), init_vertex(1400, 600), 0xffa500, s);
	if (preset != NONE)
	{
		rectangle(init_vertex(1399, 49), init_vertex(1450, 100), 0xffa500, s);
		rectangle(init_vertex(1599, 49), init_vertex(1650, 100), 0xffa500, s);
		square(1450, 100, 0x8d33ff, s);
		square(1650, 100, 0x8d33ff, s);
	}
	print_param_in_param(&sdl, set);
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
	else if (y >= 540 && y <= 610)
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
	}
	next_sec_clic_menu_editor(y, editor);
}

void			clic_editor_menu(int x, int y, t_editor *editor)
{
	int		fl;

	fl = -1;
	if (x >= 1340 && x <= 1510)
	{
		if (y >= 140 && y <= 210)
			fl = SECTOR;
		else if (y >= 240 && y <= 310)
			fl = PLAYER;
		else if (y >= 340 && y <= 410)
			fl = ENEMY;
		else if (y >= 440 && y <= 510)
			fl = OBJECT;
		else if (y >= 540 && y <= 610)
			fl = PORTAL;
		if (fl != -1)
			editor->sett = fl;
		if (fl != -1)
			editor->presets = NONE;
		blank_menu(editor->sdl.surf, editor->sett, editor->sdl, editor->presets);
	}
	else if (x >= 1540 && x <= 1710)
		sec_clic_menu_editor(y, editor);
	if (y >= 50 && y <= 100)
	{
		if (x >= 1400 && x <= 1450)
			change_value(editor, editor->presets, false);
		else if (x >= 1600 && x <= 1650)
			change_value(editor, editor->presets, true);
		blank_menu(editor->sdl.surf, editor->sett, editor->sdl, editor->presets);
	}
	if (editor->presets != NONE)
		blank_menu(editor->sdl.surf, editor->sett, editor->sdl, editor->presets);
}

static void			next_motion(t_sdl s, int set, t_presets preset)
{
	int		y;

	y = s.event.motion.y;
	if (set != PORTAL && y >= 140 && y <= 210)
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), PRPL, s.surf);
	else if (set != PORTAL && y >= 240 && y <= 310)
		rectangle(init_vertex(1540, 240), init_vertex(1710, 310), PRPL, s.surf);
	else if (set != PORTAL && y >= 340 && y <= 410)
		rectangle(init_vertex(1540, 340), init_vertex(1710, 410), PRPL, s.surf);
	else if ((set != PORTAL && set != PLAYER) && y >= 440 && y <= 510)
		rectangle(init_vertex(1540, 440), init_vertex(1710, 510), PRPL, s.surf);
	else if ((set != PORTAL && set != PLAYER) && y >= 540 && y <= 610)
		rectangle(init_vertex(1540, 540), init_vertex(1710, 610), PRPL, s.surf);
	else if ((set == ENEMY || set == OBJECT) && y >= 640 && y <= 710)
		rectangle(init_vertex(1540, 640), init_vertex(1710, 710), PRPL, s.surf);
	else
		blank_menu(s.surf, set, s, preset);
}

void			motion(t_sdl s, int set, t_presets preset)
{
	if (s.event.motion.x >= 1340 && s.event.motion.x <= 1510)
	{
		if ((s.event.motion.y >= 140 && s.event.motion.y <= 210))
			rectangle(init_vertex(1340, 140), init_vertex(1510, 210),\
					PRPL, s.surf);
		else if (s.event.motion.y >= 240 && s.event.motion.y <= 310)
			rectangle(init_vertex(1340, 240), init_vertex(1510, 310),\
					PRPL, s.surf);
		else if (s.event.motion.y >= 340 && s.event.motion.y <= 410)
			rectangle(init_vertex(1340, 340), init_vertex(1510, 410),\
					PRPL, s.surf);
		else if (s.event.motion.y >= 440 && s.event.motion.y <= 510)
			rectangle(init_vertex(1340, 440), init_vertex(1510, 510),\
					PRPL, s.surf);
		else if (s.event.motion.y >= 540 && s.event.motion.y <= 610)
			rectangle(init_vertex(1340, 540), init_vertex(1510, 610),\
					PRPL, s.surf);
		else
			blank_menu(s.surf, set, s, preset);
	}
	else if (s.event.motion.x >= 1540 && s.event.motion.x <= 1710)
		next_motion(s, set, preset);
	else
		blank_menu(s.surf, set, s, preset);
}
