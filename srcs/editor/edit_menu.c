#include "editor.h"
#include "env.h"

static void		fst_clic_editor_menu(int y, t_editor *editor)
{
	if (y >= 140 && y <= 210)
		editor->sett = SECTOR;
	else if (y >= 240 && y <= 310)
		editor->sett = PLAYER;
	else if (y >= 340 && y <= 410)
		editor->sett = ENEMY;
	else if (y >= 440 && y <= 510)
		editor->sett = OBJECT;
	else if (y >= 540 && y <= 610)
		editor->sett = PORTAL;
	else if (y >= 640 && y <= 710)
		editor->sett = EFFECTOR;
	if (y >= 140 && y <= 710)
		editor->presets = NONE;
}

void			clic_editor_menu(int x, int y, t_editor *editor, t_env *env)
{
	if (x >= 1300 && x <= 1410 && y >= 760 && y <= 810)
		clear_editor(editor, env);
	else if (x >= 1420 && x <= 1530 && y >= 760 && y <= 810)
		create_map(editor);
	else if (x >= 1340 && x <= 1510)
		fst_clic_editor_menu(y, editor);
	else if (x >= 1540 && x <= 1710)
		sec_clic_menu_editor(y, editor);
	if (y >= 50 && y <= 100)
	{
		if (x >= 1400 && x <= 1450)
			change_value(editor, editor->presets, false);
		else if (x >= 1600 && x <= 1650)
			change_value(editor, editor->presets, true);
	}
	else
		blank_menu(env->sdl.screen, editor->sett, editor, editor->presets, env);
}