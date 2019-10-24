/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:09:05 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/10/24 13:30:56 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "editor.h"

int		is_saved(t_editor *editor)
{
	if (editor->map_save == 1)
	{
		ft_putendl("You didn't save, press Esc to quit");
		edit->map_save = 2;
		return (1);
	}
	else if (editor->map_save == 2)
	{
		ft_putendl("Exiting without saving");
		return (0);
	}
	ft_putendl("Exiting...");
	return (0);
}

void	display_editor(t_editor *editor)
{
	t_vertex	mouse;

	display_grid(edit);
	display_vertex(edit->sdl, &edit->player, 0xff00ff);
	display_vertex(edit->sdl, edit->ennemi, 0xff0000);
	display_vertex(edit->sdl, edit->object, 0x8b4513);
	display_sector(edit);
	display_vertex(edit->sdl, edit->vertex, 0xffff00);
	if (edit->sett == vertex)
	{
		mouse = create_vertex((edit->sdl->event.motion.x / edit->dist_grid) * edit->dist_grid, (edit->sdl->event.motion.y / edit->dist_grid) * edit->dist_grid);
		display_vertex(edit->sdl, mouse, 0x0ff0f0);
	}
	display_line(edit, edit->sdl->event.motion.x, edit->sdl->event.motion.y);
}

void	mouse(t_editor *editor, SDL_Event event)
{
	if (editor->sett == VERTEX)
		place_vertex(editor, event.motion.x, event.motion.y);
	else if (editor->sett == PLAYER)
		place_player(editor, event.motion.x, event.motion.y);
	else if (editor->sett == ENEMY)
		place_ennemy(editor, event.motion.x, event.motion.y);
	else if (editor->sett == OBJECT)
		place_object(editor, event.motion.x, event.motion.y);
	else if (editor->sett == PORTAL)
		place_portal(editor, event.motion.x, event.motion.y);
	editor->map_save = 1;
}

void	keydown(t_editor *editor, SDL_Event event)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
	{
		if (is_saved(editor) == 0)
			editor->finish = 0;
	}
	if (event.key.keysym.scancode == SDL_SCANCODE_RETURN)
	{
		create_map(editor);
		editor->map_save = 0;
	}
	if (editor->sect_is_closed == TRUE)
	{
		if (event.key.keysym.scancode == SDL_SCANCODE_1)
			editor->sett = VERTEX;
		else if (event.key.keysym.scancode == SDL_SCANCODE_2)
			editor->sett = PLAYER;
		else if (event.key.keysym.scancode == SDL_SCANCODE_3)
			editor->sett = ENEMY;
		else if (event.key.keysym.scancode == SDL_SCANCODE_4)
			editor->sett = OBJECT;
		else if (event.key.keysym.scancode == SDL_SCANCODE_5)
			editor->sett = PORTAL;
	}
}

void	events(t_editor *editor)
{
	while (editor->finish)
	{
		while (SDL_PollEvent(&(editor->sdl.event)))
		{
			if (editor->sdl.event.type == SDL_QUIT)
			{
				if (is_saved(editor) == 0)
					editor->finish = 0;
			}
			else if (editor->sdl.event.type == SDL_KEYDOWN)
				keydown(editor, editor->sdl.event);
			else if (editor->sdl.event.type == SDL_MOUSEBUTTONDOWN)
				mouse(editor, editor->sdl.event);
		}
		display_editor(editor);
		if (SDL_UpdateWindowSurface(editor->sdl.win != 0)
			exit(1);
	}
}