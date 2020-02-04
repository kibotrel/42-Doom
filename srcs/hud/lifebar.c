#include <math.h>
#include "utils.h"
#include "texture.h"

static void	draw_polygon(t_env *env, t_pos p[4], int thickness)
{
	int		i[2];
	t_pos	tmp;

	i[0] = -1;
	tmp = p[1];
	p[2].x = p[1].x - (p[3].y - p[0].y);
	while (++tmp.y != p[2].y && --tmp.x != p[2].x)
		draw_pixel(env, env->sdl.screen, tmp, 0);
	while (++i[0] < thickness)
	{
		i[1] = -1;
		while (++i[1] < 4)
			if (i[1] != 1)
				draw_line(env, p[i[1]], p[(i[1] + 1) % 4], 0);
		p_update(&p[0], -1, -1);
		p_update(&p[1], 1, -1);
		p_update(&p[2], -1, 1);
		p_update(&p[3], -1, 1);
	}
}

static void	fill_bar(t_env *env, int border)
{
	int		i;
	t_pos	p;

	i = 0;
	p.y = env->data.grid.min.y * 29;
	while (++p.y < env->data.grid.min.y * 31)
	{
		p.x = env->data.grid.min.x;
		while (++p.x < border - 1)
			draw_pixel(env, env->sdl.screen, p, color_add(RED, -i * 6));
		border--;
		i++;
	}
}

void		lifebar(t_env *env)
{
	t_pos	p[4];
	double	border;

	p[0] = p2d(1, 29, env->data.grid.min.x, env->data.grid.min.y);
	p[1] = p2d(21, 29, env->data.grid.min.x, env->data.grid.min.y);
	p[2] = p2d(19, 31, env->data.grid.min.x, env->data.grid.min.y);
	p[3] = p2d(1, 31, env->data.grid.min.x, env->data.grid.min.y);
	draw_polygon(env, p, 3);
	border = 21 * env->data.life / 100;
	fill_bar(env, border * env->data.grid.min.x);
}
