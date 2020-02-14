/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:01:04 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/14 08:01:05 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static uint32_t	weapon_frame(uint32_t frame)
{
	if (frame < 100)
		return (1);
	else if (frame < 175)
		return (2);
	else if (frame < 250)
		return (3);
	else if (frame < 300)
		return (4);
	else if (frame < 600)
		return (5);
	else if (frame < 800)
		return (6);
	else if (frame < 1000)
		return (5);
	else
		return (0);
}

static uint32_t	weapon_state(t_env *env)
{
	uint32_t	pos;

	env->tick.shot.new = SDL_GetTicks();
	pos = weapon_frame(env->tick.shot.new - env->tick.shot.old);
	if (!pos)
		env->data.shot = 0;
	return (pos);
}

void			weapon(t_env *env)
{
	t_pos		shift;
	t_pos		vertex[2];
	uint32_t	pos;

	pos = (env->data.shot ? weapon_state(env) : 0);
	shift = (t_pos){env->w / 2 + env->data.grid.min.x * 3, env->h};
	draw_asset(env, env->sdl.bmp[SHOT_0 + pos], shift);
	vertex[0] = p2d(0, 24, env->data.grid.min.x, env->data.grid.min.y);
	vertex[1] = p2d(21, 28, env->data.grid.min.x, env->data.grid.min.y);
	blur_area(env, vertex[0], vertex[1]);
	shift = (t_pos){env->data.grid.min.x, env->data.grid.min.y * 27};
	draw_asset(env, env->sdl.bmp[MAGAZINE], shift);
	shift = (t_pos){shift.x * 12, shift.y};
	draw_asset(env, env->sdl.bmp[SHELL], shift);
	info(env, ft_itoa(env->data.magazines), v2d(9, 25.5), 1);
	info(env, txt(ft_itoa(env->data.ammos), " / 5", 0), v2d(18, 25.5), 1);
}
