/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:01:41 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/20 18:02:54 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "env.h"

char		*magazine_asset(int w, int h)
{
	if (w == 1280 && h == 720)
		return ("./assets/magazine_720.bmp");
	else if (w == 1366 && h == 768)
		return ("./assets/magazine_768.bmp");
	else if (w == 1440 && h == 900)
		return ("./assets/magazine_900.bmp");
	else if (w == 1920 && h == 1080)
		return ("./assets/magazine_1080.bmp");
	else
		return (NULL);
}

int32_t		coin_shift(int w, int h)
{
	if (w == 1280 && h == 720)
		return (48);
	else if (w == 1366 && h == 768)
		return (51);
	else if (w == 1440 && h == 900)
		return (60);
	else if (w == 1920 && h == 1080)
		return (72);
	else
		return (0);
}

int32_t		shotgun_shift(int w, int h)
{
	if (w == 1280 && h == 720)
		return (480);
	else if (w == 1366 && h == 768)
		return (512);
	else if (w == 1440 && h == 900)
		return (600);
	else if (w == 1920 && h == 1080)
		return (720);
	else
		return (0);
}

uint32_t	life_state(double life)
{
	if (life >= 75)
		return (GREEN);
	else if (life >= 50)
		return (YELLOW);
	else if (life >= 25)
		return (ORANGE);
	else
		return (RED);
}
