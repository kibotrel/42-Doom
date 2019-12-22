/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:44:25 by lojesu            #+#    #+#             */
/*   Updated: 2019/12/22 14:52:48 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

#include <stdint.h>
#include "clean.h"
#include "utils.h"

# define FOG -z / 2

/*
** texture/texture_tools, fonction who serves to change an hexadecimal color
*/
uint32_t    color_mul(uint32_t color, double mul);
uint32_t    color_add(uint32_t color, double add);

/*
** texture/texture_tools, function for draw texture's slice'
*/
void		draw_texture(t_env *env, int x, int y1, int y2, int z, uint32_t *middle);

#endif
