/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/16 05:58:40 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "core.h"
#include "libft.h"
#include "utils.h"

static void		point(t_point *p, double x, double y)
{
	p->x = round(x);
	p->y = round(y);
}

void	project(t_env *env, t_point p1, t_point p2, double angle)
{
	t_pos	t1;
	t_pos	t2;
	t_point	w1;
	t_point	w2;
	double	x1;
	double	x2;
	double	y1a;
	double	y1b;
	double	y2a;
	double	y2b;

	t1.x = p1.x - env->player.pos.x; t1.y = p1.y - env->player.pos.y;
	t2.x = p2.x - env->player.pos.x; t2.y = p2.y - env->player.pos.y;
	t1.z = t1.x * cos(ft_radians(angle)) + t1.y * sin(ft_radians(angle));
	t2.z = t2.x * cos(ft_radians(angle)) + t2.y * sin(ft_radians(angle));
	t1.x = t1.x * sin(ft_radians(angle)) - t1.y * cos(ft_radians(angle));
	t2.x = t2.x * sin(ft_radians(angle)) - t2.y * cos(ft_radians(angle));
	w1.x = env->cam.pos.x - t1.x; w1.y = env->cam.pos.y - t1.z;
	w2.x = env->cam.pos.x - t2.x; w2.y = env->cam.pos.y - t2.z;
	x1 = -t1.x * 16 / t1.z; y1a = -env->cam.pos.x / t1.z; y1b = env->cam.pos.x / t1.z;
	x2 = -t2.x * 16 / t2.z; y2a = -env->cam.pos.x / t2.z; y2b = env->cam.pos.x / t2.z;
	point(&w1, env->cam.pos.x + x1, env->cam.pos.y + y1a);
	point(&w2, env->cam.pos.x + x2, env->cam.pos.y + y2a);
	draw_line(env, w1, w2, WHITE);
	point(&w2, env->cam.pos.x + x1, env->cam.pos.y + y1b);
	draw_line(env, w1, w2, WHITE);
	point(&w1, env->cam.pos.x + x2, env->cam.pos.y + y2a);
	point(&w2, env->cam.pos.x + x2, env->cam.pos.y + y2b);
	draw_line(env, w1, w2, WHITE);
	point(&w1, env->cam.pos.x + x1, env->cam.pos.y + y1b);
	draw_line(env, w1, w2, WHITE);
}

// void	draw_direction(t_env *env)
// {
// 	t_point	p1;
// 	t_point p2;
//
// 	p1.x = env->cam.pos.x;
// 	p1.y = env->cam.pos.y;
// 	p2 = p1;
// 	p2.y -= 10;
// 	draw_line(env, p1, p2, WHITE);
// }

void	game(t_env *env)
{
	int		i = -1;
	int		j = 0;
	// t_point	p;

	SDL_SetWindowTitle(env->sdl.win, TITLE_GAME);
	while (++i < 4)
		draw_line(env, env->vertex[i], env->vertex[(i + 1) % 4], WHITE);
	while (j < 2)
	{
		project(env, env->wall[j], env->wall[j + 1], env->cam.angle);
		j += 2;
	}
	// p.y = env->cam.pos.y - 2;
	// while (++p.y < env->cam.pos.y + 2)
	// {
	// 	p.x = env->cam.pos.x - 2;
	// 	while (++p.x < env->cam.pos.x + 2)
	// 		draw_pixel(env, env->sdl.screen, p, RED);
	// }
	// draw_direction(env);
}
