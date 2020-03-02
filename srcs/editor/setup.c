#include "env.h"
#include "editor.h"

void			init_portals(t_editor *editor)
{
	editor->portal_points[0].x = -1;
	editor->portal_points[0].y = -1;
	editor->portal_points[1].x = -1;
	editor->portal_points[1].y = -1;
	editor->which_sector = NULL;
	editor->ab = NULL;
	editor->cd = NULL;
}

static void		init_chained_list(t_editor *editor)
{
	editor->enemy = NULL;
	editor->sector = NULL;
	editor->object = NULL;
	editor->portals = NULL;
}

void			editor_setup(t_editor *editor)
{
	editor->dist_grid = 50;
	editor->true_grid = EDIT_W / editor->dist_grid;
	editor->grid = 1;
	editor->sett = SECTOR;
	editor->presets = NONE;
	editor->effects.effects = EFF_NONE;
	editor->effects.data = 0;
	editor->finish = false;
	editor->display_portal = -1;
	editor->delete = -1;
	editor->sect_is_closed = true;
	editor->last_vertex.x = -1;
	editor->last_vertex.y = -1;
	editor->map_save = true;
	editor->player.x = -5;
	editor->player.y = -5;
	editor->player.angle = 90;
	init_chained_list(editor);
	init_portals(editor);
	init_count(&editor->count);
}
