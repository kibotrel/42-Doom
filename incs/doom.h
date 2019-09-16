/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:10 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/16 16:53:02 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "SDL.h"
# include "env.h"

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
	int				status;
	char			*error[NB_ERRORS + 1];
	t_sdl			sdl;
}					t_env;

/*
**	core/hooks.c
*/

void				hooks(t_env *env, t_sdl *sdl);

/*
**	core/keyboard.c
*/

void				handle_keyboard(t_env *env, t_sdl *sdl);

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
**	clean/sdl.c
*/

void				clean_sdl(t_sdl *sdl);

#endif
