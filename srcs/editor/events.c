/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:09:05 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/28 12:53:04 by nde-jesu         ###   ########.fr       */
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

static void		display_editor(t_editor *edit, t_env *env)
{
	t_vertex	mse;
	int			clr;

	display_grid(edit, env);
	clr = (edit->sett == PLAYER) ? 0xffff00 : 0xff00ff;
	put_fov(env->sdl.screen, init_vertex(edit->player.x, edit->player.y),
			edit->player.angle, clr);
	which_entity_to_display(edit, env);
	edit->sett == SECTOR ? display_sector(&env->sdl, edit->sector, true)
		: display_sector(&env->sdl, edit->sector, false);
	display_vertex(&env->sdl, edit->vertex, 0xffff00);
	if (edit->sett == PORTAL)
		display_portals(edit->portals, &env->sdl, 0x00ff00, edit->sett == PORTAL);
	if (edit->sett == SECTOR && env->sdl.event.motion.x <= EDIT_W)
	{
		mse.x = (env->sdl.event.motion.x / edit->true_grid) * edit->true_grid;
		mse.y = (env->sdl.event.motion.y / edit->true_grid) * edit->true_grid;
		display_mouse(&env->sdl, mse, 0x0ff0f0);
	}
	display_line(edit, env->sdl.event.motion.x, env->sdl.event.motion.y, env);
	print_param_to_screen(env, edit->sett, edit);
}

void		editor_click(t_editor *editor, SDL_Event event, t_env *env)
{
	if (event.motion.x <= EDIT_W && event.button.button == SDL_BUTTON_LEFT)
	{
		editor->presets = NONE;
		blank_menu(env->sdl.screen, editor->sett, editor, editor->presets, env);
		if (editor->sett == SECTOR)
			place_sector(editor, event.motion.x, event.motion.y, env);
		else if (editor->sett == PLAYER)
			place_player(editor, event.motion.x, event.motion.y);
		else if (editor->sett == ENEMY)
			place_entity(editor, event.motion.x, event.motion.y, 0, env);
		else if (editor->sett == OBJECT)
			place_entity(editor, event.motion.x, event.motion.y, 1, env);
		else if (editor->sett == PORTAL)
			place_portal(editor, event.motion.x, event.motion.y, env);
		editor->map_save = false;
	}
	else if (editor->sect_is_closed == true && event.motion.x > EDIT_W)
		clic_editor_menu(event.motion.x, event.motion.y, editor, env);
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

void			events(t_editor *editor, t_env *env)
{
		blank_menu(env->sdl.screen, editor->sett, editor, editor->presets, env);
		display_editor(editor, env);
		if (SDL_UpdateWindowSurface(env->sdl.win) != 0)
			clean_editor(editor, env);
}
