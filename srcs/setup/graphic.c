#include "SDL.h"
#include "libft.h"
#include "env.h"
#include "doom.h"

#include <stdio.h>

void	graphic_setup(t_env *env, t_sdl *sdl)
{
	if (!SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO))
		printf("Error : init\n");
	if (!(sdl->win = SDL_CreateWindow("", 0, 0, 600, 400, 0)))
		printf("Error : win\n");
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1, SDL_RENDERER_TARGETTEXTURE)))
		printf("Error : ren\n");
}
