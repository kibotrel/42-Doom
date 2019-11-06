/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 02:02:33 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 06:20:26 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "macros.h"
#include "bmp.h"

int	check_signature(uint8_t *buffer)
{
	return ((ft_short(buffer) != BMP_SIGN) ? BMP_E_SIGNATURE : BMP_OK);
}

int	check_size(uint32_t *size, uint8_t *buff)
{
	return (((*size = swap4(ft_int(buff))) >= MAX_SIZE) ? BMP_E_SIZE : BMP_OK);
}

int	check_header(t_file *file)
{
	if ((file->info.bmp.offset = swap4(ft_int(file->stream + 10))) != BMP_SHIFT)
		return (BMP_E_OFFSET);
	if ((file->info.dib.size = swap4(ft_int(file->stream + 14))) != DIB_SIZE)
		return (BMP_E_DIB);
	if (!(file->info.dib.res.x = swap4(ft_int(file->stream + 18)))
		|| !(file->info.dib.res.y = swap4(ft_int(file->stream + 22))))
		return (BMP_E_RES);
	file->info.dib.planes = swap2(ft_short(file->stream + 26));
	if ((file->info.dib.bpp = swap2(ft_short(file->stream + 28))) != 24)
		return (BMP_E_BPP);
	if ((file->info.dib.compression = swap4(ft_int(file->stream + 30))))
		return (BMP_E_COMPRESSION);
	if (((file->info.dib.raw = swap4(ft_int(file->stream + 34))) % 4))
		return (BMP_E_PADDING);
	file->info.dib.dpi.x = swap4(ft_int(file->stream + 38));
	file->info.dib.dpi.y = swap4(ft_int(file->stream + 42));
	file->info.dib.colors = swap4(ft_int(file->stream + 46));
	file->info.dib.important = swap4(ft_int(file->stream + 50));
	return (BMP_OK);
}
