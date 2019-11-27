/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_menu_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:14:01 by reda-con          #+#    #+#             */
/*   Updated: 2019/11/27 14:22:30 by reda-con         ###   ########.fr       */
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

t_vertex		init_vertex(int x, int y)
{
	t_vertex	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

void			rectangle(t_vertex start, t_vertex end, int clr, SDL_Surface *s)
{
	draw_line(s, start, init_vertex(start.x, end.y), clr);
	draw_line(s, init_vertex(end.x, start.y), end, clr);
	draw_line(s, start, init_vertex(end.x, start.y), clr);
	draw_line(s, init_vertex(start.x, end.y), end, clr);
}

void			blank_menu(SDL_Surface *s, int set)
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
	if (set != SECTOR)
		rectangle(init_vertex(1340, 140), init_vertex(1510, 210), 0xffffff, s);
	else
		rectangle(init_vertex(1340, 140), init_vertex(1510, 210), 0x0000ff, s);
	if (set != PLAYER)
		rectangle(init_vertex(1340, 240), init_vertex(1510, 310), 0xffffff, s);
	else
		rectangle(init_vertex(1340, 240), init_vertex(1510, 310), 0xff00ff, s);
	if (set != ENEMY)
		rectangle(init_vertex(1340, 340), init_vertex(1510, 410), 0xffffff, s);
	else
		rectangle(init_vertex(1340, 340), init_vertex(1510, 410), 0xff0000, s);
	if (set != OBJECT)
		rectangle(init_vertex(1340, 440), init_vertex(1510, 510), 0xffffff, s);
	else
		rectangle(init_vertex(1340, 440), init_vertex(1510, 510), 0x8b4513, s);
	if (set != PORTAL)
		rectangle(init_vertex(1340, 540), init_vertex(1510, 610), 0xffffff, s);
	else
		rectangle(init_vertex(1340, 540), init_vertex(1510, 610), 0x177013, s);
	rectangle(init_vertex(1350, 250), init_vertex(1400, 300), 0xffa500, s);
	rectangle(init_vertex(1350, 150), init_vertex(1400, 200), 0xffa500, s);
	rectangle(init_vertex(1350, 450), init_vertex(1400, 500), 0xffa500, s);
	rectangle(init_vertex(1350, 350), init_vertex(1400, 400), 0xffa500, s);
	rectangle(init_vertex(1350, 550), init_vertex(1400, 600), 0xffa500, s);
}
