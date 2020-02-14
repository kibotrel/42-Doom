#include "editor.h"

static void		blank_sect(int set, int preset, SDL_Surface *s)
{
	int		clr;

	if (set == SECTOR)
	{
		clr = ((preset != SECTOR_MOVE) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), clr, s);
		clr = ((preset != SECTOR_FLOOR) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 240), init_vertex(1710, 310), clr, s);
		clr = ((preset != SECTOR_CEIL) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 340), init_vertex(1710, 410), clr, s);
		clr = ((preset != SECTOR_TEXT) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 440), init_vertex(1710, 510), clr, s);
		clr = ((preset != SECTOR_GRAV) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 540), init_vertex(1710, 610), clr, s);
		clr = ((preset != SECTOR_FRICTION) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 640), init_vertex(1710, 710), clr, s);
		clr = ((preset != SECTOR_LIGHT) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 740), init_vertex(1710, 810), clr, s);
	}
}

void			sec_blank_menu(SDL_Surface *s, int set, int preset)
{
	int		clr;

	blank_sect(set, preset, s);
	if (set == OBJECT || set == ENEMY)
	{
		clr = ((preset != ENTITY_TYPE) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 440), init_vertex(1710, 510), clr, s);
		clr = ((preset != ENTITY_ROTATE) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 240), init_vertex(1710, 310), clr, s);
		clr = ((preset != ENTITY_MOVE) ? 0xffffff : 0x177013);
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), clr, s);
	}
	if (set == PLAYER)
		clr = ((preset != PLAYER_ROTATE) ? 0xffffff : 0x177013);
	if (set == PLAYER)
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), clr, s);
	if (preset != NONE && preset != SECTOR_MOVE)
	{
		rectangle(init_vertex(1399, 49), init_vertex(1450, 100), 0xffa500, s);
		rectangle(init_vertex(1599, 49), init_vertex(1650, 100), 0xffa500, s);
		square(1450, 100, 0x8d33ff, s);
		square(1650, 100, 0x8d33ff, s);
	}
}

static void		part_5_sec_clic_menu_editor(int y, t_editor *editor)
{
	if (y >= 540 && y <= 610)
	{
		if (editor->sett == SECTOR)
			editor->presets = SECTOR_GRAV;
		else
			editor->presets = NONE;
	}
	if (y >= 640 && y <= 710)
	{
		if (editor->sett == SECTOR)
			editor->presets = SECTOR_FRICTION;
		else
			editor->presets = NONE;
	}
	if (y >= 740 && y <= 810)
	{
		if (editor->sett == SECTOR)
			editor->presets = SECTOR_LIGHT;
		else
			editor->presets = NONE;
	}
}

static void		next_sec_clic_menu_editor(int y, t_editor *editor)
{
	if (y >= 340 && y <= 410)
	{
		if (editor->sett == ENEMY)
			del_entity(&editor->enemy);
		if (editor->sett == ENEMY)
			editor->map_save = false;
		if (editor->sett == OBJECT)
			del_entity(&editor->object);
		if (editor->sett == OBJECT)
			editor->map_save = false;
		if (editor->sett == SECTOR)
			editor->presets = SECTOR_CEIL;
		else
			editor->presets = NONE;
	}
	next_sec_clic_menu_editor_tool(y, editor);
	part_5_sec_clic_menu_editor(y, editor);
}

void			sec_clic_menu_editor(int y, t_editor *editor)
{
	if (y >= 140 && y <= 210)
	{
		if (editor->sett == PLAYER)
			editor->presets = PLAYER_ROTATE;
		if (editor->sett == ENEMY || editor->sett == OBJECT)
			editor->presets = ENTITY_MOVE;
		if (editor->sett == SECTOR)
			editor->presets = SECTOR_MOVE;
	}
	sec_clic_menu_editor_tool(y, editor);
	next_sec_clic_menu_editor(y, editor);
}
