#include "editor.h"

void			next_keydown(SDL_Event event, SDL_Surface *s, t_editor *editor)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_1)
	{
		editor->sett = SECTOR;
		rectangle(init_vertex(1340, 140), init_vertex(1510, 210), 0x5f287e, s);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_2)
	{
		editor->sett = PLAYER;
		rectangle(init_vertex(1340, 240), init_vertex(1510, 310), 0x5f287e, s);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_3)
	{
		editor->sett = ENEMY;
		rectangle(init_vertex(1340, 340), init_vertex(1510, 410), 0x5f287e, s);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_4)
	{
		editor->sett = OBJECT;
		rectangle(init_vertex(1340, 440), init_vertex(1510, 510), 0x5f287e, s);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_5)
	{
		editor->sett = PORTAL;
		rectangle(init_vertex(1340, 540), init_vertex(1510, 610), 0x5f287e, s);
	}
}

static void		change_height(int *to_change, bool fl)
{
	if (fl == false)
		--*to_change;
	else
		++*to_change;
	if (*to_change < -250)
		++*to_change;
	else if (*to_change > 250)
		--*to_change;
}

static void		change_type(int *to_change, bool fl)
{
	int		max;

	max = 3;
	if (fl == false)
		--*to_change;
	else
		++*to_change;
	if (*to_change < 0)
		++*to_change;
	else if (*to_change > max)
		--*to_change;
}

static void		change_percentage(int *to_change, bool fl)
{
	if (fl == false)
		--*to_change;
	else
		++*to_change;
	if (*to_change < 0)
		++*to_change;
	else if (*to_change > 100)
		--*to_change;
}

void			change_value(t_editor *editor, t_presets presets, bool fl)
{
	if (presets == SECTOR_FLOOR)
		change_height(&editor->sector->h_floor, fl);
	else if (presets == SECTOR_CEIL)
		change_height(&editor->sector->h_ceil, fl);
	else if (presets == SECTOR_TEXT)
		change_type(&editor->sector->texture, fl);
	else if (presets == SECTOR_GRAV)
		change_percentage(&editor->sector->gravity, fl);
	else if (presets == SECTOR_FRICTION)
		change_percentage(&editor->sector->friction, fl);
	else if (presets == ENTITY_TYPE && editor->sett == ENEMY && editor->enemy)
		change_type(&editor->enemy->type, fl);
	else if (presets == ENTITY_TYPE && editor->sett == OBJECT && editor->object)
		change_type(&editor->object->type, fl);
	else if (presets == ENTITY_MOVE && editor->sett == ENEMY)
		move_in_entities(&editor->enemy, fl);
	else if (presets == ENTITY_MOVE && editor->sett == OBJECT)
		move_in_entities(&editor->object, fl);
	else if (presets == ENTITY_ROTATE && editor->sett == ENEMY)
		rotate_entity(editor->enemy, fl);
	else if (presets == ENTITY_ROTATE && editor->sett == OBJECT)
		rotate_entity(editor->object, fl);
	else if (presets == PLAYER_ROTATE)
		rotate_player(&editor->player, fl);
	else if (presets == PORTAL_MOVE)
		move_in_portals(&editor->portals, fl);
	else if (presets == PORTAL_TYPE && editor->portals)
		change_portal_type(editor->sector, editor->portals, fl);
}
