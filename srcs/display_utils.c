/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:14:01 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/18 15:07:07 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	draw_line(SDL_Surface *surf, t_vertex start, t_vertex end, int color)
{
	t_line		line;

	line.delta_x = abs(end.x - start.x);
	line.delta_y = abs(end.y - start.y);
	line.sign_x = start.x < end.x ? 1 : -1;
	line.sign_y = start.y < end.y ? 1 : -1;
	line.error = line.delta_x - line.delta_y;
	put_pixel(surf, end.x, end.y, color);
	while (start.x != end.x || start.y != end.y)
	{
		put_pixel(surf, start.x, start.y, color);
		line.error_2 = line.error * 2;
		if (line.error_2 > -line.delta_y)
		{
			line.error -= line.delta_y;
			start.x += line.sign_x;
		}
		if (line.error_2 < line.delta_x)
		{
			line.error += line.delta_x;
			start.y += line.sign_y;
		}
	}
}

void	put_pixel(SDL_Surface *surf, int x, int y, int color)
{
	int		*pix;

	if ((x >= 0 && x <= EDIT_W + MENU_W) && (y >= 0 && y <= WIN_H))
	{
		pix = surf->pixels + y * surf->pitch + x * surf->format->BytesPerPixel;
		*pix = color;
	}
}
