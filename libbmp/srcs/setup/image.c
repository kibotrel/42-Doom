/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 05:08:52 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 05:17:33 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bmp.h"

void	load_image(t_file *file, t_bmp *image)
{
	ft_bzero(image, sizeof(t_bmp));
	image->width = file->info.dib.res.x;
	image->height = file->info.dib.res.y;
	image->pixels = file->pixels;
}
