/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <lojesu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:44:25 by lojesu            #+#    #+#             */
/*   Updated: 2020/01/23 18:31:48 by lojesu           ###   ########.fr       */
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

/*
** texture/texture_tools, function for draw texture's slice'
*/

void		draw_texture_slice(t_env *env, int x, t_height h, t_game *var, uint32_t *wall);

#endif
