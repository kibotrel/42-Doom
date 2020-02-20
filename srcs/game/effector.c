#include "structs.h"
#include <stdint.h>
#include "utils.h"

void	sector_triger(t_env *env)
{
	int			i;
	int			s;
	uint32_t	j;
	uint32_t	k;
	int			l;

	s = env->cam.sector;
	if (env->sector[s].type == 1)
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
		if (env->sector[s].type == 3)
		{
			i = -1;
			while (++i < env->sector[s].num_link)
			{
				j = 0;
				while (j < env->sector[env->sector[s].link[i]].points)
				{
					l = env->sector[env->sector[s].link[i]].doors_neighbor[j];
					if (l > -1 && env->sector[l].type != 4)
					{
						env->sector[env->sector[s].link[i]].neighbor[j] = env->sector[env->sector[s].link[i]].doors_neighbor[j];
						env->sector[env->sector[s].link[i]].type = -4;
					}
					k = 0;
					l = env->sector[env->sector[s].link[i]].neighbor[j];
					while (l > -1 && k < env->sector[l].points)
					{
						if (env->sector[l].doors_neighbor[k] == env->sector[s].link[i])
							env->sector[l].neighbor[k] = env->sector[s].link[i];
						++k;
					}
					++j;
				}
			}
		}
	}
	env->st_fl = SDL_GetTicks();
	if (env->st_fl > env->old_st_fl + 200)
	{
		if (env->sector[s].type == 2)
			env->data.life -= 1;
		if (env->sector[s].type == 5)
			++env->data.money;
		env->old_st_fl = env->st_fl;
	}
}
