/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:10 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 15:33:14 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "SDL.h"
# include "SDL_ttf.h"
# include "bmp.h"

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
	E_TTF_INIT,
	E_TTF_FONT,
	E_TTF_RENDER,
	E_SDL_BLIT,
	E_BMP_PARSE,
	NB_ERRORS
}						t_status;

/*
**	Structures
*/

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_sdl
{
	t_bmp			bmp;
	TTF_Font		*font;
	SDL_Event		event;
	SDL_Color		color;
	SDL_Window		*win;
	SDL_Surface		*screen;
}					t_sdl;

typedef struct		s_data
{
	int				f_size;
	t_point			ui;
	t_point			size;
}					t_data;

typedef struct		s_env
{
	int				w;
	int				h;
	char			*error[NB_ERRORS];
	t_sdl			sdl;
	t_win			win;
	t_data			data;
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
void				draw_text(t_env *env, t_sdl *sdl);
void				draw_buttons(t_point ui, t_sdl *sdl, int color);
void				draw_rectangle(t_sdl *sdl, t_point ui, int color, int n);

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

void				clean(t_env *env, int error);

/*
**	utils/graphic.c
*/

void				draw_pixel(SDL_Surface *win, int x, int y, int color);
void				text_to_screen(t_env *env, t_sdl *sdl, char *text, int pos);

/*
**	utils/data.c
*/

char				*get_string(int n);
void				paste_position(SDL_Rect *pos, int x, int y);
void				police_color(SDL_Color *color, int r, int g, int b);

/*
**	utils/maths
*/

void				scale_text(t_env *e, SDL_Rect *where, char *text, int pos);

#endif
