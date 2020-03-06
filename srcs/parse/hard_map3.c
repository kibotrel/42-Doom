/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:34:11 by reda-con          #+#    #+#             */
/*   Updated: 2020/03/06 10:26:24 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	hard_map_last(t_env *env)
{
	env->sector[0].texture = 0;
	env->sector[0].type = EFF_NONE;
	env->sector[0].data = 0;
	env->sector[0].light = -1;
	env->sector[0].floor = -3;
	env->sector[3].type = LAVA;
	env->sector[4].neighbor[4] = -1;
	env->sector[0].gravity = 0.1;
	env->sector[4].neighbor[5] = -1;
	env->sector[5].neighbor[1] = -1;
	env->tuto = 1;
	env->sector[0].vertex[6] = v2d(32.5, 37.5);
}
