/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:22:14 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/25 18:45:21 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "env.h"
# include "structs.h"

typedef struct	s_cast
{
	double		r;			// Relative distance to the camera where the projected point is
	double		s;			// Hit coordinate side along camera plane vector
	double		dot[2];		// Vector product hit - camera-plane
	double		size;		// Normal camera-plane vector size
	double		adjacent;
	double		distance;	// Perpendicular distance from hit point to the camera plane
	double		opposite;
	double		hypotenuse;
	t_vec2d		cam;		// Player position
	t_vec2d		hit;		// Wall hit coordinate
	t_vec2d		proj;		// Projected point from Point to line algorithm
	t_vec2d		normal;		// Normal camera-plane vector
}				t_cast;

typedef struct	s_item
{
	int			min;
	int			max;
	int			sector;
}				t_item;

typedef struct	s_game
{
	int			i;
	int			n;
	int			sky;
	int			end;
	int			*top;
	int			y[2];
	int			depth;
	int			ny[2];
	int			start;
	int			now[4];
	int			sector;
	int			thread;
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
	t_cast		cast;
	t_item		*head;
	t_item		*tail;
	t_item		queue[32];
	t_vec2d		t[2];
	t_vec2d		v[2];
	t_vec2d		size[2];
	t_vec2d		org[2];
	t_sector	*s;
	uint32_t	j;
}				t_game;

typedef struct	s_skybox
{
	t_pos		shift;
	uint32_t	draw;
	uint32_t	*image;
}				t_skybox;

/*
**	keyboard.c
*/

void			game_keyboard(t_env *env);

/*
**	movement.c
*/

void			fly(t_env *env);
void			move(t_env *env);
void			jump(t_env *env, t_cam *cam);

/*
**	camera.c
*/

void			fov_update(t_env *env);
void			update_cam(t_env *env, t_vec2d vel);
void			cam_height(t_env *env, int32_t crouch);
void			cam_motion(t_env *env, t_cam *cam, int x, int y);
/*
**	engine.c
*/

void			physics(t_env *env);
void			graphics(t_env *env);

/*
**	physics.c
*/

void			vertical_movement(t_env *env, t_sector sector, double height);
void			horizontal_movement(t_env *env, t_vec2d p, t_vec2d vel,
									double view);
int32_t			check_collisions(t_vec2d p, t_vec2d v, t_vec2d w1, t_vec2d w2);

/*
**	hud.c
*/

void			hud(t_env *env);
void			toggle_hud(t_env *env);
void			toggle_infos(t_env *env);

/*
**	click.c
*/

void			game_click(t_env *env, int x, int y);

/*
**	reload.c
*/

void			reload(t_env *env);

#endif
