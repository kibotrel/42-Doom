#include "editor.h"
#include "env.h"
#include "libft.h"

void	poor(t_env *env, uint32_t data)
{
	char	*tmp;

	tmp = ft_itoa(data);
	display_text(WHITE, init_vertex(env->w / 2 - 100, env->h / 2 - 300),
			"Not enough money", env);
	display_text(WHITE, init_vertex(env->w / 2 - 100, env->h / 2 - 250),
			"You need ", env);
	display_text(WHITE, init_vertex(env->w / 2 + 50, env->h / 2 - 250),
			tmp, env);
	free(tmp);
}
