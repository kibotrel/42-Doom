/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:10 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/19 14:03:09 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "SDL.h"
# include "env.h"

/*
**	Enumerators
*/

typedef enum			e_win
{
	MENU,
	GAME,
	EDITOR,
	SETTINGS,
	QUIT
}						t_win;

typedef enum			e_status
{
	NOTHING,
	E_FILENAME,
	E_SDL_INIT,
	E_SDL_WIN,
	E_SDL_WINSURF,
	E_SDL_UPDATE,
	E_TTF_INIT
}						t_status;

/*
**	Structures
*/

typedef struct		s_point
{
	int				x;						// x coordinate
	int				y;						// y coordinate
}					t_point;

typedef struct		s_sdl
{
	SDL_Event		event;					// Handle keyboard, mouse and window events
	SDL_Window		*win;					// Window identifier
	SDL_Surface		*screen;				// Display informations linked to the window
}					t_sdl;

typedef struct		s_data
{
	t_point			ui;						// Menu ratios for menu interface spacing
}					t_data;

typedef struct		s_env
{
	int				w;						// Width of the window
	int				h;						// Height of the window
	int				run;					// Game loop breaker
	char			*error[NB_ERRORS + 1];	// Array of error messages
	t_sdl			sdl;					// Informations about SDL
	t_win			win;					// To know which window is displayed
	t_data			data;					// Useful informations
	t_status		status;					// Code to retrieve upon exit
}					t_env;

/*
**	core/hooks.c
*/

void				hooks(t_env *env, t_sdl *sdl);

/*
**	core/selector.c
*/

void				selector(t_env *env);

/*
**	events/keyboard.c
*/

void				handle_keyboard(t_env *env, t_sdl *sdl);

/*
**	events/mouse.c
*/

void				handle_mouse(t_env *env, t_sdl *sdl);

/*
**	setup/setup.c
*/

void				env_setup(t_env *env);

/*
**	setup/graphic.c
*/

void				graphic_setup(t_env *env, t_sdl *sdl);

/*
**	usage/usage.c
*/

void				usage(void);

/*
**	menu/menu.c
*/

void				menu(t_env *env);

/*
**	menu/game.c
*/

void				game(t_env *env);

/*
**	menu/editor.c
*/

void				editor(t_env *env);

/*
**	menu/ettings.c
*/

void				settings(t_env *env);


/*
**	clean/sdl.c
*/

void				clean_sdl(t_sdl *sdl);

/*
**	utils/graphic.c
*/

void				draw_buttons(t_point ui, t_sdl *sdl, int color);
void				draw_pixel(SDL_Surface *win, int x, int y, int color);
void				draw_rectangle(t_sdl *sdl, t_point ui, int color, int n);

#endif
