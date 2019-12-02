/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2009/11/19 13:07:32 by reda-con          #+#    #+#             */
/*   Updated: 2019/12/02 09:37:33 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			blank_menu(SDL_Surface *s, int set, t_sdl sdl)
{
	int		clr;

	draw_back_ground(s);
	clr = ((set != SECTOR) ? 0xffffff : 0x289655);
	rectangle(init_vertex(1340, 140), init_vertex(1510, 210), clr, s);
	clr = ((set != PLAYER) ? 0xffffff : 0x177489);
	rectangle(init_vertex(1340, 240), init_vertex(1510, 310), clr, s);
	clr = ((set != ENEMY) ? 0xffffff : 0x090875);
	rectangle(init_vertex(1340, 340), init_vertex(1510, 410), clr, s);
	clr = ((set != OBJECT) ? 0xffffff : 0x146595);
	rectangle(init_vertex(1340, 440), init_vertex(1510, 510), clr, s);
	clr = ((set != PORTAL) ? 0xffffff : 0x177013);
	rectangle(init_vertex(1340, 540), init_vertex(1510, 610), clr, s);
	next_blank_menu(set, s);
	rectangle(init_vertex(1350, 250), init_vertex(1400, 300), 0xffa500, s);
	rectangle(init_vertex(1350, 150), init_vertex(1400, 200), 0xffa500, s);
	rectangle(init_vertex(1350, 450), init_vertex(1400, 500), 0xffa500, s);
	rectangle(init_vertex(1350, 350), init_vertex(1400, 400), 0xffa500, s);
	rectangle(init_vertex(1350, 550), init_vertex(1400, 600), 0xffa500, s);
	print_param_in_param(&sdl, set);
}

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
		blank_menu(editor->sdl.surf, editor->sett, editor->sdl);
	}
}
#include <stdio.h>
void			next_motion(t_editor *editor, t_sdl s, int set)
{
	int		y;

	y = s.event.motion.y;
	if (set != PORTAL && y >= 140 && y <= 210)
	{			
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), PRPL, s.surf);
		if (set == PLAYER)
		rotate_player(&editor->player, true);
	}
	else if (set != PORTAL && y >= 240 && y <= 310)
	{
		rectangle(init_vertex(1540, 240), init_vertex(1710, 310), PRPL, s.surf);
		rotate_player(&editor->player, false);
	}
	else if (set != PORTAL && y >= 340 && y <= 410)
	{
		rectangle(init_vertex(1540, 340), init_vertex(1710, 410), PRPL, s.surf);
		delete_player(&editor->player);
	}
	else if ((set == ENEMY || set == OBJECT) && y >= 440 && y <= 510)
		rectangle(init_vertex(1540, 440), init_vertex(1710, 510), PRPL, s.surf);
	else if ((set == ENEMY || set == OBJECT) && y >= 540 && y <= 610)
		rectangle(init_vertex(1540, 540), init_vertex(1710, 610), PRPL, s.surf);
	else if ((set == ENEMY || set == OBJECT) && y >= 640 && y <= 710)
		rectangle(init_vertex(1540, 640), init_vertex(1710, 710), PRPL, s.surf);
	else
		blank_menu(s.surf, set, s);
}

void			motion(t_editor *editor, t_sdl s, int set)
{
	if (s.event.motion.x >= 1340 && s.event.motion.x <= 1510)
	{
		if ((s.event.motion.y >= 140 && s.event.motion.y <= 210))
			rectangle(init_vertex(1340, 140), init_vertex(1510, 210),\
					PRPL, s.surf);
		else if (s.event.motion.y >= 240 && s.event.motion.y <= 310)
			rectangle(init_vertex(1340, 240), init_vertex(1510, 310),\
					PRPL, s.surf);
		else if (s.event.motion.y >= 340 && s.event.motion.y <= 410)
			rectangle(init_vertex(1340, 340), init_vertex(1510, 410),\
					PRPL, s.surf);
		else if (s.event.motion.y >= 440 && s.event.motion.y <= 510)
			rectangle(init_vertex(1340, 440), init_vertex(1510, 510),\
					PRPL, s.surf);
		else if (s.event.motion.y >= 540 && s.event.motion.y <= 610)
			rectangle(init_vertex(1340, 540), init_vertex(1510, 610),\
					PRPL, s.surf);
		else
			blank_menu(s.surf, set, s);
	}
	else if (s.event.motion.x >= 1540 && s.event.motion.x <= 1710)
		next_motion(editor, s, set);
	else
		blank_menu(s.surf, set, s);
}
