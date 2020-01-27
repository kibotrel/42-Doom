/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:15:36 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/27 15:35:38 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "utils.h"

static void	background(t_env *env)
{
	t_pos	p;

	p.y = -1;
	while (++p.y < env->data.grid.min.y * 7)
	{
		p.x = -1;
		while (++p.x < env->data.grid.min.x * 11)
			blur(env, env->sdl.screen, p);
	}
}

static void	informations(t_env *env)
{
	char	*fly;
	char	*angle;
	char	*height;

	fly = (env->cam.fly > 0 ? ft_strdup("ON") : ft_strdup("OFF"));
	angle = ft_itoa((int)fabs(ft_degrees(env->cam.angle)) % 360);
	height = ft_itoa((int)env->cam.pos.z);
	display_info(env, ft_strdup("- Debug Mode -"), v2d(4.5, 1), 1);
	display_info(env, load_text("FPS: ", ft_itoa(env->data.fps)), v2d(1, 3), 0);
	display_info(env, load_text("Sector: ", ft_itoa(env->cam.sector)),
					v2d(6, 3), 0);
	display_info(env, load_text("Fly: ", fly), v2d(1, 4), 0);
	display_info(env, load_text("Angle: ", angle), v2d(6, 4), 0);
	display_info(env, load_text("Altitude: ", height), v2d(4.5, 5), 1);
}

void	debug_hud(t_env *env)
{
	background(env);
	informations(env);
}
