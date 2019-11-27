/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:05:02 by reda-con          #+#    #+#             */
/*   Updated: 2019/11/27 16:47:20 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	next_keydown(SDL_Event event, SDL_Surface *s, t_editor *editor)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_1)
	{
		editor->sett = SECTOR;
		rectangle(init_vertex(1340, 140), init_vertex(1510, 210), 0x5f287e, s);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_2)
	{
		editor->sett = PLAYER;
		rectangle(init_vertex(1340, 240), init_vertex(1510, 310), 0x5f287e, s);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_3)
	{
		editor->sett = ENEMY;
		rectangle(init_vertex(1340, 340), init_vertex(1510, 410), 0x5f287e, s);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_4)
	{
		editor->sett = OBJECT;
		rectangle(init_vertex(1340, 440), init_vertex(1510, 510), 0x5f287e, s);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_5)
	{
		editor->sett = PORTAL;
		rectangle(init_vertex(1340, 540), init_vertex(1510, 610), 0x5f287e, s);
	}
}
