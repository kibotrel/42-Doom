/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <lojesu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:44:25 by lojesu            #+#    #+#             */
/*   Updated: 2020/01/27 14:18:11 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "structs.h"
# define FOG -z / 2

typedef struct	s_scaler
{
	int result;
	int	bop;
	int	fd;
	int	ca;
	int	cache;
}				t_scaler;

/*
** texture/texture_tools, fonction who serves to change an hexadecimal color
*/

uint32_t	color_mul(uint32_t color, double mul);
uint32_t	color_add(uint32_t color, double add);
uint32_t	color_scale(uint32_t color, uint32_t new_color, int i, int nb_pixel);

/*
** texture/texture, function for draw texture's slice'
*/

void		draw_texture_slice(t_env *env, int x, t_height h, t_game *var, uint32_t *wall);

/*
** texture/texture, function for draw ceil and floor with fog of war
*/

void		draw_ceil_and_floor_slice(t_env *env, t_game *var, int x);
#endif
