#include "env.h"
#include "structs.h"
#include "libft.h"
#include "editor.h"

static void		third_step(t_env *env)
{
	if (env->cam.sector == 3)
		display_text(WHITE, init_vertex(env->w / 2 - 400,
					env->h / 2 - 50), TUTO_DMG, env);
	else if (env->test.jetpack)
	{
		if (!env->test.elevator)
			display_text(WHITE, init_vertex(env->w / 2 - 400,
						env->h / 2 - 50), TUTO_ELTR, env);
		if (env->sector[env->cam.sector].type == 5)
			env->test.elevator = 1;
	}
	else if (env->sector[env->cam.sector].type == 1)
	{
		display_text(WHITE, init_vertex(env->w / 2 - 400,
					env->h / 2 - 50), TUTO_MONEY, env);
		display_text(WHITE, init_vertex(env->w / 2 - 400,
					env->h / 2), TUTO_JETPACK, env);
	}
}

static void		sec_step(t_env *env)
{
	if (env->test.jump)
	{
		if (env->test.crouch)
			third_step(env);
		else
			display_text(WHITE, init_vertex(env->w / 2 - 400,
						env->h / 2 - 50), TUTO_CROUCH, env);
	}
	else
		display_text(WHITE, init_vertex(env->w / 2 - 400, env->h / 2 - 50),
				TUTO_JUMP, env);
}

void			tuto(t_env *env)
{
	int		check[5];
	int		i;

	i = -1;
	while (++i < 5)
		check[i] = 0;
	if (env->test.all_move || (env->test.move[0] && env->test.move[1]
				&& env->test.move[2] && env->test.move[3]))
	{
		env->test.all_move = 1;
		if (env->test.door)
			sec_step(env);
		else
			display_text(WHITE, init_vertex(env->w / 2 - 400, env->h / 2 - 50),
					TUTO_DOOR, env);
	}
	else
		display_text(WHITE, init_vertex(env->w / 2 - 200, env->h / 2 - 50),
				TUTO_MOVE, env);
}
