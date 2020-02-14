/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:01:41 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/14 16:43:19 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*magazine_asset(int w, int h)
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
