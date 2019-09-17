/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:10 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/17 15:57:08 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "SDL.h"
# include "env.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_sdl
{
	SDL_Event		event;
	SDL_Window		*win;
	SDL_Surface		*screen;
}					t_sdl;

typedef struct		s_env
{
	int				w;
	int				h;
	int				run;
	char			*error[NB_ERRORS + 1];
	t_sdl			sdl;
	t_win			win;
	t_status		status;
}					t_env;

/*
**	core/hooks.c
*/

void				hooks(t_env *env, t_sdl *sdl);

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
**	clean/sdl.c
*/

void				clean_sdl(t_sdl *sdl);

/*
**	utils/graphic.c
*/

void				draw_pixel(SDL_Surface *win, int x, int y, int color);

#endif
