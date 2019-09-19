/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:28:40 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/19 18:07:03 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
