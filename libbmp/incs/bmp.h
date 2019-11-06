/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:59:02 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 06:14:09 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include <stdint.h>

typedef enum		e_errors
{
	BMP_OK,
	BMP_E_OPEN,
	BMP_E_MALLOC,
	BMP_E_READ,
	BMP_E_SIZE,
	BMP_E_CLOSE,
	BMP_E_SIGNATURE,
	BMP_E_LSEEK,
	BMP_E_DIB,
	BMP_E_BPP,
	BMP_E_COMPRESSION,
	BMP_E_HEADER,
	BMP_E_OFFSET,
	BMP_E_RES,
	BMP_E_PADDING,
	BMP_ERROR_COUNT
}					t_errors;

typedef	struct		s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef	struct		s_hdr
{
	uint32_t		offset;
	uint32_t		weight;
}					t_hdr;

typedef	struct		s_dib
{
	t_vec			dpi;
	t_vec			res;
	uint8_t			bpp;
	uint8_t			planes;
	uint8_t			important;
	uint8_t			compression;
	uint32_t		raw;
	uint32_t		size;
	uint32_t		colors;

}					t_dib;

typedef struct		s_info
{
	t_hdr			bmp;
	t_dib			dib;
	uint8_t			bytes;
	uint8_t			error;
	uint8_t			padding;
	uint32_t		row;
	uint32_t		memory;
	uint32_t		scanline;
}					t_info;

typedef struct		s_file
{
	char			*msg[BMP_ERROR_COUNT];
	t_info			info;
	uint8_t			*stream;
	uint32_t		*pixels;
}					t_file;

typedef struct		s_bmp
{
	int				width;
	int				height;
	uint32_t		*pixels;
}					t_bmp;

/*
**	core/bmp_to_array.c
*/

int					bmp_to_array(char *bmp, t_bmp *image);

/*
**	clean/flush_streams.c
*/

int					wipe(t_file *file, uint32_t status);

/*
**	display/exit_status.c
*/

int					dislay_output(t_file *file, uint32_t status);

/*
**	setup/infos.c
*/

void				presets(t_file *file);
void				setup_infos(t_info *data);

/*
**	setup/image.c
*/

void				load_image(t_file *file, t_bmp *image);

/*
**	chuncks/header.c
*/

int					check_header(t_file *file);
int					check_signature(uint8_t *buffer);
int					check_size(uint32_t *weight, uint8_t *buffer);

/*
**	chuncks/image.c
*/

void				build_image(t_file *file, uint8_t *stream, t_info info);

/*
**	maths/endians.c
*/

uint16_t			swap2(uint16_t x);
uint32_t			swap4(uint32_t x);

/*
**	maths/infos.c
*/

uint8_t				padding(t_dib dib);
uint32_t			memory(t_dib dib);
uint32_t			scanline(t_dib dib, uint8_t padding);

#endif
