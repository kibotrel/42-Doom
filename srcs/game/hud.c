/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:32:06 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/10 02:05:31 by vivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "utils.h"

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
	if (env->state == PLAY)
	{
		crosshair(env);
		lifebar(env);
		weapon(env);
	}
}
