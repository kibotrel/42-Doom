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
		if (t == 7 && env->tuto)
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

void	effector(t_env *env, int s)
{
	if (env->sector[s].type == LAVA)
		display_text(RED, init_vertex(env->w / 2 - 100, env->h / 2 - 500),
				"Warning", env);
	if (env->sector[s].type == MONEY)
		display_text(YELLOW, init_vertex(env->w / 2 - 100, env->h / 2 - 500),
				"Earning money", env);
	if (env->sector[s].type == HEAL)
		display_text(PINK, init_vertex(env->w / 2 - 100, env->h / 2 - 500),
				"Healing", env);
	env->st_fl = SDL_GetTicks();
	if (env->st_fl > env->old_st_fl + 200)
	{
		if (env->sector[s].type == LAVA && env->cam.ground == 1)
			env->data.life -= (double)env->sector[s].data / 5;
		if (env->sector[s].type == MONEY)
			env->data.money += (double)env->sector[s].data / 5;
		if (env->sector[s].type == HEAL && env->data.life < 100)
			env->data.life += (double)env->sector[s].data / 5;
		env->old_st_fl = env->st_fl;
	}
}

void	elevator(t_sector *sector, int s, t_cam *cam, int *input)
{
	if (sector[s].type == ELEVATOR || sector[s].type == -ELEVATOR)
	{
		if (input[SDL_SCANCODE_E] && ((sector[s].floor < sector[s].data
			+ sector[s].door_neighbor[0] && sector[s].type == ELEVATOR)
			|| (sector[s].floor < sector[s].door_neighbor[0]
			&& sector[s].type == -ELEVATOR)))
		{
			if (cam->fly != 1 || cam->pos.z <= sector[s].floor + 1)
				++cam->pos.z;
			++sector[s].floor;
		}
		if (input[SDL_SCANCODE_Q] && ((sector[s].floor
			> sector[s].door_neighbor[0] && sector[s].type == ELEVATOR)
			|| (sector[s].floor > sector[s].door_neighbor[0]
			- sector[s].data && sector[s].type == -ELEVATOR)))
		{
			if  (cam->fly != 1)
				--cam->pos.z;
			--sector[s].floor;
		}
		if (sector[s].floor >= sector[s].ceil - 5 && --cam->pos.z)
			sector[s].floor = sector[s].ceil - 6;
	}
}

void	sector_triger(t_env *env)
{
	int			s;

	s = env->cam.sector;
	elevator(env->sector, s, &env->cam, env->input);
	effector(env, s);
	if (env->input[SDL_SCANCODE_E])
		doors(env, env->sector[s].type);
}
