/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:09:05 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/12/11 15:39:56 by reda-con         ###   ########.fr       */
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

static void		display_editor(t_editor *edit)
{
	t_vertex	mse;

	display_grid(edit);
	put_fov(sdl->surf, init_vertex(player.x, player.y), player.angle, 0xff00ff);
	if (edit->sett != OBJECT)
	{
		edit->sett == ENEMY ? display_entities(&edit->sdl, edit->enemy, R, true)
			: display_entities(&edit->sdl, edit->enemy, R, false);
		display_entities(&edit->sdl, edit->object, 0x8b4513, false);
	}
	else if (edit->sett != ENEMY)
	{
		display_entities(&edit->sdl, edit->enemy, R, false);
		display_entities(&edit->sdl, edit->object, 0x8b4513, true);
	}
	display_sector(edit);
	display_vertex(&edit->sdl, edit->vertex, 0xffff00);
	if (edit->sett == SECTOR && edit->sdl.event.motion.x <= EDIT_W)
	{
		mse.x = (edit->sdl.event.motion.x / edit->dist_grid) * edit->dist_grid;
		mse.y = (edit->sdl.event.motion.y / edit->dist_grid) * edit->dist_grid;
		display_mouse(&edit->sdl, mse, 0x0ff0f0);
	}
	display_line(edit, edit->sdl.event.motion.x, edit->sdl.event.motion.y);
	print_param_to_screen(&edit->sdl);
}

static void		mouse(t_editor *editor, SDL_Event event)
{
	if (event.motion.x <= EDIT_W && event.button.button == SDL_BUTTON_LEFT)
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
	if (event.key.keysym.scancode == SDL_SCANCODE_DELETE)
		clear_editor(editor);
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
		blank_menu(editor->sdl.surf, editor->sett, editor->sdl);
	}
}

void			events(t_editor *editor)
{
	blank_menu(editor->sdl.surf, editor->sett, editor->sdl);
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
		}
		display_editor(editor);
		if (SDL_UpdateWindowSurface(editor->sdl.win) != 0)
			exit(1);
	}
}
