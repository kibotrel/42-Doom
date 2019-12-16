/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:22:14 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/16 12:08:11 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "env.h"
# include "structs.h"

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

void	jump(t_cam *cam);
void	move(t_env *env);
/*
**	camera.c
*/

void	cam_motion(t_env *env, t_cam *cam, int x, int y);
void	update_cam(t_env *env, float dx, float dy);
/*
**	engine.c
*/

void	physics(t_env *env);

/*
**	physics
*/

void	vertical_movement(t_env *env, t_sector sector, double cam_height);
void	horizontal_movement(t_env *env, t_vec3d p, t_vec3d vel, double view);
int32_t	check_collisions(t_vec3d p, t_vec3d v, t_vec2d w1, t_vec2d w2);

#endif
