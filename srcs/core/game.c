/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 17:30:55 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "SDL.h"
#include "libft.h"
#include "env.h"
#include "doom.h"

void	project(t_env *env, t_point p1, t_point p2, double angle)
{
	t_pos	t1;
	t_pos	t2;
	t_point	w1;
	t_point	w2;

	t1.x = p1.x - env->player.position.x;
	t2.x = p2.x - env->player.position.x;
	t1.y = p1.y - env->player.position.y;
	t2.y = p2.y - env->player.position.y;
	t1.z = t1.x * cos(ft_radians(angle)) + t1.y * sin(ft_radians(angle));
	t2.z = t2.x * cos(ft_radians(angle)) + t2.y * sin(ft_radians(angle));
	t1.x = t1.x * sin(ft_radians(angle)) - t1.y * cos(ft_radians(angle));
	t2.x = t2.x * sin(ft_radians(angle)) - t2.y * cos(ft_radians(angle));
	w1.x = env->pos.x - t1.x;
	w1.y = env->pos.y - t1.z;
	w2.x = env->pos.x - t2.x;
	w2.y = env->pos.y - t2.z;
	draw_line(env, w1, w2, WHITE);
}

void	draw_direction(t_env *env)
{
	t_point	p1;
	t_point p2;

	p1.x = env->pos.x;
	p1.y = env->pos.y;
	p2 = p1;
	p2.y -= 10;
	draw_line(env, p1, p2, WHITE);
}
void	game(t_env *env)
{
	int		i = -1;
	int		j = 0;
	t_point	p;

	SDL_SetWindowTitle(env->sdl.win, TITLE_GAME);
	while (++i < 4)
		draw_line(env, env->vertex[i], env->vertex[(i + 1) % 4], WHITE);
	while (j < 8)
	{
		project(env, env->wall[j], env->wall[j + 1], env->player.angle);
		j += 2;
	}
	p.y = env->pos.y - 2;
	while (++p.y < env->pos.y + 2)
	{
		p.x = env->pos.x - 2;
		while (++p.x < env->pos.x + 2)
			draw_pixel(env, env->sdl.screen, p, RED);
	}
	draw_direction(env);
}
