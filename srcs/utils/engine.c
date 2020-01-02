#include "game.h"
#include "utils.h"

void	transform(t_cam *cam, t_game *var, uint32_t i)
{
	t_vec2d p1;
	t_vec2d	p2;

	p1 = var->s->vertex[i];
	p2 = var->s->vertex[(i + 1) % var->s->points];
	var->v[0] = v2d(p1.x - cam->pos.x, p1.y - cam->pos.y);
	var->v[1] = v2d(p2.x - cam->pos.x, p2.y - cam->pos.y);
	var->t[0].x = var->v[0].x * cam->sin - var->v[0].y * cam->cos;
	var->t[0].y = var->v[0].x * cam->cos + var->v[0].y * cam->sin;
	var->t[1].x = var->v[1].x * cam->sin - var->v[1].y * cam->cos;
	var->t[1].y = var->v[1].x * cam->cos + var->v[1].y * cam->sin;
}

uint8_t	bound_view(t_game *var)
{
	if (var->t[0].y <= 0 && var->t[1].y <= 0)
		return (0);
	if (var->t[0].y <= 0 || var->t[1].y <= 0)
	{
		t_vec2d i1 = intersect(var->t[0].x,var->t[0].y,var->t[1].x,var->t[1].y, -var->nearside,var->nearz, -var->farside,var->farz);
		t_vec2d i2 = intersect(var->t[0].x,var->t[0].y,var->t[1].x,var->t[1].y, var->nearside,var->nearz, var->farside,var->farz);
		if (var->t[0].y < var->nearz)
			var->t[0] = (i1.y > 0 ? v2d(i1.x, i1.y) : v2d(i2.x, i2.y));
		if (var->t[1].y < var->nearz)
			var->t[1] = (i1.y > 0 ? v2d(i1.x, i1.y) : v2d(i2.x, i2.y));
	}
	return (1);
}

uint8_t	scale(t_env *env, t_game *var, t_item *now)
{
	var->size[0] = v2d(env->cam.fov.x / var->t[0].y, env->cam.fov.y / var->t[0].y);
	var->size[1] = v2d(env->cam.fov.x / var->t[1].y, env->cam.fov.y / var->t[1].y);
	var->side[0] = env->w / 2 - floor(var->t[0].x * var->size[0].x);
	var->side[1] = env->w / 2 - floor(var->t[1].x * var->size[1].x);
	if (var->side[0] >= var->side[1]|| var->side[1] < now->min || var->side[0] > now->max)
		return (0);
	else
	{
		var->render[now->sector]++;
		return (1);
	}
}
