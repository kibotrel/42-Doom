/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:48:17 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/23 19:44:55 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>
# include "SDL.h"
# include "SDL_ttf.h"
# include "bmp.h"
# include "enums.h"

typedef struct	s_pos
{
	int32_t		x;
	int32_t		y;
}				t_pos;

typedef struct	s_vec2d
{
	double		x;
	double		y;
}				t_vec2d;

typedef struct	s_vec3d
{
	double		x;
	double		y;
	double		z;
}				t_vec3d;

/*
**	Informations about the menu display.
*/

typedef struct	s_ui
{
	t_pos		min;
	t_pos		max;
	int8_t		background;
	uint8_t		button;
}				t_ui;

/*
** Graphic library informations.
*/

typedef struct	s_sdl
{
	t_bmp		bmp[NB_ASSETS];
	TTF_Font	*font;
	SDL_Event	event;
	SDL_Color	color;
	SDL_Window	*win;
	SDL_Surface	*screen;
}				t_sdl;

/*
** Miscelaneous informations.
*/

typedef struct	s_data
{
	t_ui		ui;
	uint8_t		f_size;
	uint32_t	fps;
	uint32_t	w_size;
}				t_data;

typedef struct	s_cam
{
	double		cos;
	double		gap;
	double		sin;
	double		angle;
	double		speed;
	t_vec2d		fov;
	t_vec3d		v;
	t_vec3d		pos;
	int8_t		fly;
	uint8_t		fall;
	uint8_t		move;
	uint8_t		sneak;
	uint8_t		ground;
	uint32_t	sector;
}				t_cam;

typedef	struct	s_sector
{
	int			*neighbor;
	double		ceil;
	double		floor;
	t_vec2d		*vertex;
	uint32_t	points;

}				t_sector;

/*
** Time tracking
*/

typedef struct	s_tick
{
	uint32_t	new;
	uint32_t	old;
}				t_tick;

typedef struct	s_time
{
	t_tick		fly;
	t_tick		fps;
	t_tick		frame;
}				t_time;

/*
**	Main structure.
*/

typedef struct	s_env
{
	char		*asset[NB_ASSETS];
	char		*error[NB_ERRORS];
	t_cam		cam;
	t_sdl		sdl;
	t_win		win;
	t_data		data;
	t_time		tick;
	int32_t		w;
	int32_t		h;
	int32_t		input[SDL_NUM_SCANCODES];
	t_sector	*sector;
	uint32_t	setup;
	uint32_t	zones;
}				t_env;

#endif
