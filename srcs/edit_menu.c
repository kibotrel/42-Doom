/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2009/11/19 13:07:32 by reda-con          #+#    #+#             */
/*   Updated: 2019/11/20 13:35:57 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			clic_editor_menu(int x, int y, t_editor *editor)
{
	if (x >= 1340 && x <= 1510)
	{
		if (y >= 140 && y < 210)
			editor->sett = SECTOR;
		else if (y >= 240 && y < 310)
			editor->sett = PLAYER;
		else if (y >= 340 && y < 410)
			editor->sett = ENEMY;
		else if (y >= 440 && y < 510)
			editor->sett = OBJECT;
		else if (y >= 540 && y < 610)
			editor->sett = PORTAL;
		blank_menu(editor->sdl.surf, editor->sett);
	}
}

void			sett_square(int sett, SDL_Surface *s)
{
	rectangle(init_vertex(1350, 150), init_vertex(1400, 200), 0x1e1e1e, s);
	rectangle(init_vertex(1350, 250), init_vertex(1400, 300), 0x1e1e1e, s);
	rectangle(init_vertex(1350, 350), init_vertex(1400, 400), 0x1e1e1e, s);
	rectangle(init_vertex(1350, 450), init_vertex(1400, 500), 0x1e1e1e, s);
	rectangle(init_vertex(1350, 550), init_vertex(1400, 600), 0x1e1e1e, s);
	if (sett == SECTOR)
		rectangle(init_vertex(1350, 150), init_vertex(1400, 200), 0xfeb201, s);
	else if (sett == PLAYER)
		rectangle(init_vertex(1350, 250), init_vertex(1400, 300), 0xfeb201, s);
	else if (sett == ENEMY)
		rectangle(init_vertex(1350, 350), init_vertex(1400, 400), 0xfeb201, s);
	else if (sett == OBJECT)
		rectangle(init_vertex(1350, 450), init_vertex(1400, 500), 0xfeb201, s);
	else if (sett == PORTAL)
		rectangle(init_vertex(1350, 550), init_vertex(1400, 600), 0xfeb201, s);
}

void			display_menu(SDL_Surface *s, int set)
{
	int		x;
	int		y;

	x = EDIT_W;
	while (x < (MENU_W + EDIT_W))
	{
		y = 0;
		while (y < WIN_H)
		{
			put_pixel(s, x, y, 0x1e1e1e);
			++y;
		}
		++x;
	}
	square(1400, 200, 0x0000ff, s);
	square(1400, 300, 0xff00ff, s);
	square(1400, 400, 0xff0000, s);
	square(1400, 500, 0x8b4513, s);
	square(1400, 600, 0x00ff00, s);
	blank_menu(s, set);
	rectangle(init_vertex(1340, 140), init_vertex(1510, 210), 0x5f287e, s);
}

void			motion(t_sdl s, int set)
{
	if (s.event.motion.x >= 1340 && s.event.motion.x <= 1510)
	{
		if (s.event.motion.y >= 140 && s.event.motion.y <= 210)
			rectangle(init_vertex(1340, 140), init_vertex(1510, 210),\
				0x5f287e, s.surf);
		else if (s.event.motion.y >= 240 && s.event.motion.y <= 310)
			rectangle(init_vertex(1340, 240), init_vertex(1510, 310),\
				0x5f287e, s.surf);
		else if (s.event.motion.y >= 340 && s.event.motion.y <= 410)
			rectangle(init_vertex(1340, 340), init_vertex(1510, 410),\
				0x5f287e, s.surf);
		else if (s.event.motion.y >= 440 && s.event.motion.y <= 510)
			rectangle(init_vertex(1340, 440), init_vertex(1510, 510),\
				0x5f287e, s.surf);
		else if (s.event.motion.y >= 540 && s.event.motion.y <= 610)
			rectangle(init_vertex(1340, 540), init_vertex(1510, 610),\
				0x5f287e, s.surf);
		else
			blank_menu(s.surf, set);
	}
	else
		blank_menu(s.surf, set);
}
