#include "utils.h"
#include "env.h"

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
	int		i;

	if (env->old_st_fl != env->st_fl)
	{
			printf("%d\n", env->sector[env->cam.sector].type);
		if (env->sector[env->cam.sector].type == 1)
		{
			env->cam.pos.z += 10;
			env->sector[env->cam.sector].floor += 10;;
			env->sector[env->cam.sector].type = 2;
		}
		else if (env->sector[env->cam.sector].type == 2)
		{
			env->cam.pos.z -= 10;
			env->sector[env->cam.sector].floor -= 10;;
			env->sector[env->cam.sector].type = 1;
		}
		else if (env->sector[env->cam.sector].type == 3)
		{
			i = -1;
			while (++i < env->sector[env->cam.sector].num_link)
			{
				env->sector[env->sector[env->cam.sector].link[i]].floor =
					env->sector[env->cam.sector].floor;
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
