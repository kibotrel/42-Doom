#include "structs.h"

void	game_click(t_env *env, int x, int y)
{
	(void)x;
	(void)y;
	if (env->state == PLAY && !env->data.shot)
	{
		env->tick.shot.old = SDL_GetTicks();
		env->data.shot = 1;
	}
}
