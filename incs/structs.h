/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:48:17 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/08 03:40:30 by vivi             ###   ########.fr       */
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
	t_pos		min;						// Start point for buttons
	t_pos		max;						// End point for buttons
	int8_t		background;					// Index in the asset list
	uint8_t		button;						// Index to draw
}				t_ui;

/*
** Graphic library informations.
*/

typedef struct	s_sdl
{
	t_bmp		bmp[NB_ASSETS];				// List of assets
	TTF_Font	*font;						// Loaded font
	SDL_Event	event;						// Handle SDL events
	SDL_Color	color;						// Font color
	SDL_Window	*win;						// SDL Window
	SDL_Surface	*screen;					// Window surface
}				t_sdl;

/*
** Miscelaneous informations.
*/

typedef struct	s_data
{
	t_ui		ui;							// Menu informations
	uint8_t		f_size;						// Font size
	uint32_t 	w_size;						// Window size in bytes
}				t_data;

typedef struct	s_cam
{
	double 		cos;
	double		gap;
	double 		sin;
	double 		angle;
	double		speed;
	t_vec2d		fov;						// Perspective angle
	t_vec3d		v;							// Velocity
	t_vec3d		pos;
	uint8_t		fall;
	uint8_t		move;
	uint8_t		sneak;
	uint8_t		ground;						// Position
	uint32_t	sector;						// Current location within the map
}				t_cam;

typedef	struct	s_sector
{
	int			*neighbor;					 // Each edge may have a corresponding neighboring sector
	double		ceil;
	double		floor;
	t_vec2d		*vertex;
	uint32_t	points;						 // How many vertexes there are

}				t_sector;
/*
**	Main structure.
*/

typedef struct	s_env
{
	char		*asset[NB_ASSETS];			// Array of path to assets
	char		*error[NB_ERRORS];			// Array of error messages
	t_cam		cam;						// Engine point of view
	t_sdl		sdl;						// SDL structure
	t_win		win;						// Enum for window state
	t_data		data;						// Structure for miscelaneous informations
	int32_t		w;							// Width of the window
	int32_t		h;							// Height of the window
	int32_t		input[SDL_NUM_SCANCODES];	// Handle key inputs
	t_sector	*sector;					// Map informations
	uint32_t	setup;						// TEMPORARY
	uint32_t	zones;
}				t_env;

#endif
