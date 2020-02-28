#include "structs.h"

void	hard_map_last(t_env *env)
{
	env->sector[0].texture = 0;
	env->sector[0].type = 0;
	env->sector[0].data = 0;
	env->sector[0].light = -1;
	env->sector[0].floor = -3;
	env->sector[3].type = 4;
	env->sector[4].neighbor[4] = -1;
	env->sector[0].gravity = 0.1;
	env->sector[4].neighbor[5] = -1;
	env->zones = 8;
}
