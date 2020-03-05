#include "structs.h"
#include "env.h"
#include "clean.h"
#include "utils.h"
#include "libft.h"

static void		hard_map_seven(t_env *env)
{
	env->sector[4].door_neighbor[0] = -1;
	env->sector[4].door_neighbor[1] = 5;
	env->sector[4].door_neighbor[2] = -1;
	env->sector[4].door_neighbor[3] = 6;
	env->sector[4].door_neighbor[4] = -1;
	env->sector[4].door_neighbor[5] = -1;
	env->sector[4].door_neighbor[6] = -1;
	env->sector[4].door_neighbor[7] = 3;
	if (!(env->sector[5].neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[5].door_neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[5].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_MALLOC);
	env->sector[5].texture = 5;
	env->sector[5].type = MONEY;
	env->sector[5].data = 10;
	env->sector[5].light = -1;
	env->sector[5].floor = 4;
	env->sector[5].ceil = 15;
	env->sector[5].gravity = 0.1;
	env->sector[5].friction = 0.5;
	env->sector[5].points = 4;
	env->sector[5].vertex[0] = v2d(50, 30);
	env->sector[5].vertex[1] = v2d(50, 27.5);
}

static void		hard_map_eight(t_env *env)
{
	env->sector[5].vertex[2] = v2d(52.5, 27.5);
	env->sector[5].vertex[3] = v2d(52.5, 30);
	env->sector[5].neighbor[0] = -1;
	env->sector[5].neighbor[2] = -1;
	env->sector[5].neighbor[3] = 4;
	env->sector[5].door_neighbor[0] = -1;
	env->sector[5].door_neighbor[1] = -1;
	env->sector[5].door_neighbor[2] = -1;
	env->sector[5].door_neighbor[3] = 4;
	if (!(env->sector[6].neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[6].door_neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_MALLOC);
	if (!(env->sector[6].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_MALLOC);
	env->sector[6].texture = 6;
	env->sector[6].type = ELEVATOR;
	env->sector[6].data = 13;
	env->sector[6].light = -1;
	env->sector[6].floor = 12;
	env->sector[6].ceil = 35;
	env->sector[6].gravity = 0.1;
	env->sector[6].friction = 0.5;
	env->sector[6].points = 4;
	env->sector[6].elvt = 12;
}

static void		hard_map_nine(t_env *env)
{
	env->sector[6].vertex[0] = v2d(55, 32.5);
	env->sector[6].vertex[1] = v2d(57.5, 32.5);
	env->sector[6].vertex[2] = v2d(57.5, 35);
	env->sector[6].vertex[3] = v2d(55, 35);
	env->sector[6].neighbor[0] = -1;
	env->sector[6].neighbor[1] = 7;
	env->sector[6].neighbor[2] = -1;
	env->sector[6].neighbor[3] = 4;
	env->sector[6].door_neighbor[0] = -1;
	env->sector[6].door_neighbor[1] = 7;
	env->sector[6].door_neighbor[2] = -1;
	env->sector[6].door_neighbor[3] = 4;
	if (!(env->sector[7].neighbor = (int*)malloc(sizeof(int) * 6)))
		clean(env, E_MALLOC);
	if (!(env->sector[7].door_neighbor = (int*)malloc(sizeof(int) * 6)))
		clean(env, E_MALLOC);
	if (!(env->sector[7].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 6)))
		clean(env, E_MALLOC);
	env->sector[7].texture = 7;
	env->sector[7].type = END;
	env->sector[7].data = 2;
	env->sector[7].light = -1;
	env->sector[7].floor = 25;
	env->sector[7].ceil = 40;
	env->sector[7].gravity = 0.1;
}

static void		hard_map_ten(t_env *env)
{
	env->sector[7].friction = 0.5;
	env->sector[7].points = 6;
	env->sector[7].vertex[0] = v2d(57.5, 32.5);
	env->sector[7].vertex[1] = v2d(57.5, 30);
	env->sector[7].vertex[2] = v2d(62.5, 30);
	env->sector[7].vertex[3] = v2d(62.5, 37.5);
	env->sector[7].vertex[4] = v2d(57.5, 37.5);
	env->sector[7].vertex[5] = v2d(57.5, 35);
	env->sector[7].neighbor[0] = -1;
	env->sector[7].neighbor[1] = -1;
	env->sector[7].neighbor[2] = -1;
	env->sector[7].neighbor[3] = -1;
	env->sector[7].neighbor[4] = -1;
	env->sector[7].neighbor[5] = 6;
	env->sector[7].door_neighbor[0] = -1;
	env->sector[7].door_neighbor[1] = -1;
	env->sector[7].door_neighbor[2] = -1;
	env->sector[7].door_neighbor[3] = -1;
	env->sector[7].door_neighbor[4] = -1;
	env->sector[7].door_neighbor[5] = 6;
	env->cam.pos = v3d(34, 36, 0);
	env->cam.angle = ft_radians(222);
	env->cam.sector = 0;
	env->sector[4].neighbor[6] = -1;
	env->sector[4].neighbor[7] = 3;
}

void			hard_map_six(t_env *env)
{
	env->sector[4].texture = 4;
	env->sector[4].type = JETPACK;
	env->sector[4].data = 50;
	env->sector[4].light = -1;
	env->sector[4].floor = 2;
	env->sector[4].ceil = 20;
	env->sector[4].gravity = 0.1;
	env->sector[4].friction = 0.5;
	env->sector[4].points = 8;
	env->sector[4].vertex[0] = v2d(47.5, 32.5);
	env->sector[4].vertex[1] = v2d(50, 30);
	env->sector[4].vertex[2] = v2d(52.5, 30);
	env->sector[4].vertex[3] = v2d(55, 32.5);
	env->sector[4].vertex[4] = v2d(55, 35);
	env->sector[4].vertex[5] = v2d(52.5, 37.5);
	env->sector[4].vertex[6] = v2d(50, 37.5);
	env->sector[4].vertex[7] = v2d(47.5, 35);
	env->sector[4].neighbor[0] = -1;
	env->sector[4].neighbor[1] = 5;
	env->sector[4].neighbor[2] = -1;
	env->sector[4].neighbor[3] = 6;
	hard_map_seven(env);
	hard_map_eight(env);
	hard_map_nine(env);
	hard_map_ten(env);
}
