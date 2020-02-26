#include <math.h>
#include "libft.h"
#include "setup.h"

void	floor_and_ceil_setup(t_cam *c, t_game *var)
{
	double	octant;

	ft_bzero(&var->cast, sizeof(t_cast));
	octant = ft_degrees(c->angle);
	var->cast.cam = (t_vec2d){c->pos.x, c->pos.y};
	var->cast.normal = (t_vec2d){c->pos.x + 1 * c->cos, c->pos.y + 1 * c->sin};
	var->cast.normal.x = var->cast.normal.x - c->pos.x;
	var->cast.normal.y = var->cast.normal.y - c->pos.y;
	if (octant >= 135 && octant < 270)
		var->cast.normal = (t_vec2d){var->cast.normal.y, var->cast.normal.x};
	else
		var->cast.normal = (t_vec2d){-var->cast.normal.y, var->cast.normal.x};
	var->cast.size = sqrt(pow(var->cast.normal.x - c->pos.x, 2) + pow(var->cast.normal.y - c->pos.y, 2));
	// if (!var->thread)
	// 	printf("[%f,%f]\n", var->cast.normal.x, var->cast.normal.y);
}
