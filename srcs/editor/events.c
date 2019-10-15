/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:22:28 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/10/15 10:50:16 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "SDL.h"
#include "libft.h"

void		print_line(t_editor *edit, int x, int y)
{
	t_vertex	*act_pos;
	if (x < 0 || y < 0 || x > WIN_W || y > WIN_H)
		return ;
	act_pos = create_vertex((x / edit->dist_grid) * edit->dist_grid, (y / edit->dist_grid) * edit->dist_grid);
	if (edit->last_vertex->x != -1 && edit->last_vertex->y != -1)
		draw_line(edit->sdl, *edit->last_vertex, *act_pos, 0x0ff0f0);
}

void		print_all(t_editor *edit)
{
	print_grid(edit);
	print_player(edit, 0xffffff);
	print_ennemy(edit, 0xff0000);
	print_object(edit, 0x00ff00);
	print_sector(edit);
	print_line(edit, edit->sdl->event.motion.x, edit->sdl->event.motion.y);
}

void		mouse_click(t_editor **edit, SDL_Event event)
{
		if ((*edit)->sett == vertex)
			get_sector(edit, event.motion.x, event.motion.y);
		else if ((*edit)->sett == player)
			place_player(edit, event.motion.x, event.motion.y);
		else if ((*edit)->sett == ennemi)
			get_ennemy(edit, event.motion.x, event.motion.y);
		else if ((*edit)->sett == object)
			get_object(edit, event.motion.x, event.motion.y);
		else if ((*edit)->sett == portal)
			create_portal(edit, event.motion.x, event.motion.y);
}

void		key_press(t_editor **edit, SDL_Event event)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		(*edit)->finish = 0;
	if ((*edit)->sect_is_closed == 1)
	{	
		if (event.key.keysym.scancode == SDL_SCANCODE_1)
			(*edit)->sett = vertex;
		else if (event.key.keysym.scancode == SDL_SCANCODE_2)
			(*edit)->sett = player;
		else if (event.key.keysym.scancode == SDL_SCANCODE_3)
			(*edit)->sett = ennemi;
		else if (event.key.keysym.scancode == SDL_SCANCODE_4)
			(*edit)->sett = object;
		else if (event.key.keysym.scancode == SDL_SCANCODE_5)
			(*edit)->sett = portal;
	}
}

void		events(t_editor **edit)
{
	t_sdl		*sdl;
	t_editor	*editor;

	editor = *(edit);
	sdl = editor->sdl;
	while (editor->finish)
	{
		while (SDL_PollEvent(&(sdl->event)))
		{
			if (sdl->event.type == SDL_QUIT)
				(*edit)->finish = 0;
			if (sdl->event.type == SDL_KEYDOWN)
				key_press(edit, sdl->event);
			if (sdl->event.type == SDL_MOUSEBUTTONDOWN)
				mouse_click(edit, sdl->event);
		}
		print_all(*edit);
		if (SDL_UpdateWindowSurface(sdl->win) != 0)
			exit(1);
	}
}