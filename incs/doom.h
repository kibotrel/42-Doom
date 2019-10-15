/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:10 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 17:41:52 by kibotrel         ###   ########.fr       */
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

typedef enum			e_assets
{
	MENU_1080P,
	MENU_900P,
	MENU_768P,
	MENU_720P,
	NB_ASSETS
}						t_assets;

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
	E_BKGD,
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

typedef struct		s_pos
{
	double			x;
	double			y;
	double			z;
}					t_pos;

typedef struct		s_sdl
{
	t_bmp			bmp[NB_ASSETS];
	TTF_Font		*font;
	SDL_Event		event;
	SDL_Color		color;
	SDL_Window		*win;
	SDL_Surface		*screen;
}					t_sdl;

typedef struct		s_ui
{
	int				button;
	int				background;
	t_point			min;
	t_point			max;
}					t_ui;

typedef struct		s_data
{
	int				f_size;
	t_ui			ui;
	t_point			size;
}					t_data;

typedef struct		s_player
{
	t_pos			position;
	double			angle;
	double			speed;
}					t_player;

typedef struct		s_env
{
	int				w;
	int				h;
	int				input[SDL_NUM_SCANCODES];
	char			*asset[NB_ASSETS];
	char			*error[NB_ERRORS];
	t_pos			pos;
	t_sdl			sdl;
	t_win			win;
	t_data			data;
	t_point			vertex[4];
	t_player		player;
	t_point			wall[8];
}					t_env;

typedef struct		s_line
{
	int				error;
	int				offset;
	t_point			sign;
	t_point			delta;
}					t_line;
/*
**	core/hooks.c
*/

void				hooks(t_env *env, t_sdl *sdl);

/*
**	core/selector.c
*/

void				selector(t_env *env);

/*
**	core/game.c
*/

void				game(t_env *env);

/*
**	core/menu.c
*/

void				menu(t_env *env);
void				draw_ui(t_env *env);
void				draw_button(t_env *env, t_ui ui, int color, int n);

/*
**	core/editor.c
*/

void				editor(t_env *env);

/*
**	core/ettings.c
*/

void				settings(t_env *env);

/*
**	events/keyboard.c
*/

void				handle_keyboard(t_env *env);

/*
**	events/mouse.c
*/

void				handle_mouse(t_env *env, t_sdl *sdl);

/*
**	events/motion.c
*/

void				handle_motion(t_env *env, t_sdl *sdl);

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
**	menu/click.c
*/

void				menu_click(t_env *env, t_ui ui, int x, int y);

/*
**	menu/motion.c
*/

void				menu_hover(t_env *env, t_ui ui, int x, int y);

/*
**	clean/env.c
*/

void				clean(t_env *env, int error);

/*
**	clean/sdl.c
*/

void				sdl_clean(t_sdl *sdl);

/*
**	clean/ttf.c
*/

void				ttf_clean(t_sdl *sdl);

/*
**	utils/graphic.c
*/

void				draw_background(t_env *env, t_sdl *sdl, t_bmp img);
void				draw_line(t_env *env, t_point a, t_point b, int color);
void				draw_pixel(t_env *env, SDL_Surface *win, t_point p, int c);
void				text_to_screen(t_env *env, t_sdl *sdl, char *text, int pos);

/*
**	utils/data.c
*/

int					get_dimensions(int height);
char				*get_string(int n);
void				paste_position(SDL_Rect *pos, int x, int y);
void				line_params(t_line *line, t_point a, t_point b);
void				police_color(SDL_Color *color, int r, int g, int b);

/*
**	utils/maths.c
*/

void				scale_text(t_env *e, SDL_Rect *where, char *text, int pos);

/*
**	game/keyboard.c
*/

void				game_keyboard(t_env *env);

/*
**	game/movement.c
*/

void				update_position(t_env *env);

/*
**	game/camera.c
*/

void				update_angle(t_env *env);

/*
**	editor/keyboard.c
*/

void				editor_keyboard(t_env *env);
#endif
