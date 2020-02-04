/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:26:11 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/04 04:36:21 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include "structs.h"

typedef struct	s_dist
{
	double		distance;
	uint32_t	negative;
	uint32_t	r[2];
	uint32_t	g[2];
	uint32_t	b[2];
}				t_dist;

/*
**	debug.c
*/

void	debug_hud(t_env *env);

/*
**	crosshair.c
*/

void		crosshair(t_env *env);
void		negative(SDL_Surface *win, t_pos p);

#endif
