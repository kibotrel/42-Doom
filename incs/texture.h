/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:44:25 by lojesu            #+#    #+#             */
/*   Updated: 2019/12/18 15:59:51 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

#include <stdint.h>
#include "clean.h"
#include "utils.h"
# define BMP_SIZE 4096
# define BUFF_SIZE BMP_SIZE * 3

/*
** texture/texture_tools, fonction who serves to change an hexadecimal color
*/
uint32_t    color_mul(uint32_t color, double mul);
uint32_t    color_add(uint32_t color, double add);

/*
** texture/texture_tools, function for read a bmp pictures
*/
void		read_bmp(int *ret, char *path, char *buff, int buff_size);

/*
** texture/texture_tools, function for draw texture's slice'
*/
void		draw_texture(t_env *env, int x, int y1, int y2, int top, int *middle, int bottom);

/*
** texture/texture.c, function which manage textures
*/
uint32_t	texture(int *texture);
#endif
