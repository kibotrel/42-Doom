#include "utils.h"

void	draw_plane(t_env *env, int x, t_height h, t_game *var)
{
	t_vec2d	p[2];
	t_vec2d	pos;

	p[0] = var->s->vertex[var->j];
	p[1] = var->s->vertex[(var->j + 1) % var->s->points];
	pos = (t_vec2d){env->cam.pos.x, env->cam.pos.y};
	h.top = bound(h.top, 0, env->h - 1);
	h.bottom = bound(h.bottom, 0, env->h - 1);

	//HIT COORDINATES
	var->cast.hit.x = p[0].x + (x / (fabs(var->side[0]) + fabs(var->side[1]))) * (p[1].x - p[0].x);
	var->cast.hit.y = p[0].y + (x / (fabs(var->side[0]) + fabs(var->side[1]))) * (p[1].y - p[0].y);

	//FIND THE SHORTEST DISTANCE BEWTWEEN CAMERA PLANE AND THIS POINT
	var->cast.dot[0] = (var->cast.hit.x - pos.x) * (var->cast.normal.x - pos.x) + (var->cast.hit.y - pos.y) * (var->cast.normal.y - pos.y);
	var->cast.r = var->cast.dot[0] / pow(var->cast.size, 2);
	var->cast.proj.x = pos.x + var->cast.r * (var->cast.normal.x - pos.x);
	var->cast.proj.y = pos.y + var->cast.r * (var->cast.normal.y - pos.y);
	var->cast.dot[1] = (pos.y - var->cast.hit.y) * (var->cast.normal.x - pos.x) - (pos.x - var->cast.hit.x) * (var->cast.normal.y - pos.y);
	var->cast.s = var->cast.dot[1] /  pow(var->cast.size, 2);
	var->cast.hypotenuse = pow(pos.x - var->cast.hit.x, 2) + pow(pos.y - var->cast.hit.y, 2);
	var->cast.adjacent = fabs(var->cast.s) * var->cast.size;
	var->cast.opposite = fabs(var->cast.r) * var->cast.size;
	var->cast.distance = var->cast.hypotenuse / var->cast.adjacent;
	printf("Thread %d | x = %4.d |distance %3f\n", var->thread, x, var->cast.distance);
}
