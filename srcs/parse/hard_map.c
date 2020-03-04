#include "env.h"
#include "structs.h"
#include "utils.h"
#include "clean.h"
#include "parse.h"
#include "libft.h"

static void		hard_map_two(t_env *env)
{
	env->sector[0].neighbor[0] = -1;
	env->sector[0].neighbor[1] = 1;
	env->sector[0].neighbor[2] = -1;
	env->sector[0].neighbor[3] = -2;
	env->sector[0].neighbor[4] = -1;
	env->sector[0].neighbor[5] = -1;
	env->sector[0].neighbor[6] = -1;
	env->sector[0].door_neighbor[0] = -1;
	env->sector[0].door_neighbor[1] = 1;
	env->sector[0].door_neighbor[2] = -1;
	env->sector[0].door_neighbor[3] = 2;
	env->sector[0].door_neighbor[4] = -1;
	env->sector[0].door_neighbor[5] = -1;
	env->sector[0].door_neighbor[6] = -1;
	if (!(env->sector[1].neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[1].door_neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[1].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_MALLOC);
	env->sector[1].texture = 1;
	env->sector[1].type = END + 1;
	env->sector[1].data = 0;
	env->sector[1].light = -1;
	env->sector[1].floor = -1;
}

static void		hard_map_three(t_env *env)
{
	env->sector[1].ceil = 9;
	env->sector[1].gravity = 0.1;
	env->sector[1].friction = 0.5;
	env->sector[1].points = 4;
	env->sector[1].vertex[0] = v2d(35.0, 32.5);
	env->sector[1].vertex[1] = v2d(35.0, 30.0);
	env->sector[1].vertex[2] = v2d(37.5, 30.0);
	env->sector[1].vertex[3] = v2d(37.5, 32.5);
	env->sector[1].neighbor[0] = -1;
	env->sector[1].neighbor[1] = -1;
	env->sector[1].neighbor[2] = -1;
	env->sector[1].neighbor[3] = 0;
	env->sector[1].door_neighbor[0] = -1;
	env->sector[1].door_neighbor[1] = -1;
	env->sector[1].door_neighbor[2] = -1;
	env->sector[1].door_neighbor[3] = 0;
	if (!(env->sector[2].neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[2].door_neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[2].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_MALLOC);
	env->sector[2].texture = 2;
	env->sector[2].type = -(END + 1);
	env->sector[2].data = 0;
}

static void		hard_map_four(t_env *env)
{
	env->sector[2].light = -1;
	env->sector[2].floor = 0;
	env->sector[2].ceil = 20;
	env->sector[2].gravity = 0.1;
	env->sector[2].friction = 0.5;
	env->sector[2].points = 4;
	env->sector[2].vertex[0] = v2d(40, 32.5);
	env->sector[2].vertex[1] = v2d(42.5, 32.5);
	env->sector[2].vertex[2] = v2d(42.5, 35);
	env->sector[2].vertex[3] = v2d(40, 35);
	env->sector[2].neighbor[0] = -1;
	env->sector[2].neighbor[1] = -2;
	env->sector[2].neighbor[2] = -1;
	env->sector[2].neighbor[3] = -2;
	env->sector[2].door_neighbor[0] = -1;
	env->sector[2].door_neighbor[1] = 3;
	env->sector[2].door_neighbor[2] = -1;
	env->sector[2].door_neighbor[3] = 0;
	if (!(env->sector[3].neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[3].door_neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[3].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_MALLOC);
	env->sector[3].texture = 3;
}

static void		hard_map_five(t_env *env)
{
	env->sector[3].data = 5;
	env->sector[3].light = -1;
	env->sector[3].floor = 0;
	env->sector[3].ceil = 4;
	env->sector[3].gravity = 0.1;
	env->sector[3].friction = 0.5;
	env->sector[3].points = 4;
	env->sector[3].vertex[0] = v2d(42.5, 32.5);
	env->sector[3].vertex[1] = v2d(47.5, 32.5);
	env->sector[3].vertex[2] = v2d(47.5, 35.0);
	env->sector[3].vertex[3] = v2d(42.5, 35.0);
	env->sector[3].neighbor[0] = -1;
	env->sector[3].neighbor[1] = 4;
	env->sector[3].neighbor[2] = -1;
	env->sector[3].neighbor[3] = -2;
	env->sector[3].door_neighbor[0] = -1;
	env->sector[3].door_neighbor[1] = 4;
	env->sector[3].door_neighbor[2] = -1;
	env->sector[3].door_neighbor[3] = 2;
	if (!(env->sector[4].neighbor = (int*)malloc(sizeof(int) * 8)))
		clean(env, E_MALLOC);
	if (!(env->sector[4].door_neighbor = (int*)malloc(sizeof(int) * 8)))
		clean(env, E_MALLOC);
	if (!(env->sector[4].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 8)))
		clean(env, E_MALLOC);
}

void			hard_map_one(t_env *env)
{
	env->zones = 8;
	if (!(env->sector = (t_sector*)malloc(sizeof(t_sector) * 8)))
		clean(env, E_MALLOC);
	ft_bzero(env->sector, sizeof(t_sector) * 8);
	if (!(env->sector[0].neighbor = (int*)malloc(sizeof(int) * 7)))
		clean(env, E_MALLOC);
	if (!(env->sector[0].door_neighbor = (int*)malloc(sizeof(int) * 7)))
		clean(env, E_MALLOC);
	if (!(env->sector[0].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 7)))
		clean(env, E_MALLOC);
	env->sector[0].ceil = 14;
	env->sector[0].friction = 0.5;
	env->sector[0].points = 7;
	env->sector[0].vertex[0] = v2d(32.5, 32.5);
	env->sector[0].vertex[1] = v2d(35.0, 32.5);
	env->sector[0].vertex[2] = v2d(37.5, 32.5);
	env->sector[0].vertex[3] = v2d(40.0, 32.5);
	env->sector[0].vertex[4] = v2d(40.0, 35.0);
	env->sector[0].vertex[5] = v2d(40.0, 37.5);
	env->sector[0].vertex[6] = v2d(32.5, 37.5);
	hard_map_two(env);
	hard_map_three(env);
	hard_map_four(env);
	hard_map_five(env);
	hard_map_six(env);
	hard_map_last(env);
}
