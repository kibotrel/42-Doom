/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 06:06:45 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/02 07:11:57 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "bmp.h"

uint8_t		padding(t_dib dib)
{
	return ((dib.raw - (dib.res.x * dib.res.y * (dib.bpp / 8))) / dib.res.y);
}

uint32_t	scanline(t_dib dib, uint8_t padding)
{
	return (dib.res.x * (dib.bpp / 8) + padding);
}

uint32_t	memory(t_dib dib)
{
	return (dib.res.x * dib.res.y * sizeof(uint32_t));
}
