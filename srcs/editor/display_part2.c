/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:57:12 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/03 15:06:08 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "editor.h"

static void	display_entities(t_sdl *sdl, t_ed_entity *entity, int clr, bool fl)
{
	t_ed_entity	*print;

	print = entity;
	while (print)
	{
		put_fov(sdl->screen, init_vertex(print->x, print->y), print->angle, clr);
		print = print->prev;
	}
	print = entity;
	while (print)
	{
		put_fov(sdl->screen, init_vertex(print->x, print->y), print->angle, clr);
		print = print->next;
	}
	if (entity && fl == true)
		put_fov(sdl->screen, init_vertex(entity->x, entity->y),
				entity->angle, 0xffff00);
}

void		display_vertex(t_sdl *sdl, t_ed_sector *sector, int color)
{
	t_ed_sector	*print;
	t_vertex	*vertex;

	print = sector;
	if (!sector)
		return ;
	while (print->prev)
		print = print->prev;
	while (print)
	{
		vertex = print->vertex;
		while (vertex)
		{
			put_pixel(sdl->screen, vertex->x, vertex->y, color);
			put_pixel(sdl->screen, vertex->x + 1, vertex->y, color);
			put_pixel(sdl->screen, vertex->x, vertex->y + 1, color);
			put_pixel(sdl->screen, vertex->x + 1, vertex->y + 1, color);
			put_pixel(sdl->screen, vertex->x - 1, vertex->y, color);
			put_pixel(sdl->screen, vertex->x + 1, vertex->y - 1, color);
			put_pixel(sdl->screen, vertex->x - 1, vertex->y + 1, color);
			put_pixel(sdl->screen, vertex->x, vertex->y - 1, color);
			put_pixel(sdl->screen, vertex->x - 1, vertex->y - 1, color);
			vertex = vertex->next;
		}
		print = print->next;
	}
}

void		display_mouse(t_sdl *sdl, t_vertex mouse, int color)
{
	put_pixel(sdl->screen, mouse.x, mouse.y, color);
	put_pixel(sdl->screen, mouse.x + 1, mouse.y, color);
	put_pixel(sdl->screen, mouse.x, mouse.y + 1, color);
	put_pixel(sdl->screen, mouse.x + 1, mouse.y + 1, color);
	put_pixel(sdl->screen, mouse.x - 1, mouse.y, color);
	put_pixel(sdl->screen, mouse.x + 1, mouse.y - 1, color);
	put_pixel(sdl->screen, mouse.x - 1, mouse.y + 1, color);
	put_pixel(sdl->screen, mouse.x, mouse.y - 1, color);
	put_pixel(sdl->screen, mouse.x - 1, mouse.y - 1, color);
}

void		which_entity_to_display(t_editor *edit, t_env *env)
{
	if (edit->sett != OBJECT)
	{
		edit->sett == ENEMY ? display_entities(&env->sdl, edit->enemy, RED, true)
			: display_entities(&env->sdl, edit->enemy, RED, false);
		display_entities(&env->sdl, edit->object, 0x8b4513, false);
	}
	else if (edit->sett != ENEMY)
	{
		display_entities(&env->sdl, edit->enemy, RED, false);
		display_entities(&env->sdl, edit->object, 0x8b4513, true);
	}
}
