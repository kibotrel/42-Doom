#include <math.h>
#include "env.h"
#include "game.h"
#include "clean.h"
#include "setup.h"
#include "utils.h"
#include "texture.h"

void	physics(t_env *env)
{
	double		sight; // State and height of the camera (standing or crouching)

	sight = env->cam.sneak ? SNEAK_H : CAM_H;
	env->cam.ground = !env->cam.fall;
	// Vertical collision checks (along z axis)
	if (env->cam.fall)
		vertical_movement(env, env->sector[env->cam.sector], sight);
	// Horizontal collisions checks (along x and y axis)
	if (env->cam.move)
		horizontal_movement(env, env->cam.pos, env->cam.v, sight);
}

void	graphics(t_env *env, t_game *var)
{
	uint32_t	i;
	uint32_t	j;
	t_item		now;

	//WORK IN PROGRESS TEXTURES

	// t_bmp		bmp;
	// bmp_to_array("/Users/lojesu/exo42/42-Doom/srcs/texture/wall1.bmp", &bmp);

	// PS : Vu que la structure du code à changé, ce que tu es entrain de faire ce trouve maintenant dans
	// draw_screen() tu auras surement besoin de changer le prototype mais tout y es !

	i = 0;
	while(i++ == 0 || var->head != var->tail)
	{
		j = 0;
		if (cycle_check(env, var, &now)) // Check if we already processed a sector twice and if MAQ_QUEUE depth loop are reached for the current secto
			continue;
		while (j < var->s->points)
		{
			transform(&env->cam, var, j); // Move, rotate and transform the wall vertices to be in front of the camera in Pseudo3D
			if (!bound_view(var) || !scale(env, var, &now)) // Fix camera view from distance to wall problems
			{
				j++;
				continue;
			}
			draw_setup(env, var, &now, j); // Find screen coordinates corresponding to the wall vertices and ceil/floor height
			draw_screen(env, var); // <----- Affichage ici : Murs - Sols - Plafonds
			check_depth(var, var->start, var->end);
			j++;
		}
	}
	engine_clean(var);
}
