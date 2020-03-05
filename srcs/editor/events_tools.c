/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:17:05 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/05 14:17:53 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void		change_height(int *to_change, bool fl)
{
	if (fl == false)
		--*to_change;
	else
		++*to_change;
	if (*to_change < -250)
		++*to_change;
	else if (*to_change > 250)
		--*to_change;
}

static void		change_type(int *to_change, bool fl, int min, int max)
{
	if (fl == false)
		--*to_change;
	else
		++*to_change;
	if (*to_change < min)
		++*to_change;
	else if (*to_change > max)
		--*to_change;
}

static void		change_value_part2(t_editor *edit, t_presets preset, bool fl)
{
	if (preset == ENTITY_MOVE && edit->sett == ENEMY && edit->enemy)
		move_in_entities(&edit->enemy, fl);
	else if (preset == ENTITY_MOVE && edit->sett == OBJECT && edit->object)
		move_in_entities(&edit->object, fl);
	else if (preset == ENTITY_ROTATE && edit->sett == ENEMY && edit->enemy)
		rotate_entity(edit->enemy, fl);
	else if (preset == ENTITY_ROTATE && edit->sett == OBJECT && edit->object)
		rotate_entity(edit->object, fl);
	else if (preset == PLAYER_ROTATE)
		rotate_player(&edit->player, fl);
	else if (preset == EFF_EFFECT && edit->sett == EFFECTOR)
		change_effect(&edit->effects.effects, fl);
	else if (preset == EFF_DATA && edit->sett == EFFECTOR)
	{
		if (edit->effects.effects != EFF_NONE &&
			edit->effects.effects != EFF_SKY)
		{
			if (edit->effects.effects == EFF_ELEV)
				change_type(&edit->count.eff_data[edit->effects.effects],
					fl, -1000, 1000);
			else
				change_type(&edit->count.eff_data[edit->effects.effects],
					fl, 0, 1000);
		}
	}
}

void			change_value(t_editor *editor, t_presets presets, bool fl)
{
	if (presets == SECTOR_FLOOR && editor->sector)
		change_height(&editor->sector->h_floor, fl);
	else if (presets == SECTOR_CEIL && editor->sector)
		change_height(&editor->sector->h_ceil, fl);
	else if (presets == SECTOR_TEXT && editor->sector)
		change_type(&editor->sector->texture, fl, 0, 9);
	else if (presets == SECTOR_TYPE && editor->sector)
		change_type(&editor->sector->type, fl, 0, 3);
	else if (presets == SECTOR_GRAV && editor->sector)
		change_type(&editor->sector->gravity, fl, 0, 100);
	else if (presets == SECTOR_FRICTION && editor->sector)
		change_type(&editor->sector->friction, fl, 0, 100);
	else if (presets == SECTOR_LIGHT && editor->sector)
		change_type(&editor->sector->light, fl, -1, 6);
	else if (presets == ENTITY_TYPE && editor->sett == ENEMY && editor->enemy)
		change_type(&editor->enemy->type, fl, 0, 3);
	else if (presets == ENTITY_TYPE && editor->sett == OBJECT && editor->object)
		change_type(&editor->object->type, fl, 0, 3);
	change_value_part2(editor, presets, fl);
}
