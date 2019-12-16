#include "env.h"
#include "game.h"
#include "utils.h"

int32_t		check_collisions(t_vec3d p, t_vec3d v, t_vec2d w1, t_vec2d w2)
{
	if (hitbox(p.x, p.y, p.x + v.x, p.y + v.y, w1.x, w1.y, w2.x, w2.y))
	{
		if (side(p.x + v.x, + p.y + v.y, w1.x, w1.y, w2.x, w2.y) < 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static void	find_height(t_env *env, double *hole, uint32_t s)
{
	int32_t		cam;
	int32_t		neighbor;

	cam = env->cam.sector;
	neighbor = env->sector[cam].neighbor[s];
	if (neighbor < 0)
	{
		hole[0] = 9e9;
		hole[1] = -9e9;
	}
	else
	{
		hole[0] = fmax(env->sector[cam].floor, env->sector[neighbor].floor);
		hole[1] = fmin(env->sector[cam].ceil, env->sector[neighbor].ceil);
	}
}

void		vertical_movement(t_env *env, t_sector sector, double cam_height)
{
	double	newz; // The player altitude at the next frame

	env->cam.v.z -= 0.05;
	newz = env->cam.pos.z + env->cam.v.z;
	// Falling stop condition
	if (env->cam.v.z < 0 && newz < sector.floor + cam_height)
	{
		env->cam.pos.z = sector.floor + cam_height;
		env->cam.v.z = 0;
		env->cam.fall = 0;
		env->cam.ground = 1;
	}
	// Jump stop condition
	else if (env->cam.v.z > 0 && newz > sector.ceil)
	{
		env->cam.v.z = 0;
		env->cam.fall = 1;
	}
	// If moving (along z axis) after stop conditions, update player position
	if (env->cam.fall)
	{
		env->cam.pos.z += env->cam.v.z;
		env->cam.move = 1;
	}
}
void		horizontal_movement(t_env *env, t_vec3d p, t_vec3d vel, double view)
{
	uint32_t	i;
	double		hole[2];
	t_vec2d*	v = env->sector[env->cam.sector].vertex;

	i = 0;
	while (i < env->sector[env->cam.sector].points)
	{
		// Check if the player is about to cross an edge
		if (check_collisions(p, vel, v[i], v[i + 1]))
		{
			find_height(env, hole, i);
			// Check if the height of both neighbor floor and ceil allow the player to go throw the hole
			if (hole[0] > p.z - view + MARGIN_KNEE || hole[1] < p.z + MARGIN_HEAD)
			{
				// vector projection to slide on the wall
				vproj(&vel, v2d(v[i].x, v[i].y), v2d(v[i + 1].x, v[i + 1].y));
				env->cam.move = 0;
			}
		}
		i++;
	}
	update_cam(env, vel.x, vel.y);
	env->cam.fall = 1;
}
