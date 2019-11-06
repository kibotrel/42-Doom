/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:58:02 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 10:28:34 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "macros.h"
#include "bmp.h"

static int	prechecks(t_file *file, char *bmp, uint8_t *buffer)
{
	int			fd;
	int			size;

	if ((fd = open(bmp, O_RDONLY)) < 0)
		return (BMP_E_OPEN);
	if ((size = read(fd, buffer, BUFFER_SIZE)) < 0)
		return (BMP_E_READ);
	if (size < BUFFER_SIZE)
		return (BMP_E_HEADER);
	if (check_signature(buffer))
		return (BMP_E_SIGNATURE);
	if (check_size(&file->info.bmp.weight, buffer + 2))
		return (BMP_E_SIZE);
	if (!(file->stream = (uint8_t*)malloc(file->info.bmp.weight)))
		return (BMP_E_MALLOC);
	if (lseek(fd, 0, SEEK_SET) < 0)
		return (BMP_E_LSEEK);
	if ((read(fd, file->stream, file->info.bmp.weight)) < 0)
		return (BMP_E_READ);
	if (close(fd))
		return (BMP_E_CLOSE);
	return (BMP_OK);
}

static int	parse_bmp(t_file *file, t_bmp *image)
{
	if ((file->info.error = check_header(file)))
		return (file->info.error);
	setup_infos(&file->info);
	if (!(file->pixels = (uint32_t*)malloc(file->info.memory)))
		return (BMP_E_MALLOC);
	build_image(file, file->stream + BMP_SHIFT, file->info);
	load_image(file, image);
	return (BMP_OK);
}

int			bmp_to_array(char *bmp, t_bmp *img)
{
	t_file		file;
	uint8_t		buffer[BUFFER_SIZE];

	presets(&file);
	if ((file.info.error = prechecks(&file, bmp, buffer)))
		return (wipe(&file, file.info.error));
	else
		return (wipe(&file, parse_bmp(&file, img)));
}
