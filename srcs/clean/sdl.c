#include "SDL.h"
#include "doom.h"

void	clean_sdl(t_sdl *sdl)
{
	if (sdl->ren)
		SDL_DestroyRenderer(sdl->ren);
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
	SDL_Quit();
}
