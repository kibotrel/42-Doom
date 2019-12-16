#include <math.h>
#include "utils.h"

t_vec2d	intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	t_vec2d	p;

	p.x = vxs(vxs(x1, y1, x2, y2), x1 - x2, vxs(x3, y3, x4, y4), x3 - x4) / vxs(x1 - x2, y1 - y2, x3 - x4, y3 - y4);
	p.y = vxs(vxs(x1, y1, x2, y2), y1 - y2, vxs(x3, y3, x4, y4), y3 - y4) / vxs(x1 - x2, y1 - y2, x3 - x4, y3 - y4);
	return (p);
}
double	side(double px, double py, double x0, double y0, double x1, double y1)
{
	return (vxs(x1 - x0, y1 - y0, px - x0, py - y0));
}

int		hitbox(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3)
{
	return ((overlap(x0, x1, x2, x3) && overlap(y0, y1, y2, y3)));
}

void	vproj(t_vec3d *v, t_vec2d v1, t_vec2d v2)
{
	t_vec2d		w;	// Wall vector

	w = v2d(v2.x - v1.x, v2.y - v1.y);
	v->x = w.x * (v->x * w.x + w.y * v->y) / (pow(w.x, 2) + pow(w.y, 2));
	v->y = w.y * (v->x * w.x + w.y * v->y) / (pow(w.x, 2) + pow(w.y, 2));
}

void	velocity(t_env *env, t_cam *cam, t_vec2d v)
{
	int		move;
	double	speed;

	if (env->input[SDL_SCANCODE_W] || env->input[SDL_SCANCODE_S]
		|| env->input[SDL_SCANCODE_A] || env->input[SDL_SCANCODE_D])
		move = 1;
	speed = (move ? 0.4 : 0.2);
	cam->v.x = cam->v.x * (1 - speed) + v.x * speed;
	cam->v.y = cam->v.y * (1 - speed) + v.y * speed;
	if (move)
		env->cam.move = 1;
}
