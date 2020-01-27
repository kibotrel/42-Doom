#include "utils.h"
#include "texture.h"
#include "libft.h"

#define WALL_SIZE 64
#define WALL_UNIT 4096

t_scaler	scaler_init(int ya, int cya, int yb, int min_t, int max_t)
{
	return ((t_scaler){ 
			min_t + (cya-1 - ya) * (max_t-min_t) / (yb-ya),
			((max_t<min_t) ^ (yb<ya)) ? -1 : 1,
			abs(max_t-min_t), abs(yb-ya),
			(int)((cya-1-ya) * abs(max_t-min_t)) % abs(yb-ya)
			});
}

static int scaler_next(t_scaler *i)
{
	for(i->cache += i->fd; i->cache >= i->ca; i->cache -= i->ca) i->result += i->bop;
	return i->result;
}

int		x_scale(t_game *var, int x, int *scale_x)
{
	float	u0;
	float	u1;

	float tz1 = var->t[0].y;
	float tz2 = var->t[1].y;
	float wall_size = hypot(var->v[0].x - var->v[1].x, var->v[0].y - var->v[1].y);
	if (fabs(var->t[1].x - var->t[0].x) > fabs(tz2 - tz1))
	{

		u0 = (var->t[0].x-var->org[0].x) * (WALL_UNIT * wall_size / WALL_SIZE)/ (var->org[1].x-var->org[0].x);
		u1 = (var->t[1].x-var->org[0].x) * (WALL_UNIT * wall_size / WALL_SIZE)/ (var->org[1].x-var->org[0].x);
	}
	else
	{
		u0 = (tz1-var->org[0].y) * (WALL_UNIT * wall_size / WALL_SIZE)/ (var->org[1].y-var->org[0].y);
		u1 = (tz2-var->org[0].y) * (WALL_UNIT * wall_size / WALL_SIZE)/ (var->org[1].y-var->org[0].y);
	}
	*scale_x =(int)((u0 * ((var->side[1] - x) * tz2) + u1 * ((x - var->side[0]) * tz1))
			/ ((var->side[1] - x) * tz2 + (x - var->side[0]) * tz1));
	return (0);
}

void    draw_texture_slice(t_env *env, int x, t_height h, t_game *var, uint32_t *wall)
{
	t_scaler		scaler;
	int			scale_x;
	t_pos       p;

	h.top = bound(h.top, 0, env->h - 1);
	h.bottom = bound(h.bottom, 0, env->h - 1);
	p.x = x;
	p.y = h.top;
	scaler = scaler_init(var->unbound[0], h.top, var->unbound[1], 0, 20 * fabs(var->ceil[0] - var->floor[0]));
	x_scale(var, x, &scale_x);
	if (h.bottom > h.top)
	{
		draw_pixel(env, env->sdl.screen, p, 0);
		while (++p.y < h.bottom)
		{
			draw_pixel(env, env->sdl.screen, p, color_add(
						wall[(scaler_next(&scaler) % WALL_SIZE) * WALL_SIZE + (scale_x % WALL_SIZE)], -var->depth));
		}
		draw_pixel(env, env->sdl.screen, p, 0);
	}
}

void    draw_ceil_and_floor_slice(t_env *env, t_game *var, int x)
{
	t_pos       p;
	t_height	h;

	h.top = var->y[1] + 1;
	h.bottom = var->bottom[x];
	p.x = x;
	p.y = h.top;
	if (h.bottom == h.top)
		draw_pixel(env, env->sdl.screen, p, color_scale(0x0000AA, color_add(0xFFFFFF, -var->depth), p.y - h.bottom, h.top - h.bottom));
	else if (h.bottom > h.top)
	{
		draw_pixel(env, env->sdl.screen, p, 0);
		while (++p.y < h.bottom)
			draw_pixel(env, env->sdl.screen, p, color_scale(0x0000AA, color_add(0xFFFFFF, -var->depth), p.y - h.top, h.bottom - h.top));
		draw_pixel(env, env->sdl.screen, p, 0);
	}
}
