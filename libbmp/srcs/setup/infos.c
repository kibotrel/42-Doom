/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 20:02:58 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 06:14:57 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bmp.h"

void		setup_infos(t_info *info)
{
	info->padding = padding(info->dib);
	info->scanline = scanline(info->dib, info->padding);
	info->bytes = info->dib.bpp / 8;
	info->row = info->scanline - info->padding;
	info->memory = memory(info->dib);
}

static void	setup_errors(t_file *file)
{
	file->msg[0] = "";
	file->msg[1] = ")\n\t- Unable to open the given file.\n\0";
	file->msg[2] = ")\n\t- Unable to allocate memory.\n\0";
	file->msg[3] = ")\n\t- Unable to read the given file.\n\0";
	file->msg[4] = ")\n\t- File is too large (expected at most 16MiB).\n\0";
	file->msg[5] = ")\n\t- Unable to close the given file.\n\0";
	file->msg[6] = ")\n\t- Wrong file signature (expected 0x424D).\n\0";
	file->msg[7] = ")\n\t- Unable to reposition reading offset.\n\0";
	file->msg[8] = ")\n\t- DIB not supported (expected BITMAPV4HEADER).\n\0";
	file->msg[9] = ")\n\t- Bits per pixel not supported (expected 24bits).\n\0";
	file->msg[10] = ")\n\t- Compression method not supported (expected 0).\n\0";
	file->msg[11] = ")\n\t- Misformated header encountered.\n\0";
	file->msg[12] = ")\n\t- Wrong data offset (expected 122 Bytes).\n\0";
	file->msg[13] = ")\n\t- Null resolution found (expected at least 1px).\n\0";
	file->msg[14] = ")\n\t- Wrong scanline size (expected multiple of 4).\n\0";
}

void		presets(t_file *file)
{
	ft_bzero(file, sizeof(t_file));
	ft_bzero(file->msg, sizeof(char*));
	ft_bzero(&file->info, sizeof(t_info));
	ft_bzero(&file->info.bmp, sizeof(t_hdr));
	ft_bzero(&file->info.dib, sizeof(t_dib));
	ft_bzero(&file->info.dib.dpi, sizeof(t_vec));
	ft_bzero(&file->info.dib.res, sizeof(t_vec));
	setup_errors(file);
}
