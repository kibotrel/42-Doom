#include "env.h"
#include "game.h"
#include "utils.h"
#include "structs.h"

void	vertical_movement(t_env *env, t_sector sector, double cam_height)
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

void	physics(t_env *env)
{
	double sight; // State and height of the camera (standing or crouching)

	sight = env->cam.sneak ? SNEAK_H : CAM_H;
	env->cam.ground = !env->cam.fall;
	// Vertical collision checks (along z axis)
	if (env->cam.fall)
		vertical_movement(env, env->sector[env->cam.sector], sight);
	// Horizontal collisions checks (along x and y axis)
	if (env->cam.move)
	{
		float px = env->cam.pos.x;
		float py = env->cam.pos.y;
		float dx = env->cam.v.x;
		float dy = env->cam.v.y;
		const t_sector* const sect = &env->sector[env->cam.sector];
		const t_vec2d* const vert = sect->vertex;
		/* Check if the player is about to cross one of the sector's edges */
		for(unsigned s = 0; s < sect->points; ++s)
			if (IntersectBox(px , py, px + dx, py + dy, vert[s].x, vert[s].y, vert[s + 1].x, vert[s + 1].y) && PointSide(px + dx, py + dy, vert[s].x, vert[s].y, vert[s + 1].x, vert[s + 1].y) < 0)
			{
				/* Check where the hole is. */
				float hole_low = sect->neighbor[s] < 0 ?  9e9 : max(sect->floor, env->sector[sect->neighbor[s]].floor);
				float hole_high = sect->neighbor[s] < 0 ? -9e9 : min(sect->ceil, env->sector[sect->neighbor[s]].ceil);
				/* Check whether we're bumping into a wall. */
				if (hole_high < env->cam.pos.z + MARGIN_HEAD || hole_low > env->cam.pos.z - sight + MARGIN_KNEE)
				{
					/* Bumps into a wall! Slide along the wall. */
					/* This formula is from Wikipedia article "vector projection". */
					float xd = vert[s + 1].x - vert[s].x;
					float yd = vert[s + 1].y - vert[s].y;
					dx = xd * (dx * xd + yd * dy) / (xd * xd + yd * yd);
					dy = yd * (dx * xd + yd * dy) / (xd * xd + yd * yd);
					env->cam.move = 0;
				}
			}
		MovePlayer(env, dx, dy);
		env->cam.fall = 1;
	}
}
