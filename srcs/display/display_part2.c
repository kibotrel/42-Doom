/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:05:19 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/24 14:33:49 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	display_entities(t_sdl *sdl, t_entity *entity, int clr, bool fl)
{
	t_entity	*print;

	print = entity;
	while (print)
	{
		put_fov(sdl->surf, init_vertex(print->x, print->y), print->angle, clr);
		print = print->prev;
	}
	print = entity;
	while (print)
	{
		put_fov(sdl->surf, init_vertex(print->x, print->y), print->angle, clr);
		print = print->next;
	}
	if (entity && fl == true)
		put_fov(sdl->surf, init_vertex(entity->x, entity->y),
				entity->angle, 0xffff00);
}

void		display_vertex(t_sdl *sdl, t_vertex *vertex, int color)
{
	t_vertex	*print;

	print = vertex;
	while (print)
	{
		put_pixel(sdl->surf, print->x, print->y, color);
		put_pixel(sdl->surf, print->x + 1, print->y, color);
		put_pixel(sdl->surf, print->x, print->y + 1, color);
		put_pixel(sdl->surf, print->x + 1, print->y + 1, color);
		put_pixel(sdl->surf, print->x - 1, print->y, color);
		put_pixel(sdl->surf, print->x + 1, print->y - 1, color);
		put_pixel(sdl->surf, print->x - 1, print->y + 1, color);
		put_pixel(sdl->surf, print->x, print->y - 1, color);
		put_pixel(sdl->surf, print->x - 1, print->y - 1, color);
		print = print->next;
	}
}

void		display_mouse(t_sdl *sdl, t_vertex mouse, int color)
{
	put_pixel(sdl->surf, mouse.x, mouse.y, color);
	put_pixel(sdl->surf, mouse.x + 1, mouse.y, color);
	put_pixel(sdl->surf, mouse.x, mouse.y + 1, color);
	put_pixel(sdl->surf, mouse.x + 1, mouse.y + 1, color);
	put_pixel(sdl->surf, mouse.x - 1, mouse.y, color);
	put_pixel(sdl->surf, mouse.x + 1, mouse.y - 1, color);
	put_pixel(sdl->surf, mouse.x - 1, mouse.y + 1, color);
	put_pixel(sdl->surf, mouse.x, mouse.y - 1, color);
	put_pixel(sdl->surf, mouse.x - 1, mouse.y - 1, color);
}

void		which_entity_to_display(t_editor *edit)
{
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
}
