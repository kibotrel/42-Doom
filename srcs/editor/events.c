/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:22:28 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/09/17 14:38:11 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "SDL.h"

void		print_all(t_editor *edit)
{
	print_grid(edit);
	print_player(edit, 0xffffff);
	print_ennemy(edit, 0xff0000);
	print_object(edit, 0x00ff00);
	print_all_vertex(edit);
}

void		mouse_click(t_editor *edit, SDL_Event event)
{
	if (edit->sett == vertex)
		get_vertex(edit, event.motion.x, event.motion.y);
	if (edit->sett == player)
		place_player(edit, event.motion.x, event.motion.y);
	if (edit->sett == ennemi)
		get_ennemy(edit, event.motion.x, event.motion.y);
	if (edit->sett == object)
		get_object(edit, event.motion.x, event.motion.y);
}

void		key_press(t_editor *edit, SDL_Event event)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		edit->finish = 0;
	if (event.key.keysym.scancode == SDL_SCANCODE_1)
		edit->sett = vertex;
	if (event.key.keysym.scancode == SDL_SCANCODE_2)
		edit->sett = player;
	if (event.key.keysym.scancode == SDL_SCANCODE_3)
		edit->sett = ennemi;
	if (event.key.keysym.scancode == SDL_SCANCODE_4)
		edit->sett = object;
}

void		events(t_editor *edit)
{
	t_sdl		*sdl;

	sdl = edit->sdl;
	while (edit->finish)
	{
		while (SDL_PollEvent(&(sdl->event)))
		{
			if (sdl->event.type == SDL_QUIT)
				edit->finish = 0;
			if (sdl->event.type == SDL_KEYDOWN)
				key_press(edit, sdl->event);
			if (sdl->event.type == SDL_MOUSEBUTTONDOWN)
				mouse_click(edit, sdl->event);
		}
		print_all(edit);
		if (SDL_UpdateWindowSurface(sdl->win) != 0)
			exit(1);
	}
}