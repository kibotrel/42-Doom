/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:22:14 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/03 18:04:16 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "structs.h"

typedef struct	s_local
{
	int32_t		x0;			// Keeps track of the remaining space to draw
	int32_t		x1;			// Keeps track of the remaining space to draw
	t_sector	*sector;	// Copy of a sector from the parsed informations
	uint32_t	zone;		// Starting sector for the draw loop
}				t_local;

typedef struct	s_palette
{
	uint32_t	ceil;
	uint32_t	wall;
	uint32_t	floor;
}				t_palette;

/*
**	keyboard.c
*/

void	game_keyboard(t_env *env);

/*
**	movement.c
*/

void	update_position(t_env *env, double angle, double speed);

/*
**	camera.c
*/

void	reset_view(t_env *env);
void	update_angle(t_env *env, double *angle);

#endif
