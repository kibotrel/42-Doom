/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <lojesu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:44:25 by lojesu            #+#    #+#             */
/*   Updated: 2020/02/18 14:36:51 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# define W_UNIT 4096
# define W_SIZE 64

typedef struct	s_scaler
{
	int		result;
	int		bop;
	int		fd;
	int		ca;
	int		cache;
}				t_scaler;

/*
** texture/texture_tools, fonction who serves to change an hexadecimal color
*/
uint32_t	color_mul(uint32_t color, double mul);
uint32_t	color_add(uint32_t color, double add);

/*
** texture/texture_tools, functions for initialize my variable and protect from
** division by 0
*/
void		init_and_protect_variable_1(t_game *var, float w_size, float *u0, float *u1);
void		init_and_protect_variable_2(t_game *var, float w_size, float *u0, float *u1);

/*
** texture/texture, function for draw texture's slice'
*/
void		draw_texture_slice(t_env *env, int x, t_height h, t_game *var);

#endif
