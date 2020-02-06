/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:32:06 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/06 21:41:08 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "game.h"
#include "clean.h"
#include "utils.h"

void	weapon(t_env *env, int offset)
{
	t_bmp		weapon;
	t_pos		p;
	t_pos		px;
	uint32_t	pos;

	if (env->data.shot)
	{
		if (bmp_to_array("assets/shotgun2.bmp", &weapon))
			clean(env, E_BMP_PARSE);
		env->tick.shot.new = SDL_GetTicks();
		if (env->tick.shot.new - env->tick.shot.old > 320)
			env->data.shot = 0;
	}
	else
	{
		if (bmp_to_array("assets/shot0_720.bmp", &weapon))
			clean(env, E_BMP_PARSE);
	}
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
