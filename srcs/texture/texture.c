#include "utils.h"
#include "texture.h"

t_scaler	scaler_init(int ya, int cya, int yb, int min_t, int max_t)
{
	return ((t_scaler) { 
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

/*
float vx1 = sect->vertex[s+0].x - player.where.x, vy1 = sect->vertex[s+0].y - player.where.y;
float vx2 = sect->vertex[s+1].x - player.where.x, vy2 = sect->vertex[s+1].y - player.where.y;
*//* Rotate them around the player's view *//*
float pcos = player.anglecos, psin = player.anglesin;
float tx1 = vx1 * psin - vy1 * pcos,  tz1 = vx1 * pcos + vy1 * psin;
float tx2 = vx2 * psin - vy2 * pcos,  tz2 = vx2 * pcos + vy2 * psin;
​
int txtx = (u0*((x2-x)*tz2) + u1*((x-x1)*tz1)) / ((x2-x)*tz2 + (x-x1)*tz1);
*/

int		x_scale(t_env *env, t_game *var, int x)
{
	float	vx1;
	float	vx2;
	float	vy1;
	float	vy2;
	float	tz1;
	float	tz2;

	vx1 = var->t[0].x - env->cam.pos.x;
	vx2 = var->t[1].x - env->cam.pos.x;
	vy1 = var->t[0].y - env->cam.pos.y;
	vy2 = var->t[1].y - env->cam.pos.y;
	tz1 = vx1 * env->cam.cos + vy1 * env->cam.sin;
	tz2 = vx2 * env->cam.cos + vy2 * env->cam.sin;
	return (0 * ((var->side[1] - x) * tz2) + 64 * ((x - var->side[0]) * tz1)
			/ ((var->side[1] - x) * tz2 + (x - var->side[0]) * tz1));
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
	scaler = scaler_init(var->unbound[0], h.top, var->unbound[1], 0, 10*fabs(var->ceil[0] - var->floor[0]));
	scale_x = x_scale(env, var, x);
	if (h.bottom > h.top)
	{
		draw_pixel(env, env->sdl.screen, p, 0);
		while (++p.y < h.bottom)
		{
			draw_pixel(env, env->sdl.screen, p, wall[(scaler_next(&scaler) % 64) * 64 + (scale_x % 64)]);
		}
		draw_pixel(env, env->sdl.screen, p, 0);
	}
}
