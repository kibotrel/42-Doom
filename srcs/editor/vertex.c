#include "editor.h"
#include "libft.h"

t_vertex		init_vertex(int x, int y)
{
	t_vertex	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_vertex		*create_vertex(t_vertex v, t_editor *edit, t_env *env)
{
	t_vertex	*new;

	if (!(new = (t_vertex*)ft_memalloc(sizeof(t_vertex))))
		clean_editor(edit, env);
	new->x = v.x;
	new->y = v.y;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			add_vertex(t_vertex **vertex, t_vertex v,
	bool flag, t_env *env)
{
	t_vertex	*prev_vertex;
	t_vertex	*new;

	new = create_vertex(v, &env->editor, env);
	if (flag)
		new->vertex_number = env->editor.count.vertex++;
	if (!*vertex)
		*vertex = new;
	else
	{
		prev_vertex = *vertex;
		while (prev_vertex->next)
			prev_vertex = prev_vertex->next;
		new->prev = prev_vertex;
		prev_vertex->next = new;
	}
}

static t_vertex	*is_vertex_double(t_vertex *vertex, int x, int y)
{
	t_vertex	*vert;

	if (!vertex)
		return (NULL);
	vert = vertex;
	while (vert)
	{
		if (vert->x == x && vert->y == y)
			return (vert);
		vert = vert->next;
	}
	return (NULL);
}

t_vertex		*get_vertex(t_editor *editor, int x, int y, t_env *env)
{
	t_vertex	*new_vertex;

	new_vertex = is_vertex_double(editor->vertex, x, y);
	if (!new_vertex)
	{
		new_vertex = create_vertex(init_vertex(x, y), editor, env);
		add_vertex(&editor->vertex, init_vertex(x, y), true, env);
		free(new_vertex);
	}
	editor->last_vertex.x = new_vertex->x;
	editor->last_vertex.y = new_vertex->y;
	return (new_vertex);
}