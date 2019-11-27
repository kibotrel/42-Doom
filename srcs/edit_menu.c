/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2009/11/19 13:07:32 by reda-con          #+#    #+#             */
/*   Updated: 2019/11/27 17:15:27 by reda-con         ###   ########.fr       */
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
		blank_menu(editor->sdl.surf, editor->sett, editor->sdl);
	}
}

#include <stdio.h>
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
			blank_menu(s.surf, set, s);
	}
	else if (s.event.motion.x >= 1540 && s.event.motion.x <= 1710)
	{
		if (set != PORTAL && s.event.motion.y >= 140 && s.event.motion.y <= 210)
			rectangle(init_vertex(1540, 140), init_vertex(1710, 210), 0x5f287e, s.surf);
		else if (set != PORTAL && s.event.motion.y >= 240 && s.event.motion.y <= 310)
			rectangle(init_vertex(1540, 240), init_vertex(1710, 310), 0x5f287e, s.surf);
		else if (set != PORTAL && s.event.motion.y >= 340 && s.event.motion.y <= 410)
			rectangle(init_vertex(1540, 340), init_vertex(1710, 410), 0x5f287e, s.surf);
		else if ((set == ENEMY || set == OBJECT) && s.event.motion.y >= 440 && s.event.motion.y <= 510)
			rectangle(init_vertex(1540, 440), init_vertex(1710, 510), 0x5f287e, s.surf);
		else if ((set == ENEMY || set == OBJECT) && s.event.motion.y >= 540 && s.event.motion.y <= 610)
			rectangle(init_vertex(1540, 540), init_vertex(1710, 610), 0x5f287e, s.surf);
		else if ((set == ENEMY || set == OBJECT) && s.event.motion.y >= 640 && s.event.motion.y <= 710)
			rectangle(init_vertex(1540, 640), init_vertex(1710, 710), 0x5f287e, s.surf);
		else
			blank_menu(s.surf, set, s);
	}
	else
		blank_menu(s.surf, set, s);
}
