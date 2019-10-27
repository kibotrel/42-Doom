/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:48:17 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/28 00:32:27 by demonwaves       ###   ########.fr       */
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
	int8_t		background;					// Index in the asset list
	uint8_t		button;						// Index to draw
	t_pos		min;						// Start point for buttons
	t_pos		max;						// End point for buttons
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

/*
**	Player informations.
*/

typedef struct	s_cam
{
	double		gap;						// Distance between angles
	double		angle;						// Angle to look at
	double		cos;						// cos(angle) for optimizations
	double		sin;						// sin(angle) for optimizations
	t_vec3d		pos;						// Cam position in space
	t_vec3d		speed;						// Motion vector for movement
	uint32_t	sector;						// Which sector the player is in
}				t_cam;

/*
**	Sector informations
*/

typedef struct	s_sector
{
	t_pos		*vextex						// Array of vertices
	double		ceil;						// Ceilling height
	double		floor;						// Floor height
	uint32_t	points						// Number of vertices in the sector
}


/*
**	Main structure.
*/

typedef struct	s_env
{
	char		*asset[NB_ASSETS];			// Array of path to assets
	char		*error[NB_ERRORS];			// Array of error messages
	t_sdl		sdl;						// SDL structure
	t_win		win;						// Enum for window state
	t_cam		cam;						// Camera informations
	t_data		data;						// Structure for miscelaneous informations
	t_sector	*sector;					// Array of sectors
	int32_t		w;							// Width of the window
	int32_t		h;							// Height of the window
	int32_t		input[SDL_NUM_SCANCODES];	// Handle key inputs
	uint32_t	zones;						// Number of sectors in the map
	uint32_t	Ssetup;						// TEMPORARY
}				t_env;

#endif
