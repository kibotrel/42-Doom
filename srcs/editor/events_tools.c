#include "editor.h"

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

static void		change_type(int *to_change, bool fl, int min, int max)
{
	if (fl == false)
		--*to_change;
	else
		++*to_change;
	if (*to_change < min)
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
		change_type(&editor->sector->texture, fl, 0, 9);
	else if (presets == SECTOR_TYPE)
		change_type(&editor->sector->type, fl, 0, 3);
	else if (presets == SECTOR_GRAV)
		change_percentage(&editor->sector->gravity, fl);
	else if (presets == SECTOR_FRICTION)
		change_percentage(&editor->sector->friction, fl);
	else if (presets == SECTOR_LIGHT)
		change_type(&editor->sector->light, fl, -1, 6);
	else if (presets == ENTITY_TYPE && editor->sett == ENEMY && editor->enemy)
		change_type(&editor->enemy->type, fl, 0, 3);
	else if (presets == ENTITY_TYPE && editor->sett == OBJECT && editor->object)
		change_type(&editor->object->type, fl, 0 , 3);
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
	else if (presets == EFF_EFFECT && editor->sett == EFFECTOR)
		change_effect(&editor->effects.effects, fl);
	else if (presets == EFF_DATA && editor->sett == EFFECTOR)
	{
		if (editor->effects.effects != EFF_NONE && editor->effects.effects != EFF_SKY)
		{
			if (editor->effects.effects != EFF_ELEV)
				change_type(&editor->count.eff_data[editor->effects.effects], fl, 0, 1000);
		}
	}
}
