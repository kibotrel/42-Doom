/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:43:57 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/04 10:43:57 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			move_in_sector(t_editor *edit, int x, int y)
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

static void		draw_sector_effects(t_sdl *sdl, t_ed_sector *sectors,
	t_editor *edit)
{
	t_ed_sector *sect;
	t_vertex	*vertex;
	int			i;

	sect = sectors;
	while (sect->prev)
		sect = sect->prev;
	while (sect)
	{
		if (sect->effect.effects == edit->effects.effects)
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

static void		draw_sector_plate_door(t_sdl *sdl, t_ed_sector *sectors,
	t_editor *edit)
{
	t_ed_sector *sect;
	t_vertex	*vertex;
	int			color;
	int			number;

	sect = sectors;
	while (sect->prev)
		sect = sect->prev;
	number = EFF_PLATE + edit->count.eff_data[EFF_PLATE];
	while (sect)
	{
		if (sect->effect.effects == number || sect->effect.effects == -number)
		{
			color = 0xff00ff;
			if (sect->effect.effects == number)
				color = 0xffff00;
			vertex = sect->vertex;
			while (vertex)
			{
				draw_walls(sdl, sect, vertex, color);
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

void			next_display_sector(t_sdl *sdl, t_ed_sector *sectors,
	t_editor *edit)
{
	t_ed_sector	*sect;
	t_vertex	*vertex;

	sect = sectors;
	while (sect)
	{
		vertex = sect->vertex;
		while (vertex)
		{
			draw_walls(sdl, sect, vertex, 0x0000ff);
			vertex = vertex->next;
		}
		sect = sect->next;
	}
	prev_display_sector(sdl, sectors);
	if (edit->sett == EFFECTOR && sectors && edit->effects.effects != EFF_PLATE)
		draw_sector_effects(sdl, sectors, edit);
	if (edit->sett == EFFECTOR && edit->effects.effects == EFF_PLATE && sectors)
		draw_sector_plate_door(sdl, sectors, edit);
}
