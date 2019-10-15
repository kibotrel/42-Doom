/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:28:40 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 21:15:06 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "SDL.h"
#include "enums.h"
#include "structs.h"

void	line_params(t_line *line, t_point a, t_point b)
{
	line->sign.y = (a.y < b.y ? 1 : -1);
	line->sign.x = (a.x < b.x ? 1 : -1);
	line->delta.y = abs(b.y - a.y);
	line->delta.x = abs(b.x - a.x);
	line->offset = line->delta.x - line->delta.y;
	line->error = 0;
}

void	police_color(SDL_Color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

void	paste_position(SDL_Rect *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

char	*get_string(int n)
{
	if (n == 1)
		return ("GAME");
	if (n == 3)
		return ("EDITOR");
	if (n == 5)
		return ("SETTINGS");
	if (n == 7)
		return ("QUIT");
	else
		return (NULL);
}

int		get_dimensions(int height)
{
	if (height == 1080)
		return (MENU_1080P);
	if (height == 900)
		return (MENU_900P);
	if (height == 768)
		return (MENU_768P);
	if (height == 720)
		return (MENU_720P);
	else
		return (-1);
}
