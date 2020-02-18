/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:15:36 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/18 10:56:29 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "setup.h"
#include "utils.h"

static void	background(t_env *env)
{
	t_pos			min;
	t_pos			vertex[2];

	min = env->data.grid.min;
	vertex[0] = p2d(0, 0, min.x, min.y);
	vertex[1] = p2d(21, 12, min.x, min.y);
	blur_area(env, vertex[0], vertex[1]);
	draw_line(env, p2d(4, 1, min.x, min.y), p2d(10, 1, min.x, min.y), WHITE);
	draw_line(env, p2d(4, 2, min.x, min.y), p2d(10, 2, min.x, min.y), WHITE);
	draw_line(env, p2d(4, 1, min.x, min.y), p2d(4, 2, min.x, min.y), WHITE);
	draw_line(env, p2d(10, 1, min.x, min.y), p2d(10, 2, min.x, min.y), WHITE);
	draw_line(env, p2d(7, 3, min.x, min.y), p2d(7, 8, min.x, min.y), WHITE);
	draw_line(env, p2d(14, 3, min.x, min.y), p2d(14, 11, min.x, min.y), WHITE);
	draw_line(env, p2d(15, 1, min.x, min.y), p2d(20, 1, min.x, min.y), WHITE);
	draw_line(env, p2d(15, 2, min.x, min.y), p2d(20, 2, min.x, min.y), WHITE);
	draw_line(env, p2d(15, 1, min.x, min.y), p2d(15, 2, min.x, min.y), WHITE);
	draw_line(env, p2d(20, 1, min.x, min.y), p2d(20, 2, min.x, min.y), WHITE);
}

static void	cam_infos(t_env *env, t_cam *cam)
{
	char			**str;

	if (!(str = (char**)malloc(sizeof(char*) * 12)))
		return ;
	setup_debug_cam(env, cam, str);
	info(env, ft_strdup("  Camera infos  "), v2d(6.5, 1), 1);
	info(env, txt("Fall : ", str[0], 1), v2d(1, 3), 0);
	info(env, txt("Ground : ", str[2], 1), v2d(8, 3), 0);
	info(env, txt("Sneak : ", str[3], 1), v2d(1, 4), 0);
	info(env, txt("Move : ", str[4], 1), v2d(8, 4), 0);
	info(env, txt("Fly : ", str[1], 1), v2d(1, 5), 0);
	info(env, txt("Sprint : ", str[11], 1), v2d(8, 5), 0);
	info(env, txt("FOV : ", str[5], 1), v2d(1, 6), 0);
	info(env, txt("Angle : ", str[6], 1), v2d(8, 6), 0);
	info(env, txt("Sector : ", str[10], 1), v2d(1, 7), 0);
	info(env, txt("FPS : ", str[9], 1), v2d(8, 7), 0);
	info(env, txt("Position (XYZ) : ", str[7], 1), v2d(6.5, 9), 1);
	info(env, txt("Velocity (XYZ) : ", str[8], 1), v2d(6.5, 10), 1);
	free(str);
}

static void	sector_infos(t_env *env, t_sector *sector)
{
	char			**str;

	if (!(str = (char**)malloc(sizeof(char*) * 5)))
		return ;
	setup_debug_sector(sector, str);
	info(env, ft_strdup("  Sector infos  "), v2d(17, 1), 1);
	info(env, txt("Walls : ", str[0], 1), v2d(15, 3), 0);
	info(env, txt("Ceil : ", str[1], 1), v2d(15, 5), 0);
	info(env, txt("Floor : ", str[2], 1), v2d(15, 6), 0);
	info(env, txt("Gravity : ", str[3], 1), v2d(15, 7), 0);
	info(env, txt("Friction : ", str[4], 1), v2d(15, 8), 0);
	info(env, ft_strdup("Effector : WIP"), v2d(15, 10), 0);
	free(str);
}

void		debug_hud(t_env *env)
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
	background(env);
	cam_infos(env, &env->cam);
	sector_infos(env, &env->sector[env->cam.sector]);
}
