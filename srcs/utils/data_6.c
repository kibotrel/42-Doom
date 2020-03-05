/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 22:04:18 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/05 22:04:46 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"

void	peak_point(t_env *env, int floor, double height)
{
	if (env->cam.pos.z - height - floor > env->data.fall_height)
		env->data.fall_height = env->cam.pos.z - height - floor;
}

double	difficulty_scale(t_env *env, double damage)
{
	if (env->setting.mode == HARD)
		return (damage * 2);
	if (env->setting.mode == EASY)
		return (damage / 2);
	return (damage);
}
