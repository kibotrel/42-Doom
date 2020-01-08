#include "utils.h"

uint32_t	color_mul(uint32_t color, double mul);	//a mettre dans un .h
uint32_t	color_add(uint32_t color, double add);	//a mettre dans un .h

static void	draw_ceil_and_floor(t_env *env, t_game *var, int32_t x)
{
	int32_t		*p;
	int32_t		end;
	int32_t		start;
	t_vec2d		*t;

	end = var->side[1];
	p = var->now;
	t = var->t;
	start = var->side[0];
	var->depth = ((x - start) * (t[1].y - t[0].y) / (end - start) + t[0].y) * 8;
	var->unbound[0] = (x - start) * (p[2] - p[0]) / (end - start) + p[0];
	var->unbound[1] = (x - start) * (p[3] - p[1]) / (end - start) + p[1];
	var->y[0] = bound(var->unbound[0], var->top[x], var->bottom[x]);
	var->y[1] = bound(var->unbound[1], var->top[x], var->bottom[x]);
	draw_slice(env, x, var->top[x], var->y[0] - 1, 0, 0x222222, 0); // Ceil
	draw_slice(env, x, var->y[1] + 1, var->bottom[x], 0, 0x0000AA, 0); // Floor
}

static void	draw_transitions(t_env *env, t_game *var, int32_t x)
{
	uint32_t	r1 = 0x010101 * (255 - var->depth);
	uint32_t	r2 = 0x040007 * (31 - var->depth / 8);

	r1 = (255 - var->depth < 0 ? 0 : r1);
	r2 = (31 - var->depth / 8 < 0 ? 0 : r2);

	int32_t		*p;
	int32_t		end;
	int32_t		start;

	end = var->side[1];
	p = var->next;
	start = var->side[0];
	var->unbound[0] = (x - start) * (p[2] - p[0]) / (end - start) + p[0];
	var->unbound[1] = (x - start) * (p[3] - p[1]) / (end - start) + p[1];
	var->ny[0] = bound(var->unbound[0], var->top[x], var->bottom[x]);
	var->ny[1] = bound(var->unbound[1], var->top[x], var->bottom[x]);
	var->top[x] = bound(fmax(var->y[0], var->ny[0]), var->top[x], env->h - 1);
	var->bottom[x] = bound(fmin(var->y[1], var->ny[1]), 0, var->bottom[x]);
	draw_slice(env, x, var->y[0], var->ny[0] - 1, 0, x == start || x == end ? 0 : r1, 0); // Ceil transition
	draw_slice(env, x, var->ny[1] + 1, var->y[1], 0, x == start || x == end ? 0 : r2, 0); // Floor transition
}

static void	draw_wall(t_env *env, t_game *var, int32_t *y, int32_t x)
{
	uint32_t	r = color_add(0xFFFFFF, -var->depth);

	int32_t		end;
	int32_t		start;

	end = var->side[1];
	start = var->side[0];
	draw_slice(env, x, y[0], y[1], 0, x == start || x == end ? 0 : r, 0);
}

void		draw_screen(t_env *env, t_game *var)
{
	int32_t		x;

	x = var->start;
	while (x <= var->end)
	{
		draw_ceil_and_floor(env, var, x);
		if (var->n >= 0) // If the current wall leads to another sector we need to draw "walls" if either the neighboring floor is higher or ceil is lower
			draw_transitions(env, var, x);
		else
			draw_wall(env, var, var->y, x);
		x++;
	}
}
