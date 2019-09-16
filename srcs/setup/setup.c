#include "libft.h"
#include "env.h"
#include "doom.h"

static void	env_setup(t_env *env)
{
	env->w = WIDTH;
	env->h = HEIGHT;
}

void		setup(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	env_setup(env);
	graphic_setup(env, &env->sdl);
}
