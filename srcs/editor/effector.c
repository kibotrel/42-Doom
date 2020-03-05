/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 08:55:48 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/04 12:43:14 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "libft.h"

void	effector_text(t_env *env, t_presets preset, t_effects effect)
{
	char	*print;

	if (effect == EFF_PLATE)
	{
		display_text(WHITE, init_vertex(1610, 455), "Plate", env);
		display_text(WHITE, init_vertex(1610, 555), "Door", env);
	}
	if (preset == EFF_EFFECT)
	{
		display_text(WHITE, init_vertex(1420, 50), "-", env);
		display_text(WHITE, init_vertex(1615, 55), "+", env);
	}
	if (preset == EFF_MOVE || preset == EFF_EFFECT)
		display_text(WHITE,
			init_vertex(1460, 50), env->editor.effector[effect], env);
	else if (preset == EFF_DATA && effect != NONE)
	{
		display_text(WHITE, init_vertex(1420, 50), "-", env);
		display_text(WHITE, init_vertex(1615, 55), "+", env);
		print = ft_itoa(env->editor.count.eff_data[effect]);
		display_text(WHITE, init_vertex(1460, 50), print, env);
		free(print);
	}
}

void	change_effect(t_effects *effect, bool fl)
{
	if (fl == false && *effect > 0)
		--*effect;
	else if (fl == true && *effect < ALL_EFFECTS - 1)
		++*effect;
}

void	apply_effect_in_sector(t_editor *edit, int x, int y)
{
	int				which_sector;
	t_ed_sector		*sect;

	which_sector = is_in_sector(edit, init_vertex(x, y));
	sect = edit->sector;
	while (sect->prev)
		sect = sect->prev;
	while (sect)
	{
		if (sect->sector_number == which_sector)
		{
			if (sect->effect.effects == edit->effects.effects)
			{
				sect->effect.effects = EFF_NONE;
				sect->effect.data = 0;
			}
			else
			{
				sect->effect.effects = edit->effects.effects;
				sect->effect.data = edit->count.eff_data[edit->effects.effects];
			}
		}
		sect = sect->next;
	}
}

void	check_plate(t_ed_sector *sect, int number)
{
	if (sect->effect.effects == -number)
		sect->effect.effects = 0;
	else if (sect->effect.effects == number)
		sect->effect.effects = 0;
	else
		sect->effect.effects = number;
}

void	apply_plate(t_editor *edit, int x, int y, bool fl)
{
	int				which_sector;
	t_ed_sector		*sect;
	int				number;

	which_sector = is_in_sector(edit, init_vertex(x, y));
	if (which_sector < 0)
		return ;
	sect = edit->sector;
	while (sect->prev)
		sect = sect->prev;
	number = EFF_PLATE + edit->count.eff_data[EFF_PLATE];
	while (sect)
	{
		if (sect->sector_number != which_sector &&
			sect->effect.effects == number && fl == false)
			sect->effect.effects = 0;
		if (sect->sector_number == which_sector)
		{
			check_plate(sect, number);
			if (fl == true)
				sect->effect.effects *= -1;
		}
		sect = sect->next;
	}
}
