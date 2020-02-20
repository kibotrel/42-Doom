#include "structs.h"
#include <stdint.h>
#include "utils.h"

void	doors(t_env *env, int type)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	k;

	i = 0;
	while (i < env->zones)
	{
		if (env->sector[i].type == type)
			env->sector[i].type = EFF_NONE;
		if (env->sector[i].type == -type)
		{
			j = 0;
			while (j < env->sector[i].points)
			{
				if (env->sector[i].doors_neighbor[j] > -1 && env->sector[env->sector[i].doors_neighbor[j]].type != -type)
					env->sector[i].neighbor[j] = env->sector[i].doors_neighbor[j];
				k = 0;
				while (env->sector[i].neighbor[j] > -1 && k < env->sector[env->sector[i].neighbor[j]].points)
				{
					if (env->sector[env->sector[env->sector[i].neighbor[j]].doors_neighbor[k]].type == -type)
						env->sector[env->sector[i].neighbor[j]].neighbor[k] = env->sector[env->sector[i].neighbor[j]].doors_neighbor[k];
					++k;
				}
				++j;
			}
			env->sector[i].type = EFF_NONE;
		}
		++i;
	}
}

void	sector_triger(t_env *env)
{
	int			s;

	s = env->cam.sector;
	if (env->sector[s].type == ELEVATOR)
	{
		if (env->input[SDL_SCANCODE_E])
		{
			++env->cam.pos.z;
			++env->sector[s].floor;
		}
		if (env->input[SDL_SCANCODE_Q])
		{
			--env->cam.pos.z;
			--env->sector[s].floor;
		}
		if (env->sector[s].floor >= env->sector[s].ceil - 5)
		{
			--env->cam.pos.z;
			env->sector[s].floor = env->sector[s].ceil - 6;
		}
	}
	if (env->input[SDL_SCANCODE_E])
	{
		if (env->sector[s].type > END)
			doors(env, env->sector[s].type);
	}
	env->st_fl = SDL_GetTicks();
	if (env->st_fl > env->old_st_fl + 200)
	{
		if (env->sector[s].type == GENERATOR)
			env->data.life -= 1;
		if (env->sector[s].type == MONEY)
			++env->data.money;
		env->old_st_fl = env->st_fl;
	}
}
