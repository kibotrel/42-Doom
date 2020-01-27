#include "editor.h"

static int	is_portal_close(t_ed_sector *sector, t_vertex *start, t_vertex *end)
{
	int			postion_closing_portal;
	t_vertex	*sector_vertex;
	t_vertex	*vertex;

	postion_closing_portal = 0;
	sector_vertex = sector->vertex;
	vertex = sector->vertex;
	if (vertex == NULL)
		return (-1);
	while (vertex)
	{
		if ((vertex->next == NULL) && ((vertex == start && sector_vertex == end)
			|| (vertex == end && sector_vertex == end)))
			return (sector->vertex_count - 1);
		if ((vertex == start && vertex->next == end)
			|| (vertex == end && vertex->next == start))
			return (postion_closing_portal);
		++postion_closing_portal;
		vertex = vertex->next;
	}
	return (-1);
}

static void	save_vertex(t_env *env, t_ed_sector *sector,
		t_vertex *first_point, t_vertex *last_point)
{
	int			from;
	int			dest;

	if (env->editor.which_sector == NULL)
	{
		env->editor.which_sector = sector;
		env->editor.ab = first_point;
		env->editor.cd = last_point;
	}
	else
	{
		if (compare_coordinates(first_point, env->editor.ab, env->editor.cd) == 0
			|| compare_coordinates(last_point, env->editor.ab, env->editor.cd) == 0)
			init_portals(&env->editor);
		else
		{
			dest = is_portal_close(sector, first_point, last_point);
			sector->is_portal[dest] = env->editor.which_sector->sector_number;
			from = is_portal_close(env->editor.which_sector, env->editor.ab,
				env->editor.cd);
			env->editor.which_sector->is_portal[from] = sector->sector_number;
			add_portal(&env->editor.portals, *first_point, *last_point, env);
			add_portal(&sector->portal, *first_point, *last_point, env);
			add_portal(&env->editor.which_sector->portal, *last_point, *first_point,
				env);
		}
	}
}

static int	check_vertex(t_env *env, t_vertex *vertex, t_ed_sector *sector)
{
	if (vertex->next == NULL)
	{
		if (intersects_count(*vertex, *(sector->vertex),
			env->editor.portal_points[0], env->editor.portal_points[1]))
		{
			save_vertex(env, sector, vertex, sector->vertex);
			++env->editor.count.portal;
		}
	}
	else if (intersects_count(*vertex, *(vertex->next),
		env->editor.portal_points[0], env->editor.portal_points[1]))
	{
		save_vertex(env, sector, vertex, vertex->next);
		++env->editor.count.portal;
	}
	if (env->editor.count.portal == 2)
	{
		env->editor.count.portal = 0;
		return (1);
	}
	return (0);
}

static int	vertex_intersect(t_env *env, t_ed_sector *sector)
{
	t_vertex	*vertex;

	vertex = sector->vertex;
	while (vertex)
	{
		if (check_vertex(env, vertex, sector))
			return (1);
		vertex = vertex->next;
	}
	return (0);
}

void		place_portal(t_editor *editor, int x, int y, t_env *env)
{
	t_vertex	*point;
	t_ed_sector	*sector;

	if (count_sector(editor->sector) < 2)
		return ;
	point = create_vertex(init_vertex(x, y), editor, env);
	if (editor->portal_points[0].x == -1)
		editor->portal_points[0] = *point;
	else if (editor->portal_points[1].x == -1)
	{
		editor->portal_points[1] = *point;
		sector = editor->sector;
		while (sector->prev)
			sector = sector->prev;
		while (sector)
		{
			if (vertex_intersect(env, sector))
			{
				init_portals(editor);
				break ;
			}
			sector = sector->next;
		}
		if (sector == NULL)
			init_portals(editor);
	}
	free(point);
}