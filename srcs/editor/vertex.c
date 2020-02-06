#include "editor.h"
#include "libft.h"

t_vertex		init_vertex(int x, int y)
{
	t_vertex	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_vertex		*create_vertex(t_vertex v, t_editor *edit, t_env *env, int num)
{
	t_vertex	*new;

	if (!(new = (t_vertex*)ft_memalloc(sizeof(t_vertex))))
		clean_editor(edit, env);
	new->x = v.x;
	new->y = v.y;
	if (num >= 0)
		new->vertex_number = num;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			add_vertex(t_vertex **vertex, t_vertex *v, t_env *env)
{
	t_vertex	*prev_vertex;

(void)env;
	if (!*vertex)
		*vertex = v;
	else
	{
		prev_vertex = *vertex;
		while (prev_vertex->next)
			prev_vertex = prev_vertex->next;
		v->prev = prev_vertex;
		prev_vertex->next = v;
	}
}

static t_vertex	*is_vertex_double(t_ed_sector *sector, int x, int y)
{
	t_ed_sector	*sect;
	t_vertex	*vert;

	if (!sector)
		return (NULL);
	sect = sector;
	while (sector->prev)
		sector = sector->prev;
	while (sector)
	{
		vert = sector->vertex;
		while (vert)
		{
			if (vert->x == x && vert->y == y)
			{
				printf("peut\n");
				return (vert);
			}
			vert = vert->next;
		}
		sector = sector->next;
	}
	return (NULL);
}

t_vertex		*get_vertex(t_editor *editor, int x, int y, t_env *env)
{
	t_vertex	*new_vertex;

	new_vertex = is_vertex_double(editor->sector, x, y);
	if (!new_vertex)
		new_vertex = create_vertex(init_vertex(x, y), editor, env, editor->count.vertex++);
	editor->last_vertex.x = new_vertex->x;
	editor->last_vertex.y = new_vertex->y;
	return (create_vertex(init_vertex(x, y), editor, env, new_vertex->vertex_number));
}
