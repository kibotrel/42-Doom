#include "editor.h"

static void		fst_clic_editor_menu(int y, t_editor *editor)
{
	int		fl;

	fl = -1;
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
}

void			clic_editor_menu(int x, int y, t_editor *editor, t_env *env)
{
	if (x >= 1300 && x <= 1410 && y >= 660 && y <= 710)
		clear_editor(editor, env);
	else if (x >= 1420 && x <= 1530 && y >= 660 && y <= 710)
	{
		create_map(editor);
		editor->map_save = true;
	}
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
	// blank_menu(env->sdl.screen, editor->sett, editor, editor->presets, env);
}

static void		next_motion(t_sdl s, int set, int preset, t_editor *edit, t_env *env)
{
	int		y;

	y = s.event.motion.y;
	if (y >= 140 && y <= 210)
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), PRPL, s.screen);
	else if (y >= 240 && y <= 310)
		rectangle(init_vertex(1540, 240), init_vertex(1710, 310), PRPL, s.screen);
	else if ((set != PORTAL && set != PLAYER) && y >= 340 && y <= 410)
		rectangle(init_vertex(1540, 340), init_vertex(1710, 410), PRPL, s.screen);
	else if ((set != PORTAL && set != PLAYER) && y >= 440 && y <= 510)
		rectangle(init_vertex(1540, 440), init_vertex(1710, 510), PRPL, s.screen);
	else if (set == SECTOR && y >= 540 && y <= 610)
		rectangle(init_vertex(1540, 540), init_vertex(1710, 610), PRPL, s.screen);
	else if (set == SECTOR && y >= 640 && y <= 710)
		rectangle(init_vertex(1540, 640), init_vertex(1710, 710), PRPL, s.screen);
	else
		blank_menu(s.screen, set, edit, preset, env);
}

static void		option_motion(t_sdl s, int set, int preset, t_editor *edit, t_env *env)
{
	int		x;
	int		y;

	x = s.event.motion.x;
	y = s.event.motion.y;
	if (x >= 1300 && x <= 1410 && y >= 660 && y <= 710)
		rectangle(init_vertex(1300, 660), init_vertex(1410, 710), PRPL, s.screen);
	else if (x > 1420 && x <= 1530 && y >= 660 && y <= 710)
		rectangle(init_vertex(1420, 660), init_vertex(1530, 710), PRPL, s.screen);
	else
		blank_menu(s.screen, set, edit, preset, env);
}

void			editor_motion(t_sdl s, int set, int preset, t_editor *edit, t_env *env)
{
	if (s.event.motion.y >= 660 && s.event.motion.y <= 710 &&
		((s.event.motion.x >= 1300 && s.event.motion.x <= 1410) ||
			(s.event.motion.x >= 1420 && s.event.motion.x <= 1530)))
		option_motion(s, set, preset, edit, env);
	else if (s.event.motion.x >= 1340 && s.event.motion.x <= 1510)
	{
		if ((s.event.motion.y >= 140 && s.event.motion.y <= 210))
			rectangle(init_vertex(1340, 140), init_vertex(1510, 210),
					PRPL, s.screen);
		else if (s.event.motion.y >= 240 && s.event.motion.y <= 310)
			rectangle(init_vertex(1340, 240), init_vertex(1510, 310),
					PRPL, s.screen);
		else if (s.event.motion.y >= 340 && s.event.motion.y <= 410)
			rectangle(init_vertex(1340, 340), init_vertex(1510, 410),
					PRPL, s.screen);
		else if (s.event.motion.y >= 440 && s.event.motion.y <= 510)
			rectangle(init_vertex(1340, 440), init_vertex(1510, 510),
					PRPL, s.screen);
		else if (s.event.motion.y >= 540 && s.event.motion.y <= 610)
			rectangle(init_vertex(1340, 540), init_vertex(1510, 610),
					PRPL, s.screen);
		else
			blank_menu(s.screen, set, edit, preset, env);
	}
	else if (s.event.motion.x >= 1540 && s.event.motion.x <= 1710)
		next_motion(s, set, preset, edit, env);
	// else
		// blank_menu(s.screen, set, edit, preset, env);
}
