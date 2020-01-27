/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:09:05 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/27 14:43:24 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "editor.h"

bool		is_saved(t_editor *editor)
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
	int			clr;

	display_grid(edit);
	clr = (edit->sett == PLAYER) ? 0xffff00 : 0xff00ff;
	put_fov(edit->sdl.screen, init_vertex(edit->player.x, edit->player.y),
			edit->player.angle, clr);
	which_entity_to_display(edit);
	edit->sett == SECTOR ? display_sector(&edit->sdl, edit->sector, true)
		: display_sector(&edit->sdl, edit->sector, false);
	display_vertex(&edit->sdl, edit->vertex, 0xffff00);
	if (edit->sett == PORTAL)
		display_portals(edit->portals, &edit->sdl, 0x00ff00, edit->sett == PORTAL);
	if (edit->sett == SECTOR && edit->sdl.event.motion.x <= EDIT_W)
	{
		mse.x = (edit->sdl.event.motion.x / edit->true_grid) * edit->true_grid;
		mse.y = (edit->sdl.event.motion.y / edit->true_grid) * edit->true_grid;
		display_mouse(&edit->sdl, mse, 0x0ff0f0);
	}
	display_line(edit, edit->sdl.event.motion.x, edit->sdl.event.motion.y);
	print_param_to_screen(&edit->sdl, edit->sett, edit);
}

void		editor_click(t_editor *editor, SDL_Event event)
{
	if (event.motion.x <= EDIT_W && event.button.button == SDL_BUTTON_LEFT)
	{
		editor->presets = NONE;
		blank_menu(editor->sdl.screen, editor->sett, editor, editor->presets);
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
		editor->map_save = false;
	}
	else if (editor->sect_is_closed == true && event.motion.x > EDIT_W)
		clic_editor_menu(event.motion.x, event.motion.y, editor);
}

void			editor_mousewheel(t_editor *editor, SDL_Event event)
{
	if (event.wheel.y > 0)
		editor->dist_grid *= 2;
	else if (event.wheel.y < 0)
		editor->dist_grid /= 2;
	if (editor->dist_grid < 25)
		editor->dist_grid = 25;
	if (editor->dist_grid > 100)
		editor->dist_grid = 100 ;
	editor->true_grid = EDIT_W / editor->dist_grid;
}

void			events(t_editor *editor, t_env)
{
		blank_menu(editor->sdl.screen, editor->sett, editor, editor->presets);
		display_editor(editor);
		if (SDL_UpdateWindowSurface(editor->sdl.win) != 0)
			clean_editor(editor);
	}
	clean_editor(editor);
}
