#include "game.h"
#include "utils.h"

void	transform(t_cam *cam, t_game *var, t_vec2d p1, t_vec2d p2)
{
	var->v[0] = v2d(p1.x - cam->pos.x, p1.y - cam->pos.y);
	var->v[1] = v2d(p2.x - cam->pos.x, p2.y - cam->pos.y);
	var->t[0].x = var->v[0].x * cam->sin - var->v[0].y * cam->cos;
	var->t[0].y = var->v[0].x * cam->cos + var->v[0].y * cam->sin;
	var->t[1].x = var->v[1].x * cam->sin - var->v[1].y * cam->cos;
	var->t[1].y = var->v[1].x * cam->cos + var->v[1].y * cam->sin;
}

void	bound_view(t_game *var)
{
	t_vec2d i1 = intersect(var->t[0].x,var->t[0].y,var->t[1].x,var->t[1].y, -var->nearside,var->nearz, -var->farside,var->farz);
	t_vec2d i2 = intersect(var->t[0].x,var->t[0].y,var->t[1].x,var->t[1].y, var->nearside,var->nearz, var->farside,var->farz);
	if (var->t[0].y < var->nearz)
		var->t[0] = (i1.y > 0 ? v2d(i1.x, i1.y) : v2d(i2.x, i2.y));
	if (var->t[1].y < var->nearz)
		var->t[1] = (i1.y > 0 ? v2d(i1.x, i1.y) : v2d(i2.x, i2.y));
}
