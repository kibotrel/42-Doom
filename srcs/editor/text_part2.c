/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:01:00 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/04 11:30:03 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

static void	print_light(t_editor *edit, t_env *env, t_settings sett)
{
	if (edit->presets == SECTOR_LIGHT && edit->sector)
		print_sector_light(env, edit->sector->light, edit->sector,
			env->sdl.screen);
	if (edit->presets == ENTITY_TYPE && sett == ENEMY && edit->enemy)
		print_sector_light(env, edit->enemy->type, edit->sector,
			env->sdl.screen);
	if (edit->presets == ENTITY_TYPE && sett == OBJECT && edit->object)
		print_sector_light(env, edit->object->type, edit->sector,
			env->sdl.screen);
}

static void	print_sector_values(t_ed_sector *sector, t_presets presets,
	t_env *env)
{
	char		*print;

	print = NULL;
	display_text(WHITE, init_vertex(1420, 50), "-", env);
	display_text(WHITE, init_vertex(1615, 55), "+", env);
	if (presets == SECTOR_FLOOR)
		print = ft_itoa(sector->h_floor);
	else if (presets == SECTOR_CEIL)
		print = ft_itoa(sector->h_ceil);
	else if (presets == SECTOR_GRAV)
		print = ft_itoa(sector->gravity);
	else if (presets == SECTOR_FRICTION)
		print = ft_itoa(sector->friction);
	else if (presets == ENTITY_MOVE)
		display_text(WHITE, init_vertex(1455, 50), "Prev./Next", env);
	else if (presets == PLAYER_ROTATE || presets == ENTITY_ROTATE)
		display_text(WHITE, init_vertex(1455, 50), "Left/Right", env);
	else
		return ;
	if (print)
	{
		display_text(WHITE, init_vertex(1510, 50), print, env);
		free(print);
	}
}

void		print_param_to_screen(t_env *env, t_settings sett, t_editor *edit)
{
	t_vertex	pos;
	int			i;

	i = -1;
	pos.x = 1410;
	pos.y = 155;
	while (++i < 6)
	{
		display_text(WHITE, pos, edit->first_params[i], env);
		display_text(WHITE, init_vertex(pos.x - 45, pos.y), edit->numbers[i],
			env);
		pos.y = pos.y + 100;
	}
	display_text(WHITE, init_vertex(1315, 765), edit->first_params[6], env);
	display_text(WHITE, init_vertex(1445, 765), edit->first_params[7], env);
	if (edit->presets > SECTOR_MOVE && edit->sector && edit->sett != EFFECTOR)
		print_sector_values(edit->sector, edit->presets, env);
	if (edit->presets == SECTOR_TEXT)
		print_params_image(edit, edit->presets, edit->sett, env);
	print_light(edit, env, sett);
	if (sett == EFFECTOR)
		effector_text(env, edit->presets, edit->effects.effects);
	if (edit->sect_is_closed == false)
		display_text(WHITE, init_vertex(1380, 50), edit->first_params[8], env);
}
