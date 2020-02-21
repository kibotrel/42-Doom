/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:01:38 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/20 17:41:53 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "structs.h"

char	*coins_asset(int w, int h)
{
	if (w == 1280 && h == 720)
		return ("./assets/coins_720.bmp");
	else if (w == 1366 && h == 768)
		return ("./assets/coins_768.bmp");
	else if (w == 1440 && h == 900)
		return ("./assets/coins_900.bmp");
	else if (w == 1920 && h == 1080)
		return ("./assets/coins_1080.bmp");
	else
		return (NULL);
}

char	*shotgun_asset(int w, int h)
{
	if (w == 1280 && h == 720)
		return ("./assets/shotgun_720.bmp");
	else if (w == 1366 && h == 768)
		return ("./assets/shotgun_768.bmp");
	else if (w == 1440 && h == 900)
		return ("./assets/shotgun_900.bmp");
	else if (w == 1920 && h == 1080)
		return ("./assets/shotgun_1080.bmp");
	else
		return (NULL);
}

char	*shell_asset(int w, int h)
{
	if (w == 1280 && h == 720)
		return ("./assets/shells_720.bmp");
	else if (w == 1366 && h == 768)
		return ("./assets/shells_768.bmp");
	else if (w == 1440 && h == 900)
		return ("./assets/shells_900.bmp");
	else if (w == 1920 && h == 1080)
		return ("./assets/shells_1080.bmp");
	else
		return (NULL);
}

t_pos	p2d(int32_t x, int32_t y, int32_t base_x, int32_t base_y)
{
	t_pos p;

	p.x = x * base_x;
	p.y = y * base_y;
	return (p);
}

void	p_update(t_pos *pos, int32_t delta_x, int32_t delta_y)
{
	pos->x += delta_x;
	pos->y += delta_y;
}
