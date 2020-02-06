#include "libft.h"
#include "editor.h"

int				search_vertex_num(t_vertex *all, t_vertex *to_find)
{
	t_vertex	*vertex;

	vertex = all;
	while (vertex)
	{
		if (vertex->x == to_find->x && vertex->y == to_find->y)
			return (vertex->vertex_number);
		vertex = vertex->next;
	}
	return (-1);
}

static int		count_entity(t_ed_entity *all_entity)
{
	t_ed_entity *entity;

	if (!all_entity)
		return (0);
	entity = all_entity;
	while (entity->next)
		entity = entity->next;
	return (entity->number + 1);
}

int				count_sector(t_ed_sector *all_sector)
{
	t_ed_sector	*sector;

	if (!all_sector)
		return (0);
	sector = all_sector;
	while (sector->next)
		sector = sector->next;
	return (sector->sector_number);
}

static int		count_vertex(t_ed_sector *all_vertex)
{
	t_ed_sector	*sect;
	t_vertex	*vertex;
	int			i;

	if (!all_vertex)
		return (0);
	sect = all_vertex;
	while (sect->prev)
		sect = sect->prev;
	i = 0;
	while (sect)
	{
		vertex = sect->vertex;
		while (vertex)
		{
			vertex = vertex->next;
			++i;
		}
		sect = sect->next;
	}
	return (i);
}

void			get_elements_number(t_editor *editor, int fd)
{
	ft_putstr_fd("total vertexes ", fd);
	ft_putnbr_fd(count_vertex(editor->sector), fd);
	ft_putstr_fd(" sectors ", fd);
	ft_putnbr_fd(count_sector(editor->sector), fd);
	ft_putstr_fd(" enemies ", fd);
	ft_putnbr_fd(count_entity(editor->enemy), fd);
	ft_putstr_fd(" objects ", fd);
	ft_putnbr_fd(count_entity(editor->object), fd);
	ft_putstr_fd("\n\n", fd);
}
