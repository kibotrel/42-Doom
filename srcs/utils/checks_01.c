#include "structs.h"

void	speed_check(t_env *env)
{
	if (SDL_GetModState() & KMOD_LCTRL)
		env->cam.speed *= 2;
}
