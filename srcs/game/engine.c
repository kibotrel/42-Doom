#include <math.h>
#include "env.h"
#include "game.h"

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
		horizontal_movement(env, env->cam.pos, env->cam.v, sight);
}
