/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:33:36 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/04/13 07:39:07 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "libft.h"
#include "editor.h"

t_ed_sector		*create_sector(t_env *env, t_editor *edit)
{
	t_ed_sector *sect;

	if (!(sect = (t_ed_sector *)ft_memalloc(sizeof(t_ed_sector))))
		clean(env, E_MALLOC);
	sect->sector_number = edit->count.sector++;
	sect->h_ceil = 20;
	sect->h_floor = 0;
	sect->vertex_count = 0;
	sect->texture = 0;
	sect->type = 0;
	sect->gravity = 10;
	sect->friction = 50;
	sect->light = -1;
	sect->light_value = -1;
	sect->next = NULL;
	sect->prev = NULL;
	sect->effect.effects = EFF_NONE;
	sect->effect.data = 0;
	return (sect);
}

void			print_sector_light(t_env *env, int light, t_ed_sector *sect,
						SDL_Surface *screen)
{
	rectangle(init_vertex(1499, 49), init_vertex(1550, 100), 0xffffff, screen);
	if (light == -1)
	{
		sect->light_value = -1;
		return ;
	}
	else if (light == 0)
		sect->light_value = 0xff0000;
	else if (light == 1)
		sect->light_value = 0x00ff00;
	else if (light == 2)
		sect->light_value = 0x0000ff;
	else if (light == 3)
		sect->light_value = 0xcc6075;
	else if (light == 4)
		sect->light_value = 0xe69a01;
	else if (light == 5)
		sect->light_value = 0x999999;
	else if (light == 6)
		sect->light_value = 0x04c39a;
	else
		return ;
	square(1550, 100, sect->light_value, env->sdl.screen);
}
