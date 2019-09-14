/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:22:28 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/09/14 11:56:42 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "SDL.h"
#include <stdio.h>

void		print_all_vertex(t_editor **edit)
{
	t_vertex	*vertex;
	t_vertex	*prev_vertex;

	vertex = (*edit)->vertex;
	prev_vertex = NULL;
	while (vertex)
	{
		if (prev_vertex == NULL)
			put_pixel((*edit)->sdl, vertex->x, vertex->y, 0xFF0000);
		else
			draw_line((*edit)->sdl, *prev_vertex, *vertex, 0xFF00000);
		prev_vertex = vertex;
		vertex = vertex->next;
	}
}

void		print_all(t_editor **edit)
{
	print_grid(*edit);
	print_all_vertex(edit);
}

void		mouse_click(t_editor **edit, SDL_Event event)
{
	get_vertex(edit, event.motion.x, event.motion.y);
}

void		events(t_editor **edit)
{
	t_sdl		*sdl;

	sdl = (*edit)->sdl;
	while ((*edit)->finish)
	{
		while (SDL_PollEvent(&(sdl->event)))
		{
			if (sdl->event.type == SDL_QUIT ||
				(sdl->event.type == SDL_KEYDOWN &&
					sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
					(*edit)->finish = 0;
			if (sdl->event.type == SDL_MOUSEBUTTONDOWN)
				mouse_click(edit, sdl->event);
		}
		print_all(edit);
		if (SDL_UpdateWindowSurface(sdl->win) != 0)
			exit(1);
	}
}