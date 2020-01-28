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

static t_portal	*create_portal(t_vertex v1, t_vertex v2, t_editor *edit, t_env *env)
{
	t_portal	*new;

	if (!(new = (t_portal*)ft_memalloc(sizeof(t_portal))))
		clean_editor(edit, env);
	new->extrems[0] = v1;
	new->extrems[1] = v2;
	new->type = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			add_portal(t_portal **portal, t_vertex v1, t_vertex v2,
	t_env *env)
{
	t_portal	*new;
	t_portal	*prev_portal;

	new = create_portal(v1, v2, &env->editor, env);
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

void			change_portal_type(t_ed_sector *all, t_portal *portal, bool way)
{
	t_ed_sector	*sector;
	t_portal	*port;

	sector = all;
	while (sector->prev)
		sector = sector->prev;
	while (sector)
	{
		port = sector->portal;
		while (port)
		{
			if ((portal->extrems[0].x == port->extrems[0].x &&
				portal->extrems[0].y == port->extrems[0].y &&
					portal->extrems[1].x == port->extrems[1].x &&
						portal->extrems[1].y == port->extrems[1].y) ||
							(portal->extrems[0].x == port->extrems[1].x &&
								portal->extrems[0].y == port->extrems[1].y &&
								portal->extrems[1].x == port->extrems[0].x &&
									portal->extrems[1].y == port->extrems[0].y))
			{
				if (way == true)
					++port->type;
				else
					--port->type;
				if (port->type > 1)
					--port->type;
				else if (port->type < 0)
					++port->type;
			}
			port = port->next;
		}
		sector = sector->next;
	}
}

void			move_in_portals(t_portal **portal, bool way)
{
	t_portal	*tmp;

	if (!*portal)
		return ;
	tmp = *portal;
	if (way == true)
	{
		if (tmp->next)
			tmp = tmp->next;
	}
	else
	{
		if (tmp->prev)
			tmp = tmp->prev;
	}
	*portal = tmp;
}
