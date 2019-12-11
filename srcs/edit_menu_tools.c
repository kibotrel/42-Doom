/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_menu_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:14:01 by reda-con          #+#    #+#             */
/*   Updated: 2019/12/11 17:15:55 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			square(int x, int y, int color, SDL_Surface *s)
{
	int		i;
	int		j;

	i = x - 50;
	while (i < x)
	{
		j = y - 50;
		while (j < y)
		{
			put_pixel(s, i, j, color);
			++j;
		}
		++i;
	}
}

void			rectangle(t_vertex start, t_vertex end, int clr, SDL_Surface *s)
{
	draw_line(s, start, init_vertex(start.x, end.y), clr);
	draw_line(s, init_vertex(end.x, start.y), end, clr);
	draw_line(s, start, init_vertex(end.x, start.y), clr);
	draw_line(s, init_vertex(start.x, end.y), end, clr);
}

void			draw_back_ground(SDL_Surface *s)
{
	int		x;
	int		y;

	x = EDIT_W;
	while (x < MENU_W + EDIT_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			put_pixel(s, x, y, 0x1e1e1e);
			++y;
		}
		++x;
	}
}

void			next_blank_menu(int set, SDL_Surface *s)
{
	if (set == ENEMY || set == OBJECT || set == SECTOR)
	{
		square(1600, 500, 0xff00ff, s);
		square(1600, 600, 0x00ffff, s);
		if (set != SECTOR)
			square(1600, 700, 0x0000ff, s);
		rectangle(init_vertex(1540, 440), init_vertex(1710, 510), 0xffffff, s);
		rectangle(init_vertex(1540, 540), init_vertex(1710, 610), 0xffffff, s);
		if (set != SECTOR)
			rectangle(init_vertex(1540, 640), init_vertex(1710, 710), 0xffffff, s);
	}
	if (set != PORTAL)
	{
		square(1600, 200, 0x181279, s);
		square(1600, 300, 0x261017, s);
		square(1600, 400, 0x270139, s);
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), 0xffffff, s);
		rectangle(init_vertex(1540, 240), init_vertex(1710, 310), 0xffffff, s);
		rectangle(init_vertex(1540, 340), init_vertex(1710, 410), 0xffffff, s);
		rectangle(init_vertex(1340, 540), init_vertex(1510, 610), 0xffffff, s);
	}
}
