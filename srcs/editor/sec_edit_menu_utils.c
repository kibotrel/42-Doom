#include "editor.h"

void	sec_clic_menu_editor_tool(int y, t_editor *editor)
{
	if (y >= 240 && y <= 310)
	{
		if (editor->sett == PLAYER)
			delete_player(&editor->player);
		else if (editor->sett == ENEMY || editor->sett == OBJECT)
			editor->presets = ENTITY_ROTATE;
		else if (editor->sett == SECTOR)
			editor->presets = SECTOR_FLOOR;
		else if (editor->sett == EFFECTOR && editor->effects.effects != EFF_PLATE)
			editor->presets = EFF_MOVE;
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
		else if (editor->sett == EFFECTOR)
			editor->presets = EFF_S_PLATE;
		else
			editor->presets = NONE;
	}
}
