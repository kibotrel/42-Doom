/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 08:56:26 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/15 15:54:14 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static int	get_wall_color(t_sector *sect, int *i)
{
	if (sect->is_portal != NULL && *i >= sect->vertex_count)
		*i = 0;
	if (sect->is_portal != NULL && sect->is_portal[*i] != -1)
		return (0x00ff00);
	else
		return (0x0000ff);
}

static void	draw_walls(t_sdl *sdl, t_sector *sect, t_vertex *vertex, int color)
{
	t_vertex	start;
	t_vertex	end;

	start.x = vertex->x;
	start.y = vertex->y;
	if (vertex->next)
	{
		end.x = vertex->next->x;
		end.y = vertex->next->y;
		draw_line(sdl->surf, start, end, color);
	}
	else if (sect->next)
	{
		end.x = sect->vertex->x;
		end.y = sect->vertex->y;
		draw_line(sdl->surf, start, end, color);
	}
	else
		put_pixel(sdl->surf, vertex->x, vertex->y, color);
}

void		display_sector(t_editor *editor)
{
	int			i;
	t_sector	*sect;
	t_vertex	*vertex;

	sect = editor->sector;
	while (sect)
	{
		i = 0;
		vertex = sect->vertex;
		while (vertex && ++i)
		{
			draw_walls(&editor->sdl, sect, vertex, get_wall_color(sect, &i));
			vertex = vertex->next;
		}
		sect = sect->next;
	}
}

void		display_line(t_editor *editor, int x, int y)
{
	t_vertex	act_pos;

	if (x < 0 || y < 0 || x > EDIT_W || y > WIN_H)
		return ;
	act_pos.x = (x / editor->dist_grid) * editor->dist_grid;
	act_pos.y = (y / editor->dist_grid) * editor->dist_grid;
	if (editor->last_vertex.x != -1 && editor->last_vertex.y != -1)
		draw_line(editor->sdl.surf, editor->last_vertex, act_pos, 0x0ff0f0);
}

void		display_grid(t_editor *editor)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < EDIT_W)
		{
			if (x % editor->dist_grid == 0 && y % editor->dist_grid == 0)
				put_pixel(editor->sdl.surf, x, y, 0x9c9c9c);
			else
				put_pixel(editor->sdl.surf, x, y, 0x000000);
			++x;
		}
		++y;
	}
}
