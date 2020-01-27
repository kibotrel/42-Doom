#include "editor.h"
#include "libft.h"

void	display_portals(t_portal *portal, t_sdl *sdl, int color, bool fl)
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
	if (portal && fl == true)
		draw_ed_line(sdl->screen, portal->extrems[0], portal->extrems[1], 0xffff00);
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

void	display_sector(t_sdl *sdl, t_ed_sector *sectors, bool fl)
{
	int			i;
	t_ed_sector	*sect;
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
	act_pos.x = (x / editor->true_grid) * editor->true_grid;
	act_pos.y = (y / editor->true_grid) * editor->true_grid;
	if (editor->last_vertex.x != -1 && editor->last_vertex.y != -1)
		draw_ed_line(editor->sdl.screen, editor->last_vertex, act_pos, 0x0ff0f0);
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
			if (x % editor->true_grid == 0 && y % editor->true_grid == 0 &&
				editor->grid)
				put_pixel(editor->sdl.screen, x, y, 0x9c9c9c);
			else
				put_pixel(editor->sdl.screen, x, y, 0x000000);
			++x;
		}
		++y;
	}
}
