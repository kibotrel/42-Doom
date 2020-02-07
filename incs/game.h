/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:22:14 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/07 14:16:40 by lojesu           ###   ########.fr       */
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
}				t_item;

typedef struct	s_game
{
	int			n;
	int			end;
	int			*top;
	int			y[2];
	int			depth;
	int			ny[2];
	int			start;
	int			now[4];
	int			*bottom;
	int			*render;
	int			next[4];
	int			side[2];
	int			unbound[2];
	double		text_height;
	double		farz;
	double		nearz;
	double		farside;
	double		nearside;
	double		ceil[2];
	double		floor[2];
	t_item		*head;
	t_item		*tail;
	t_item		queue[32];
	t_vec2d		t[2];
	t_vec2d		v[2];
	t_vec2d		size[2];
	t_vec2d		org[2];
	t_sector	*s;
}				t_game;
/*
**	keyboard.c
*/

void			game_keyboard(t_env *env);

/*
**	movement.c
*/

void			move(t_env *env);
void			jump(t_env *env, t_cam *cam);

/*
**	camera.c
*/

void			update_cam(t_env *env, t_vec2d vel);
void			cam_height(t_env *env, int32_t crouch);
void			cam_motion(t_env *env, t_cam *cam, int x, int y);

/*
**	engine.c
*/

void			physics(t_env *env);
void			graphics(t_env *env, t_game *var);

/*
**	physics
*/

void			vertical_movement(t_env *env, t_sector sector, double height);
void			horizontal_movement(t_env *env, t_vec2d p, t_vec2d vel,
									double view);
int32_t			check_collisions(t_vec2d p, t_vec2d v, t_vec2d w1, t_vec2d w2);

#endif
