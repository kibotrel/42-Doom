/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:15:36 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 08:53:07 by kibotrel         ###   ########.fr       */
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

static char	*precision(double value, int precision)
{
	char	*str;
	char	*tmp;
	unsigned int	i;
	unsigned int	max;
	unsigned int	int_part;

	if (value == floor(value))
		return (ft_itoa((int)value));
	tmp = ft_dtoa(value);
	int_part = ft_numlen((floor(value)), 10);
	if (!(str = malloc(sizeof(char) * int_part + precision + 2)))
		return (NULL);
	i = 0;
	max = int_part + precision + 1;
	while (i < max)
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
	free(tmp);
	return (str);


}

static void	informations(t_env *env)
{
	char	*fly;
	char	*pos;
	char	*angle;

	fly = (env->cam.fly > 0 ? ft_strdup("ON") : ft_strdup("OFF"));
	angle = ft_itoa((int)fabs(ft_degrees(env->cam.angle)) % 360);
	pos = load_text(precision(env->cam.pos.x, 2), " / ", 0);
	pos = load_text(pos, precision(env->cam.pos.z, 2), 2);
	pos = load_text(pos, " / ", 0);
	pos = load_text(pos, precision(env->cam.pos.y, 2), 2);
	display_info(env, ft_strdup("- Debug Mode -"), v2d(4.5, 1), 1);
	display_info(env, load_text("FPS: ", ft_itoa(env->data.fps), 1), v2d(1, 3), 0);
	display_info(env, load_text("Sector: ", ft_itoa(env->cam.sector), 1),
					v2d(6, 3), 0);
	display_info(env, load_text("Fly: ", fly, 1), v2d(1, 4), 0);
	display_info(env, load_text("Angle: ", angle, 1), v2d(6, 4), 0);
	display_info(env, load_text("X / Y / Z : ", pos, 1), v2d(4.5, 5), 1);
}

void		debug_hud(t_env *env)
{
	background(env);
	informations(env);
}
