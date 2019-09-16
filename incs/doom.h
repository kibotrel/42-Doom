#ifndef DOOM_H
# define DOOM_H

# include "SDL.h"

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
}					t_sdl;

typedef struct		s_env
{
	int				w;
	int				h;
	int				state;
	t_sdl			sdl;
}					t_env;

/*
**	setup/setup.c
*/

void				setup(t_env *env);

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
