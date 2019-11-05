/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:09:05 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/05 15:52:10 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "editor.h"

static int		is_saved(t_editor *editor)
{
	if (editor->map_save == 1)
	{
		ft_putendl("You didn't save, press Esc to quit");
		editor->map_save = 2;
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

static void	display_editor(t_editor *editor)
{
	t_vertex	mouse;

	display_grid(editor);
	display_player(editor->player, &editor->sdl);
	display_entity(editor->sdl, editor->enemy, 0xff0000);
	display_entity(editor->sdl, editor->object, 0x8b4513);
	display_sector(editor);
	display_vertex(&editor->sdl, editor->vertex, 0xffff00);
	if (editor->sett == SECTOR)
	{
		mouse.x = (editor->sdl.event.motion.x / editor->dist_grid) * editor->dist_grid;
		mouse.y = (editor->sdl.event.motion.y / editor->dist_grid) * editor->dist_grid;
		display_vertex(&editor->sdl, &mouse, 0x0ff0f0);
	}
	display_line(editor, editor->sdl.event.motion.x, editor->sdl.event.motion.y);
}

static void	mouse(t_editor *editor, SDL_Event event)
{
	if (editor->sett == SECTOR)
		place_sector(editor, event.motion.x, event.motion.y);
	else if (editor->sett == PLAYER)
		place_player(editor, event.motion.x, event.motion.y);
	else if (editor->sett == ENEMY)
		place_entity(editor, event.motion.x, event.motion.y, 0);
	else if (editor->sett == OBJECT)
		place_entity(editor, event.motion.x, event.motion.y, 1);
	else if (editor->sett == PORTAL)
		place_portal(editor, event.motion.x, event.motion.y);
	editor->map_save = 1;
}

static void	keydown(t_editor *editor, SDL_Event event)
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
	if (editor->sect_is_closed == 1)
	{
		if (event.key.keysym.scancode == SDL_SCANCODE_1)
			editor->sett = SECTOR;
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
		if (SDL_UpdateWindowSurface(editor->sdl.win != 0))
			exit(1);
	}
}