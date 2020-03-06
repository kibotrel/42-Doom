/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:34:41 by reda-con          #+#    #+#             */
/*   Updated: 2020/03/06 10:06:38 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static void		third_step(t_env *env)
{
	if (env->cam.sector == 3)
		info(env, ft_strdup(TUTO_DMG), v2d(RATIO_GRID_X / 2,
			RATIO_GRID_Y / 4), 1);
	else if (env->test.jetpack)
	{
		if (!env->test.elevator)
			info(env, ft_strdup(TUTO_ELTR), v2d(RATIO_GRID_X / 2,
				RATIO_GRID_Y / 4), 1);
		if (env->sector[env->cam.sector].type == 5)
			env->test.elevator = 1;
	}
	else if (env->sector[env->cam.sector].type == 1)
	{
		info(env, ft_strdup(TUTO_MONEY), v2d(RATIO_GRID_X / 2,
			RATIO_GRID_Y / 4 - 4), 1);
		info(env, ft_strdup(TUTO_JETPACK), v2d(RATIO_GRID_X / 2,
			RATIO_GRID_Y / 4 - 2), 1);
	}
}

static void		sec_step(t_env *env)
{
	if (env->test.jump)
	{
		if (env->test.crouch)
			third_step(env);
		else
			info(env, ft_strdup(TUTO_CROUCH), v2d(RATIO_GRID_X / 2,
				RATIO_GRID_Y / 4), 1);
	}
	else
		info(env, ft_strdup(TUTO_JUMP), v2d(RATIO_GRID_X / 2,
			RATIO_GRID_Y / 4), 1);
}

void			tuto(t_env *env)
{
	if (env->test.all_move || (env->test.move[0] && env->test.move[1]
				&& env->test.move[2] && env->test.move[3]))
	{
		env->test.all_move = 1;
		if (env->test.door)
			sec_step(env);
		else
			info(env, ft_strdup(TUTO_DOOR), v2d(RATIO_GRID_X / 2,
				RATIO_GRID_Y / 4), 1);
	}
	else
		info(env, ft_strdup(TUTO_MOVE), v2d(RATIO_GRID_X / 2,
			RATIO_GRID_Y / 4), 1);
}
