/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:41:22 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/10/17 13:37:40 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "editor.h"
#include "libft.h"

void		print_vertex(t_sdl *sdl, t_vertex *to_print, int color)
{
	t_vertex	*print;

	print = to_print;
	while (print)
	{
		put_pixel(sdl, print->x, print->y, color);
		put_pixel(sdl, print->x + 1, print->y, color);
		put_pixel(sdl, print->x, print->y + 1, color);
		put_pixel(sdl, print->x + 1, print->y + 1, color);
		put_pixel(sdl, print->x - 1, print->y, color);
		put_pixel(sdl, print->x + 1, print->y - 1, color);
		put_pixel(sdl, print->x - 1, print->y + 1, color);
		put_pixel(sdl, print->x, print->y - 1, color);
		put_pixel(sdl, print->x - 1, print->y - 1, color);
		print = print->next;
	}
}

t_vertex 	*create_vertex(int x, int y)
{
	t_vertex	*new;

	if (!(new = (t_vertex*)ft_memalloc(sizeof(t_vertex))))
		exit(1);
	new->x = x;
	new->y = y;
	return (new);
}

void	put_pixel(t_sdl *sdl, int x, int y, int color)
{
	int				*pixel;
	SDL_Surface		*surf;

	surf = sdl->surf;
	if ((x >= 0 && x < WIN_W) && (y >= 0 && y < WIN_H))
	{
		pixel = surf->pixels + y * surf->pitch
			+ x * surf->format->BytesPerPixel;
		*pixel = color;
	}
}

void	draw_line(t_sdl *sdl, t_vertex start, t_vertex end, int color)
{
		t_line		line;

		line.delta_x = abs(end.x - start.x);
		line.delta_y = abs(end.y - start.y);
		line.sign_x = start.x < end.x ? 1 : -1;
		line.sign_y = start.y < end.y ? 1 : -1;
		line.error = line.delta_x - line.delta_y;
		put_pixel(sdl, end.x, end.y, color);
		while (start.x != end.x || start.y != end.y)
		{
			put_pixel(sdl, start.x, start.y, color);
			line.error_2 = line.error * 2;
			if (line.error_2 > -line.delta_y)
			{
				line.error -= line.delta_y;
				start.x += line.sign_x;
			}
			if (line.error_2 < line.delta_x)
			{
				line.error += line.delta_x;
				start.y += line.sign_y;
			}
		}
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
		draw_line(sdl, start, end, color);
	}
	else if (sect->next)
	{
		end.x = sect->vertex->x;
		end.y = sect->vertex->y;
		draw_line(sdl, start, end, color);
	}
	else
		put_pixel(sdl, vertex->x, vertex->y, color);
}

void	print_grid(t_editor *edit)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (x % edit->dist_grid == 0 && y % edit->dist_grid == 0)
				put_pixel(edit->sdl, x, y, 0x9c9c9c);
			else
				put_pixel(edit->sdl, x, y, 0x000000);
			++x;
		}
		++y;
	}
}