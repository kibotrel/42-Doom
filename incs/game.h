/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:22:14 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/19 16:28:26 by vivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "structs.h"

typedef struct  s_item
{
	int sector;
	int sx1;
	int sx2;
}               t_item;
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
