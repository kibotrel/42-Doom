#include "utils.h"
#include "env.h"
#include "libft.h"

void	jump(t_env *env, t_cam *cam)
{
	if (cam->fly > 0
			&& env->sector[cam->sector].ceil - cam->pos.z > MARGIN_HEAD)
		cam->pos.z += 0.25;
	else if (cam->ground)
	{
		cam->v.z += 0.75;
		cam->fall = 1;
	}
}

void	sector_triger(t_env *env)
{
	int			i;
	int			s;
	uint32_t	j;
	uint32_t	k;

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
	if (env->old_st_fl != env->st_fl)
	{
		if (env->sector[s].type == 3)
		{
			i = -1;
			while (++i < env->sector[s].num_link)
			{
				j = 0;
				while (j < env->sector[env->sector[s].link[i]].points)
				{
					if (env->sector[env->sector[env->sector[s].link[i]].doors_neighbor[j]].type != 4)
					{
						env->sector[env->sector[s].link[i]].neighbor[j] = env->sector[env->sector[s].link[i]].doors_neighbor[j];
						env->sector[env->sector[s].link[i]].type = -4;
					}
					k = 0;
					while (k < env->sector[env->sector[env->sector[s].link[i]].neighbor[j]].points)
					{
						if (env->sector[env->sector[env->sector[s].link[i]].neighbor[j]].doors_neighbor[k] == env->sector[s].link[i])
							env->sector[env->sector[env->sector[s].link[i]].neighbor[j]].neighbor[k] = env->sector[s].link[i];
						++k;
					}
					++j;
				}
			}
		}
	}
}

void	move(t_env *env)
{
	t_vec2d		v;

	v = v2d(0, 0);
	speed_check(env);
	if (env->input[SDL_SCANCODE_W])
	{
		v.x += env->cam.cos * (env->cam.speed * 0.2);
		v.y += env->cam.sin * (env->cam.speed * 0.2);
	}
	if (env->input[SDL_SCANCODE_S])
	{
		v.x -= env->cam.cos * (0.5 * env->cam.speed * 0.2);
		v.y -= env->cam.sin * (0.5 * env->cam.speed * 0.2);
	}
	if (env->input[SDL_SCANCODE_A])
	{
		v.x += env->cam.sin * (0.75 * env->cam.speed * 0.2);
		v.y -= env->cam.cos * (0.75 * env->cam.speed * 0.2);
	}
	if (env->input[SDL_SCANCODE_D])
	{
		v.x -= env->cam.sin * (0.75 * env->cam.speed * 0.2);
		v.y += env->cam.cos * (0.75 * env->cam.speed * 0.2);
	}
	velocity(env, &env->cam, v);
}
