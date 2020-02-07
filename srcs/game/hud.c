/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:32:06 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/07 09:59:36 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "game.h"
#include "clean.h"
#include "utils.h"

uint32_t	weapon_frame(uint32_t frame)
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

void	weapon(t_env *env, int offset)
{
	t_pos		p;
	t_pos		px;
	t_bmp		weapon;
	uint32_t	pos;

	pos = 0;
	if (env->data.shot)
	{
		env->tick.shot.new = SDL_GetTicks();
		pos = weapon_frame(env->tick.shot.new - env->tick.shot.old);
		if (!pos)
			env->data.shot = 0;
	}
	weapon = env->sdl.bmp[SHOT_0 + pos];
	p.y = -1;
	while (++p.y < weapon.height)
	{
		p.x = -1;
		px.y = env-> h - weapon.height + p.y;
		while (++p.x < weapon.width)
		{
			px.x = (env->w / 2) + p.x + offset;
			pos = p.x + p.y * weapon.width;
			if (weapon.pixels[pos] != 41704)
				draw_pixel(env, env->sdl.screen, px, weapon.pixels[pos]);
		}
	}
}

void	hud(t_env *env)
{
	// t_pos	n;
	// t_pos	end;
	// t_pos	start;
	//
	// n.y = 0;
	// while (++n.y <= RATIO_GRID_Y)
	// {
	// 	n.x = 0;
	// 	while (++n.x <= RATIO_GRID_X + 1)
	// 	{
	// 		start.x = n.x * env->data.grid.min.x;
	// 		start.y = n.y * env->data.grid.min.y;
	// 		if (n.y == RATIO_GRID_Y)
	// 			end.y = start.y;
	// 		else
	// 			end.y = (n.y + 1) * env->data.grid.min.y;
	// 		end.x = start.x;
	// 		draw_line(env, start, end, WHITE);
	// 		if (n.x == RATIO_GRID_X + 1)
	// 			end.x = start.x;
	// 		else
	// 			end.x = (n.x + 1) * env->data.grid.min.x;
	// 		end.y = start.y;
	// 		draw_line(env, start, end, WHITE);
	// 	}
	// }
	if (env->data.hud.debug > 0)
		debug_hud(env);
	crosshair(env);
	lifebar(env);
	weapon(env, env->data.grid.min.x * 3);
}
