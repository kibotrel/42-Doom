/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:15:36 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/01 04:38:28 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "utils.h"

static void	background(t_env *env)
{
	t_pos	p;

	p.y = -1;
	while (++p.y < env->data.grid.min.y * 20)
	{
		p.x = -1;
		while (++p.x < env->data.grid.min.x * 20)
			blur(env, env->sdl.screen, p);
	}

}

// static char	*precision(double value, int precision)
// {
// 	char	*str;
// 	char	*tmp;
// 	unsigned int	i;
// 	unsigned int	max;
// 	unsigned int	int_part;
//
// 	if (value == floor(value))
// 		return (ft_itoa((int)value));
// 	tmp = ft_dtoa(value);
// 	int_part = ft_numlen((floor(value)), 10);
// 	if (!(str = malloc(sizeof(char) * int_part + precision + 2)))
// 		return (NULL);
// 	i = 0;
// 	max = int_part + precision + 1;
// 	while (i < max)
// 	{
// 		str[i] = tmp[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	free(tmp);
// 	return (str);
// }

static void	cam_infos(t_env *env, t_cam *cam)
{
	char	*str[6];
	t_vec3d	v;
	// char	*pos;

	// pos = load_text(precision(env->cam.pos.x, 2), " / ", 0);
	// pos = load_text(pos, precision(env->cam.pos.z, 2), 2);
	// pos = load_text(pos, " / ", 0);
	// pos = load_text(pos, precision(env->cam.pos.y, 2), 2);
	v = cam->v;
	str[0] = (cam->v.z ? ft_strdup("True") : ft_strdup("False"));
	str[1] = (cam->fly > 0 ? ft_strdup("On") : ft_strdup("Off"));
	str[2] = (cam->ground ? ft_strdup("True") : ft_strdup("False"));
	str[3] = (cam->sneak ? ft_strdup("True") : ft_strdup("False"));
	str[4] = (v.x || v.y || v.z ? ft_strdup("True") : ft_strdup("False"));
	str[5] = ft_itoa((inter(round((1 / (cam->fov.x / env->h)) * 56)), 30, 245);
	// str[2] = ft_itoa((int)round((1 / (cam->fov.x / env->h)) * 50));
	// str[3] = ft_itoa((int)fabs(ft_degrees(env->cam.angle)) % 360);

	info(env, ft_strdup("  Debug Mode  "), v2d(5.5, 1), 1);
	info(env, txt("Fall : ", str[0], 1), v2d(1, 3), 0);
	info(env, txt("Fly : ", str[1], 1), v2d(1, 4), 0);
	info(env, txt("Ground : ", str[2], 1), v2d(1, 5), 0);
	info(env, txt("Sneak : ", str[3], 1), v2d(1, 6), 0);
	info(env, txt("Move : ", str[4], 1), v2d(1, 7), 0);
	info(env, txt("FOV : ", str[5], 1), v2d(1, 8), 0);
	// info(env, txt("FPS : ", ft_itoa(env->data.fps), 1), v2d(1, 3), 0);
	info(env, txt("Sector : ", ft_itoa(cam->sector), 1), v2d(12, 3), 0);
	//info(env, txt("Angle : ", str[1], 1), v2d(6, 4), 0);
	// display_info(env, load_text("X / Y / Z : ", pos, 1), v2d(4.5, 5), 1);
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
	// sector_infos(env);
}
