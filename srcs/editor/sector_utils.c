#include "libft.h"
#include "editor.h"

t_ed_sector	*create_sector(t_editor *edit, t_env *env)
{
	t_ed_sector	*sect;

	if (!(sect = (t_ed_sector*)ft_memalloc(sizeof(t_ed_sector))))
		clean_editor(edit, env);
	sect->sector_number = edit->count.sector++;
	sect->h_ceil = 20;
	sect->h_floor = 0;
	sect->vertex_count = 0;
	sect->texture = 0;
	sect->type = 0;
	sect->gravity = 10;
	sect->friction = 50;
	sect->next = NULL;
	sect->prev = NULL;
	return (sect);
}

static int		oui(t_vertex *vertex, t_ed_sector *sector)
{
	t_ed_sector	*sect;
	t_vertex	*vert_1;
	t_vertex	*vert_2;
	int			ret;
	int			minus;

	ret = 0;
	minus = 0;
	vert_1 = vertex;
	sect = sector;
	while (vert_1)
	{
		while (sect->prev)
			sect = sect->prev;
		while (sect && sect->sector_number < sector->sector_number)
		{
			vert_2 = sect->vertex;
			while (vert_2)
			{
				if (vert_2->x == vert_1->x && vert_2->y == vert_1->y)
					++minus;
				vert_2 = vert_2->next;
			}
			sect = sect->next;
		}
		++ret;
		vert_1 = vert_1->next;
	}
	return (ret - minus);
}

void	delete_sector_in_progress(t_ed_sector **sector,t_editor *edit)
{
	t_ed_sector	*sect;

	if (edit->sect_is_closed)
		return ;
	sect = *sector;
	while (sect->next)
		sect = sect->next;
	edit->count.vertex -= oui(sect->vertex, sect);
	delete_vertex(&sect->vertex);
	edit->sect_is_closed = true;
}