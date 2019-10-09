/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:28:40 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/09 03:47:05 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "SDL.h"
#include "doom.h"

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
