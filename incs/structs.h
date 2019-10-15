/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:48:17 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 19:22:45 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "SDL.h"
# include "SDL_ttf.h"
# include "bmp.h"
# include "enums.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_pos
{
	double		x;
	double		y;
	double		z;
}				t_pos;

/*
**	Informations about the menu display.
*/

typedef struct	s_ui
{
	int			button;						// Index to draw
	int			background;					// Index in the asset list
	t_point		min;						// Start point for buttons
	t_point		max;						// End point for buttons
}				t_ui;

/*
** Miscelaneous informations.
*/

typedef struct	s_data
{
	int			f_size;						// Font size
	t_ui		ui;							// Menu informations
	t_point		size;						// Text dimensions
}				t_data;

/*
**	Player informations.
*/

typedef struct	s_player
{
	t_pos		position;					// Real player position
	double		angle;						// What the player is seeing (degrees)
	double		speed;						// Modify deplacement speed
}				t_player;

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
**	Main structure.
*/

typedef struct	s_env
{
	int			w;							// Width of the window
	int			h;							// Height of the window
	int			input[SDL_NUM_SCANCODES];	// Handle key inputs
	char		*asset[NB_ASSETS];			// Array of path to assets
	char		*error[NB_ERRORS];			// Array of error messages
	t_sdl		sdl;						// SDL structure
	t_win		win;						// Enum for window state
	t_data		data;						// Structure for miscelaneous informations

	t_pos		pos;						// Absolute player position
	t_point		vertex[4];					// Rectangle that delimit the space
	t_player	player;						// Player informations
	t_point		wall[8];					// Array of points that goes in pair to from walls withing space
}				t_env;

/*
**	Informations for utils/graphic.c - draw_line() function.
*/

typedef struct		s_line
{
	int				error;		// Current error
	int				offset;		// size of the line
	t_point			sign;		// Slope of the line
	t_point			delta;		// Global error
}					t_line;

#endif
