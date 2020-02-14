#include "utils.h"
#include "texture.h"
#include "libft.h"

#define WALL_RATIO 20

static t_scaler	scaler_init(int ya, int cya, int yb, int max_t)
{
	t_scaler	ret;

	ret.result = 0 + (cya - 1 - ya) * (max_t - 0) / (yb - ya);
	ret.bop = ((max_t < 0) ^ (yb < ya)) ? -1 : 1;
	ret.fd = abs(max_t - 0);
	ret.ca = abs(yb - ya);
	ret.cache = (int)((cya - 1 - ya) * abs(max_t - 0)) % abs(yb - ya);
	return (ret);
}

static int		scaler_next(t_scaler *i)
{
	i->cache += i->fd;
	while (i->cache >= i->ca)
	{
		i->result += i->bop;
		i->cache -= i->ca;
	}
	return (i->result);
}

static int		x_scale(t_game *var, int x)
{
	float	u0;
	float	u1;
	float	tz1;
	float	tz2;
	float	w_size;

	tz1 = var->t[0].y;
	tz2 = var->t[1].y;
	w_size = hypot(var->v[0].x - var->v[1].x, var->v[0].y - var->v[1].y);
	if (fabs(var->t[1].x - var->t[0].x) > fabs(tz2 - tz1))
		init_and_protect_variable_1(var, w_size, &u0, &u1);
	else
		init_and_protect_variable_2(var, w_size, &u0, &u1);
	return ((u0 * ((var->side[1] - x) * tz2) + u1 * ((x - var->side[0]) * tz1))
			/ ((var->side[1] - x) * tz2 + (x - var->side[0]) * tz1));
}

void			draw_texture_slice
				(t_env *env, int x, t_height h, t_game *var, uint32_t *wall)
{
	t_scaler	scaler;
	int			scale_x;
	t_pos		p;
	uint32_t	color;

	h.top = bound(h.top, 0, env->h - 1);
	h.bottom = bound(h.bottom, 0, env->h - 1);
	p.x = x;
	p.y = h.top;
	scaler = scaler_init(var->unbound[0], h.top,
			var->unbound[1], WALL_RATIO * var->text_height);
	scale_x = x_scale(var, x);
	if (h.bottom > h.top)
	{
		draw_pixel(env, env->sdl.screen, p, 0);
		while (++p.y < h.bottom)
		{
			color = color_add(
				wall[abs((scaler_next(&scaler) % W_SIZE * W_SIZE)
					+ (scale_x % W_SIZE))], -var->depth);
			if (env->sector[env->cam.sector].light != -1)
				color = color_light(color, env->sector[env->cam.sector].light);
			draw_pixel(env, env->sdl.screen, p, color);
		}
		draw_pixel(env, env->sdl.screen, p, 0);
	}
}
