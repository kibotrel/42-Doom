/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:22:14 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/26 05:26:36 by demonwaves       ###   ########.fr       */
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

typedef struct	s_local
{
	int			*ytop;
	int			*ybottom;
	int			*renderedsectors;
	t_item		queue[QUEUE_MAX];
	t_item		*head;
	t_item		*tail;
}				t_local;

typedef struct	s_graphic
{
	double		vx1;
	double		vy1;
	double		vx2;
	double		vy2;

	double		tx1;
	double		tz1;
	double		tx2;
	double		tz2;

	double		farz;
	double		nearz;
	double		farside;
	double		nearside;

	double		xscale1;
	double		yscale1;
	double		xscale2;
	double		yscale2;

	int			x1;
	int			x2;

	double		yceil;
	double		yfloor;
	double		nyceil;
	double		nyfloor;
	int			neighbor;
	int			y1a;
	int			y1b;
	int			y2a;
	int			y2b;
	int			ny1a;
	int			ny1b;
	int			ny2a;
	int			ny2b;
	int			beginx;
	int			endx;

	int			z;
	int			ya;
	int			yb;
	int			cya;
	int			cyb;

	int			nya;
	int			nyb;
	int			cnya;
	int			cnyb;
}				t_graphic;

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

/*
**	engine.c
*/

void	engine(t_env *env);

#endif
