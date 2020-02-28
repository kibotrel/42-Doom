#include "editor.h"
#include "env.h"
#include "libft.h"

void	poor(t_env *env)
{
	display_text(WHITE, init_vertex(env->w / 2 - 100, env->h / 2 - 300),
			"Not enough money", env);
	display_text(WHITE, init_vertex(env->w / 2 - 100, env->h / 2 - 250),
			"You need ", env);
	display_text(WHITE, init_vertex(env->w / 2 + 50, env->h / 2 - 250),
			ft_itoa(env->sector[env->cam.sector].data), env);
}
