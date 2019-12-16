#include "game.h"
#include "libft.h"
#include "utils.h"

void	game_setup(t_env *env, t_game *var)
{
	uint32_t	i;

	i = 0;
	ft_bzero(var, sizeof(t_game));
	var->head = var->queue;
	var->tail = var->queue;
	var->top = malloc(sizeof(int) * env->w);
	var->bottom = malloc(sizeof(int) * env->w);
	var->render = malloc(sizeof(int) * env->zones);
	var->nearz = 1e-4;
	var->farz = 5;
	var->nearside = 1e-5;
	var->farside = 20;
	while ((int32_t)i < env->w)
	{
		if (i < env->zones)
			var->render[i] = 0;
		var->top[i] = 0;
		var->bottom[i++] = env->h - 1;
	}
	*var->head = item(env->cam.sector, 0, env->w - 1);
	if (++var->head == var->queue + 32)
		var->head = var->queue;
}
