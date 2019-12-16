/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:22:14 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/16 21:13:45 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "env.h"
# include "structs.h"

typedef struct	s_item
{
	int sector;
	int min;
	int max;
}               t_item;

typedef struct	s_game
{
	int			*top;
	int			*bottom;
	int			*render;
	double		farz;
	double		nearz;
	double		farside;
	double		nearside;
	t_item		*head;
	t_item		*tail;
	t_item		queue[32];
	t_vec2d		t[2];
	t_vec2d		v[2];
}				t_game;
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
void	graphics(t_env *env, t_game *var);

/*
**	physics
*/

void	vertical_movement(t_env *env, t_sector sector, double cam_height);
void	horizontal_movement(t_env *env, t_vec3d p, t_vec3d vel, double view);
int32_t	check_collisions(t_vec3d p, t_vec3d v, t_vec2d w1, t_vec2d w2);

#endif
