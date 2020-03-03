#include "clean.h"
#include "libft.h"
#include "editor.h"

int				compare_coordinates(t_vertex *point, t_vertex *a, t_vertex *b)
{
	if (point->x == a->x && point->y == a->y)
		return (1);
	if (point->x == b->x && point->y == b->y)
		return (1);
	return (0);
}

static t_portal	*create_portal(t_vertex v1, t_vertex v2, t_env *env)
{
	t_portal	*new;

	if (!(new = (t_portal*)ft_memalloc(sizeof(t_portal))))
		clean(env, E_EDIT_PORTAL);
	new->extrems[0] = v1;
	new->extrems[1] = v2;
	new->type = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			delete_portal(t_portal **portal, t_vertex v1, t_vertex v2)
{
	t_portal	*tf;
	t_portal	*tmp;
	t_portal	*tmp2;

	if (*portal == NULL)
		return ;
	tmp = NULL;
	tmp2 = NULL;
	tf = *portal;
	while (tf)
	{
		if (tf->extrems[0].x == v1.x && tf->extrems[0].y == v1.y &&
			tf->extrems[1].x == v2.x && tf->extrems[1].y == v2.y)
		{
			if (tf->prev)
				tmp = tf->prev;
			if (tf->next)
				tmp2 = tf->next;
			free(tf);
			if (tmp)
				tmp->next = tmp2;
			if (tmp2)
				tmp2->prev = tmp;
			if (tmp)
				*portal = tmp;
			else if (tmp2)
				*portal = tmp2;
			else
				*portal = NULL;
		}
		tf = tf->next;
	}
}

void			add_portal(t_portal **portal, t_vertex v1, t_vertex v2,
	t_env *env)
{
	t_portal	*new;
	t_portal	*prev_portal;

	new = create_portal(v1, v2, env);
	if (!*portal)
		*portal = new;
	else
	{
		prev_portal = *portal;
		while (prev_portal->next)
			prev_portal = prev_portal->next;
		new->prev = prev_portal;
		prev_portal->next = new;
	}
}