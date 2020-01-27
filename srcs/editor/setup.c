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
	editor->vertex = NULL;
	editor->object = NULL;
	editor->portals = NULL;
}

void			init_editor(t_editor *editor)
{
	editor->dist_grid = 50;
	editor->true_grid = EDIT_W / editor->dist_grid;
	editor->grid = true;
	editor->sett = SECTOR;
	editor->presets = NONE;
	editor->finish = false;
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
