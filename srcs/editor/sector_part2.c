#include "editor.h"

void		move_in_sector(t_editor *edit, int x, int y)
{
	int			which_sector;
	t_ed_sector	*sect;

	which_sector = is_in_sector(edit, init_vertex(x, y));
	if (which_sector < 0)
		return ;
	sect = edit->sector;
	while (sect->prev)
		sect = sect->prev;
	while (sect)
	{
		if (sect->sector_number == which_sector)
		{
			edit->sector = sect;
			return ;
		}
		sect = sect->next;
	}
}

static void		draw_sector_effects(t_sdl *sdl, t_ed_sector *sectors, t_editor *edit)
{
	t_ed_sector *sect;
	t_vertex	*vertex;
	int			i;

	sect = sectors;
	while (sect->prev)
		sect = sect->prev;
	while (sect)
	{
		if (sect->effect.effects == edit->effects)
		{
			i = 0;
			vertex = sect->vertex;
			while (vertex && ++i)
			{
				draw_walls(sdl, sect, vertex, 0xffff00);
				vertex = vertex->next;
			}
		}
		sect = sect->next;
	}
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

void			next_display_sector(t_sdl *sdl, t_ed_sector *sectors, t_editor *edit)
{
	t_ed_sector	*sect;
	int			i;
	t_vertex	*vertex;

	sect = sectors;
	while (sect)
	{
		if (sect->effect.effects == edit->effects && edit->sett == EFFECTOR)
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
	if (edit->sett == EFFECTOR)
		draw_sector_effects(sdl, sectors, edit);
}
