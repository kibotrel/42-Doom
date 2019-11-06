/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 06:42:37 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 11:46:30 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"

static uint32_t	build_pixel(uint8_t *stream)
{
	return ((stream[2] << 16) | (stream[1] << 8) | stream[0]);
}

void			build_image(t_file *file, uint8_t *stream, t_info info)
{
	int			y;
	int			i;
	uint32_t	x;
	uint32_t	pixel;

	y = info.dib.res.y;
	x = 0;
	while (--y >= 0)
	{
		x = 0;
		i = 0;
		while (x < info.row)
		{
			pixel = build_pixel(stream + x + y * info.scanline);
			file->pixels[(info.dib.res.y - y - 1) * info.dib.res.x + i++] = pixel;
			x += info.bytes;
		}
	}
}
