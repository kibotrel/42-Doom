#include "editor.h"

void			move_in_sector(t_ed_sector **sector, bool way)
{
	t_ed_sector *tmp;

	if (!*sector)
		return ;
	tmp = *sector;
	if (way == true)
	{
		if (tmp->next->next)
			tmp = tmp->next;
	}
	else
	{
		if (tmp->prev)
			tmp = tmp->prev;
	}
	*sector = tmp;
}

static void		prev_display_sector(t_sdl *sdl, t_ed_sector *sectors)
{
	t_ed_sector	*sect;
	int			i;
	t_vertex	*vertex;

	sect = sectors;
	while (sect)
	{
		i = 0;
		vertex = sect->vertex;
		while (vertex && ++i)
		{
			draw_walls(sdl, sect, vertex, 0x0000ff);
			vertex = vertex->next;
		}
		sect = sect->prev;
	}
}

void			next_display_sector(t_sdl *sdl, t_ed_sector *sectors)
{
	t_ed_sector	*sect;
	int			i;
	t_vertex	*vertex;

	sect = sectors;
	while (sect)
	{
		i = 0;
		vertex = sect->vertex;
		while (vertex && ++i)
		{
			draw_walls(sdl, sect, vertex, 0x0000ff);
			vertex = vertex->next;
		}
		sect = sect->next;
	}
	prev_display_sector(sdl, sectors);
}
