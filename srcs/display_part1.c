/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 08:56:26 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/13 11:42:44 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "libft.h"

void	display_portals(t_portal *portal, t_sdl *sdl, int color, bool fl)
{
	t_portal	*print;

	print = portal;
	while (print)
	{
		draw_line(sdl->surf, print->extrems[0], print->extrems[1], color);
		print = print->prev;
	}
	print = portal;
	while (print)
	{
		draw_line(sdl->surf, print->extrems[0], print->extrems[1], color);
		print = print->next;
	}
	if (portal && fl == true)
		draw_line(sdl->surf, portal->extrems[0], portal->extrems[1], 0xffff00);
}

void	draw_walls(t_sdl *sdl, t_sector *sect, t_vertex *vertex, int color)
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

void	display_sector(t_sdl *sdl, t_sector *sectors, bool fl)
{
	int			i;
	t_sector	*sect;
	t_vertex	*vertex;

	next_display_sector(sdl, sectors);
	if (sectors && fl == true)
	{
		i = 0;
		sect = sectors;
		vertex = sect->vertex;
		while (vertex && ++i)
		{
			draw_walls(sdl, sectors, vertex, 0xffff00);
			vertex = vertex->next;
		}
	}
}

void	display_line(t_editor *editor, int x, int y)
{
	t_vertex	act_pos;

	if (x < 0 || y < 0 || x > EDIT_W || y > WIN_H)
		return ;
	act_pos.x = (x / editor->dist_grid) * editor->dist_grid;
	act_pos.y = (y / editor->dist_grid) * editor->dist_grid;
	if (editor->last_vertex.x != -1 && editor->last_vertex.y != -1)
		draw_line(editor->sdl.surf, editor->last_vertex, act_pos, 0x0ff0f0);
}

void	display_grid(t_editor *editor)
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
