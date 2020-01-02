#include <stdlib.h>
#include "game.h"

void	engine_clean(t_game *var)
{
	if (var->top)
		free(var->top);
	if (var->bottom)
		free(var->bottom);
	if (var->render)
		free(var->render);
}
