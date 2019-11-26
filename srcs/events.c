/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:09:05 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/26 09:41:11 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "editor.h"

static bool		is_saved(t_editor *editor)
{
	if (editor->map_save == false)
	{
		ft_putendl("You didn't save, press Esc to quit");
		editor->map_save = true;
		return (false);
	}
	else
	{
		ft_putendl("Exiting...");
		return (true);
	}
}

static void		display_editor(t_editor *editor)
{
	t_vertex	mouse;

	display_grid(editor);
	display_player(editor->player, &editor->sdl);
	display_entities(&editor->sdl, editor->enemy, 0xff0000);
	display_entities(&editor->sdl, editor->object, 0x8b4513);
	display_sector(editor);
	display_vertex(&editor->sdl, editor->vertex, 0xffff00);
	if (editor->sett == SECTOR && editor->sdl.event.motion.x <= EDIT_W)
	{
		mouse.x = (editor->sdl.event.motion.x / editor->dist_grid)
			* editor->dist_grid;
		mouse.y = (editor->sdl.event.motion.y / editor->dist_grid)
			* editor->dist_grid;
		display_mouse(&editor->sdl, mouse, 0x0ff0f0);
	}
	display_line(editor, editor->sdl.event.motion.x,
			editor->sdl.event.motion.y);
}

static void		mouse(t_editor *editor, SDL_Event event)
{
	if (event.motion.x <= EDIT_W)
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
		// else if (editor->sett == MODIFY_SECTOR)
		// 	is_in_sector(editor, event.motion.x, event.motion.y);
		editor->map_save = false;
	}
	else if (editor->sect_is_closed == true)
		clic_editor_menu(event.motion.x, event.motion.y, editor);
}

static void		keydown(t_editor *editor, SDL_Event event)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
	{
		if (is_saved(editor) == true)
			editor->finish = true;
	}
	if (event.key.keysym.scancode == SDL_SCANCODE_RETURN)
	{
		create_map(editor);
		editor->map_save = true;
	}
	if (editor->sect_is_closed == true)
	{
		next_keydown(event, editor->sdl.surf, editor);
		blank_menu(editor->sdl.surf, editor->sett);
	}
}

void			events(t_editor *editor)
{
	display_menu(editor->sdl.surf, editor->sett);
	while (editor->finish == false)
	{
		while (SDL_PollEvent(&(editor->sdl.event)))
		{
			if (editor->sdl.event.type == SDL_QUIT)
					editor->finish = true;
			else if (editor->sdl.event.type == SDL_KEYDOWN)
				keydown(editor, editor->sdl.event);
			else if (editor->sdl.event.type == SDL_MOUSEBUTTONDOWN)
				mouse(editor, editor->sdl.event);
			else if (editor->sdl.event.type == SDL_MOUSEMOTION)
				motion(editor->sdl, editor->sett);
			sett_square(editor->sett, editor->sdl.surf);
		}
		display_editor(editor);
		if (SDL_UpdateWindowSurface(editor->sdl.win) != 0)
			exit(1);
	}
}
