/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:28:40 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 15:32:56 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "SDL.h"

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
	else if (n == 3)
		return ("EDITOR");
	else if (n == 5)
		return ("SETTINGS");
	else if (n == 7)
		return ("QUIT");
	else
		return (NULL);
}
