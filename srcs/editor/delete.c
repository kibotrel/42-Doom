#include "libft.h"
#include "editor.h"

void				delete_vertex(t_vertex **vertex)
{
	t_vertex	*tmp;
	t_vertex	*to_del;

	if (*vertex == NULL)
		return ;
	to_del = NULL;
	tmp = NULL;
	to_del = *vertex;
	tmp = to_del;
	while (tmp)
	{
		tmp = to_del->next;
		free(to_del);
		to_del = tmp;
	}
	*vertex = NULL;
}

static void			delete_portals(t_portal **portal)
{
	t_portal	*tmp;
	t_portal	*to_del;

	if (*portal == NULL)
		return ;
	to_del = NULL;
	tmp = NULL;
	to_del = *portal;
	while (to_del->prev)
		to_del = to_del->prev;
	tmp = to_del;
	while (tmp)
	{
		tmp = to_del->next;
		free(to_del);
		to_del = tmp;
	}
	*portal = NULL;
}

void				delete_sector(t_sector **sectors)
{
	t_sector		*tmp;
	t_sector		*to_del;

	if (*sectors == NULL)
		return ;
	to_del = NULL;
	tmp = NULL;
	to_del = *sectors;
	while (to_del->prev)
		to_del = to_del->prev;
	tmp = to_del;
	while (tmp)
	{
		tmp = to_del->next;
		free(to_del->is_portal);
		free(to_del->portal_type);
		delete_vertex(&to_del->vertex);
		delete_portals(&to_del->portal);
		free(to_del);
		to_del = tmp;
	}
	*sectors = NULL;
}

static void			delete_entity(t_entity **entity)
{
	t_entity	*tmp;
	t_entity	*to_del;

	if (*entity == NULL)
		return ;
	to_del = NULL;
	tmp = NULL;
	to_del = *entity;
	while (to_del->prev)
		to_del = to_del->prev;
	tmp = to_del;
	while (tmp)
	{
		tmp = to_del->next;
		free(to_del);
		to_del = tmp;
	}
	*entity = NULL;
}

void				clear_editor(t_editor *editor)
{
	delete_player(&editor->player);
	if (editor->sector)
		delete_sector(&editor->sector);
	if (editor->vertex)
		delete_vertex(&editor->vertex);
	if (editor->enemy)
		delete_entity(&editor->enemy);
	if (editor->object)
		delete_entity(&editor->object);
	if (editor->portals)
		delete_portals(&editor->portals);
	editor->sett = SECTOR;
	editor->last_vertex.x = -1;
	editor->last_vertex.y = -1;
	init_portals(editor);
	init_count(&editor->count);
	blank_menu(editor->sdl.surf, editor->sett, editor, editor->presets);
	editor->map_save = true;
}
