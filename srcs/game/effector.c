#include "structs.h"
#include <stdint.h>
#include "utils.h"
#include "editor.h"

void	doors2(t_env *env, int t, uint32_t i, uint32_t j)
{
	uint32_t	k;
	int			l;

	l = env->sector[i].door_neighbor[j];
	if (l > -1 && env->sector[l].type != -t)
		env->sector[i].neighbor[j] = l;
	k = -1;
	l = env->sector[i].neighbor[j];
	while (l > -1 && ++k < env->sector[l].points)
		if (env->sector[l].door_neighbor[k] > -1
				&& env->sector[env->sector[l].door_neighbor[k]].type == -t)
			env->sector[l].neighbor[k] = env->sector[l].door_neighbor[k];
}

void	doors(t_env *env, int t)
{
	uint32_t	i;
	uint32_t	j;

	i = -1;
	if (!env->tuto || env->test.all_move)
	{
		if (t == 6 && env->tuto)
			env->test.door = 1;
		while (++i < env->zones)
		{
			if (env->sector[i].type == -t)
			{
				j = -1;
				while (++j < env->sector[i].points)
				{
					doors2(env, t, i, j);
				}
			}
		}
	}
}

void	pre_door(t_env *env, int s)
{
	if (env->input[SDL_SCANCODE_E])
	{
		if (env->sector[s].type > END
				&& env->data.money >= (uint32_t)env->sector[s].data)
		{
			env->data.money -= env->sector[s].data;
			env->sector[s].data = 0;
			doors(env, env->sector[s].type);
		}
		else if (env->data.money < (uint32_t)env->sector[s].data
				&& env->sector[s].type > END)
			poor(env);
	}
}

void	effector(t_env *env, int s)
{
	if (env->sector[s].type == GENERATOR)
		display_text(RED, init_vertex(env->w / 2 - 100, env->h / 2 - 500),
				"Warning", env);
	if (env->sector[s].type == MONEY)
		display_text(YELLOW, init_vertex(env->w / 2 - 100, env->h / 2 - 500),
				"Earning money", env);
	env->st_fl = SDL_GetTicks();
	if (env->st_fl > env->old_st_fl + 200)
	{
		if (env->sector[s].type == GENERATOR && env->cam.ground == 1)
			env->data.life -= (double)env->sector[s].data / 5;
		if (env->sector[s].type == MONEY)
			env->data.money += (double)env->sector[s].data / 5;
		env->old_st_fl = env->st_fl;
	}
}

void	sector_triger(t_env *env)
{
	int			s;

	s = env->cam.sector;
	if (env->sector[s].type == EFF_ELEV)
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
	effector(env, s);
	pre_door(env, s);
}
