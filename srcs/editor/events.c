/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:09:05 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/05 14:43:43 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void		display_editor(t_editor *edit, t_env *env, int x, int y)
{
	t_vertex	mse;
	int			clr;

	display_grid(edit, env);
	clr = (edit->sett == PLAYER) ? 0xffff00 : 0xff00ff;
	put_fov(env->sdl.screen, init_vertex(edit->player.x, edit->player.y),
			edit->player.angle, clr);
	which_entity_to_display(edit, env);
	edit->sett == SECTOR ? display_sector(&env->sdl, edit->sector, true, edit)
		: display_sector(&env->sdl, edit->sector, false, edit);
	display_vertex(&env->sdl, edit->sector, 0xffff00);
	if (edit->sett == PORTAL || edit->display_portal == 1)
		display_portals(edit->portals, &env->sdl, 0x00ff00);
	if ((edit->sett == SECTOR || edit->sett == PLAYER || edit->sett == ENEMY ||
		edit->sett == OBJECT) && x <= 1280 && edit->presets == NONE)
	{
		mse.x = (x / edit->true_grid) * edit->true_grid;
		mse.y = (y / edit->true_grid) * edit->true_grid;
		display_mouse(&env->sdl, mse, 0x0ff0f0);
	}
	if (!edit->sect_is_closed)
		display_line(edit, x, y, env);
	print_param_to_screen(env, edit->sett, edit);
}

void			editor_click(t_editor *editor, SDL_Event event, t_env *env)
{
	if (event.motion.x <= 1280 && event.button.button == SDL_BUTTON_LEFT)
	{
		blank_menu(env->sdl.screen, editor->sett, editor->presets, env);
		if (editor->sett == SECTOR && editor->presets == NONE)
			place_sector(editor, event.motion.x, event.motion.y, env);
		else if (editor->sett == SECTOR && editor->presets == SECTOR_MOVE)
			move_in_sector(editor, event.motion.x, event.motion.y);
		else if (editor->sett == PLAYER)
			place_player(editor, event.motion.x, event.motion.y);
		else if (editor->sett == ENEMY)
			place_entity(env, event.motion.x, event.motion.y, 0);
		else if (editor->sett == OBJECT)
			place_entity(env, event.motion.x, event.motion.y, 1);
		else if (editor->sett == PORTAL)
			place_portal(editor, event.motion.x, event.motion.y, env);
		else if (editor->sett == EFFECTOR && editor->presets == EFF_MOVE)
			apply_effect_in_sector(editor, event.motion.x, event.motion.y);
		else if (editor->sett == EFFECTOR && editor->presets == EFF_S_DOOR)
			apply_plate(editor, event.motion.x, event.motion.y, true);
		else if (editor->sett == EFFECTOR && editor->presets == EFF_S_PLATE)
			apply_plate(editor, event.motion.x, event.motion.y, false);
	}
	else if (editor->sect_is_closed == true && event.motion.x > 1280)
		clic_editor_menu(event.motion.x, event.motion.y, editor, env);
}

void			events(t_editor *editor, t_env *env)
{
	display_editor(editor, env, env->sdl.event.motion.x,
		env->sdl.event.motion.y);
	blank_menu(env->sdl.screen, editor->sett, editor->presets, env);
}
