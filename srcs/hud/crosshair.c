#include "structs.h"

void	negative(SDL_Surface *win, t_pos p)
{
	int		*pixel;

	pixel =  win->pixels + p.y * win->pitch + p.x * win->format->BytesPerPixel;
	*pixel = ~*pixel;
}

void	crosshair(t_env *env)
{
	t_pos	p;

	p.y = env->h / 2 - 11;
	while (++p.y < env->h / 2 + 11)
	{
		p.x = env->w / 2 - 2;
		while (++p.x < env->w / 2 + 2)
			negative(env->sdl.screen, p);
	}
	p.y = env->h / 2 - 2;
	while (++p.y < env->h / 2 + 2)
	{
		p.x = env->w / 2 - 11;
		while (++p.x < env->w / 2 + 11)
			if (p.x < env->w / 2 - 1 || p.x > env->w / 2 + 1)
				negative(env->sdl.screen, p);
	}
}
