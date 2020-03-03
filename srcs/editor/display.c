/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:53:31 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/03 14:54:34 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "libft.h"

void	display_portals(t_portal *portal, t_sdl *sdl, int color)
{
	t_portal	*print;

	print = portal;
	while (print)
	{
		draw_ed_line(sdl->screen, print->extrems[0], print->extrems[1], color);
		print = print->prev;
	}
	print = portal;
	while (print)
	{
		draw_ed_line(sdl->screen, print->extrems[0], print->extrems[1], color);
		print = print->next;
	}
}

void	draw_walls(t_sdl *sdl, t_ed_sector *sect, t_vertex *vertex, int color)
{
	t_vertex	start;
	t_vertex	end;

	start.x = vertex->x;
	start.y = vertex->y;
	if (vertex->next)
	{
		end.x = vertex->next->x;
		end.y = vertex->next->y;
		draw_ed_line(sdl->screen, start, end, color);
	}
	else if (sect->next)
	{
		end.x = sect->vertex->x;
		end.y = sect->vertex->y;
		draw_ed_line(sdl->screen, start, end, color);
	}
	else
		put_pixel(sdl->screen, vertex->x, vertex->y, color);
}

void	display_sector(t_sdl *sdl, t_ed_sector *sector, bool fl, t_editor *edit)
{
	int			i;
	t_ed_sector	*sect;
	t_vertex	*vertex;

	next_display_sector(sdl, sector, edit);
	if (sector && fl == true)
	{
		i = 0;
		sect = sector;
		vertex = sect->vertex;
		while (vertex && ++i)
		{
			draw_walls(sdl, sector, vertex, 0xffff00);
			vertex = vertex->next;
		}
	}
}

void	display_line(t_editor *editor, int x, int y, t_env *env)
{
	t_vertex	act_pos;

	if (x < 0 || y < 0 || x > EDIT_W || y > EDIT_H)
		return ;
	act_pos.x = (x / editor->true_grid) * editor->true_grid;
	act_pos.y = (y / editor->true_grid) * editor->true_grid;
	if (editor->last_vertex.x != -1 && editor->last_vertex.y != -1)
		draw_ed_line(env->sdl.screen, editor->last_vertex, act_pos, 0x0ff0f0);
}

void	display_grid(t_editor *editor, t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < EDIT_H)
	{
		x = 0;
		while (x < EDIT_W)
		{
			if (x % editor->true_grid == 0 && y % editor->true_grid == 0 &&
				editor->grid != -1)
				put_pixel(env->sdl.screen, x, y, 0x9c9c9c);
			else
				put_pixel(env->sdl.screen, x, y, 0x000000);
			++x;
		}
		++y;
	}
}
