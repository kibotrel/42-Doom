/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:05:19 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/12 17:13:52 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	display_player(t_player player, t_sdl *sdl)
{
	if (player.x != -1)
	{
		put_pixel(sdl->surf, player.x, player.y, 0xff00ff);
		put_pixel(sdl->surf, player.x + 1, player.y, 0xff00ff);
		put_pixel(sdl->surf, player.x, player.y + 1, 0xff00ff);
		put_pixel(sdl->surf, player.x + 1, player.y + 1, 0xff00ff);
		put_pixel(sdl->surf, player.x - 1, player.y, 0xff00ff);
		put_pixel(sdl->surf, player.x + 1, player.y - 1, 0xff00ff);
		put_pixel(sdl->surf, player.x - 1, player.y + 1, 0xff00ff);
		put_pixel(sdl->surf, player.x, player.y - 1, 0xff00ff);
		put_pixel(sdl->surf, player.x - 1, player.y - 1, 0xff00ff);
	}
}

void	display_entities(t_sdl *sdl, t_entity *entity, int color)
{
	t_entity	*print;

	print = entity;
	if (!entity)
		return ;
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

void	display_vertex(t_sdl *sdl, t_vertex *vertex, int color)
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
