/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_click_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:23:09 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/06 10:34:15 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	check_great_click
	(t_env *env, t_vec2d start, int size, int size_click)
{
	return (env->sdl.event.motion.x <= (start.x + size) * env->data.grid.min.x +
			env->data.grid.min.x * size_click && env->sdl.event.motion.x >=
			(start.x + size) * env->data.grid.min.x && env->sdl.event.motion.y
			>= start.y * env->data.grid.min.y && env->sdl.event.motion.y <=
			start.y * env->data.grid.min.y + env->data.grid.min.y);
}

void	click_on_off(t_env *env, t_vec2d start, int size, bool *on_off)
{
	if (check_great_click(env, start, size, 1))
		*on_off = true;
	else if (check_great_click(env, start, size + 2, 1))
		*on_off = false;
}

void	click_arrow
	(t_env *env, t_vec3d start, int8_t *index, int8_t index_max)
{
	if (check_great_click(env, v2d(start.x, start.y), 0, 1))
	{
		*index -= 1;
		if (*index < 0)
			*index = index_max - 1;
	}
	else if (check_great_click(env, v2d(start.x, start.y), start.z + 1, 1))
	{
		*index += 1;
		if (*index >= index_max)
			*index = 0;
	}
}
