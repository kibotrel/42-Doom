/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2009/11/19 13:07:32 by reda-con          #+#    #+#             */
/*   Updated: 2019/11/27 15:24:46 by nde-jesu         ###   ########.fr       */
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

void			sett_square(int sett, SDL_Surface *s, t_sdl *sdl)
{
	if (sett == SECTOR)
	{
		square(1600, 200, 0xff0000, s);
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), 0xffffff, s);
		square(1600, 300, 0xffff00, s);
		rectangle(init_vertex(1540, 240), init_vertex(1710, 310), 0xffffff, s);
		square(1600, 400, 0x177013, s);
		rectangle(init_vertex(1540, 340), init_vertex(1710, 410), 0xffffff, s);
	}
	else if (sett == PLAYER)
	{
		square(1600, 200, 0xff0000, s);
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), 0xffffff, s);
		square(1600, 300, 0xffff00, s);
		rectangle(init_vertex(1540, 240), init_vertex(1710, 310), 0xffffff, s);
	}
	else if (sett == ENEMY)
	{
		square(1600, 200, 0xff0000, s);
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), 0xffffff, s);
		square(1600, 300, 0xffff00, s);
		rectangle(init_vertex(1540, 240), init_vertex(1710, 310), 0xffffff, s);
		square(1600, 400, 0x177013, s);
		rectangle(init_vertex(1540, 340), init_vertex(1710, 410), 0xffffff, s);
		square(1600, 500, 0xff00ff, s);
		rectangle(init_vertex(1540, 440), init_vertex(1710, 510), 0xffffff, s);
		square(1600, 600, 0x00ffff, s);
		rectangle(init_vertex(1540, 540), init_vertex(1710, 610), 0xffffff, s);
	}
	else if (sett == OBJECT)
	{
		square(1600, 200, 0xff0000, s);
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), 0xffffff, s);
		square(1600, 300, 0xffff00, s);
		rectangle(init_vertex(1540, 240), init_vertex(1710, 310), 0xffffff, s);
		square(1600, 400, 0x177013, s);
		rectangle(init_vertex(1540, 340), init_vertex(1710, 410), 0xffffff, s);
		square(1600, 500, 0xff00ff, s);
		rectangle(init_vertex(1540, 440), init_vertex(1710, 510), 0xffffff, s);
		square(1600, 600, 0x00ffff, s);
		rectangle(init_vertex(1540, 540), init_vertex(1710, 610), 0xffffff, s);
	}
	print_param_in_param(sdl, sett);
}

void			display_menu(SDL_Surface *s, int set)
{
	blank_menu(s, set);
}

void			motion(t_sdl s, int set)
{
	if (s.event.motion.x >= 1340 && s.event.motion.x <= 1510)
	{
		if ((s.event.motion.y >= 140 && s.event.motion.y <= 210))
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
