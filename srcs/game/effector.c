#include "structs.h"
#include <stdint.h>
#include "utils.h"

void	doors(t_env *env, int t)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	k;
	int			l;

	i = -1;
	while (++i < env->zones)
	{
		if (env->sector[i].type == -t)
		{
			j = -1;
			while (++j < env->sector[i].points)
			{
				l = env->sector[i].door_neighbor[j];
				if (l > -1 && env->sector[l].type != -t)
					env->sector[i].neighbor[j] = l;
				k = -1;
				l = env->sector[i].neighbor[j];
				while (l > -1 && ++k < env->sector[l].points)
					if (env->sector[env->sector[l].door_neighbor[k]].type == -t)
						env->sector[l].neighbor[k]
							= env->sector[l].door_neighbor[k];
			}
		}
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
		if (env->sector[s].type > END && env->data.money >= (uint32_t)env->sector[s].data)
		{
			env->data.money -= env->sector[s].data;
			env->sector[s].data = 0;
			doors(env, env->sector[s].type);
		}
	}
	env->st_fl = SDL_GetTicks();
	if (env->st_fl > env->old_st_fl + 200)
	{
		if (env->sector[s].type == GENERATOR)
			env->data.life -= env->sector[s].data / 5;
		if (env->sector[s].type == MONEY)
			env->data.money += (double)env->sector[s].data / 5;
		env->old_st_fl = env->st_fl;
	}
}
