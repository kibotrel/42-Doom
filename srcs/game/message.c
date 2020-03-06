/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:16:17 by reda-con          #+#    #+#             */
/*   Updated: 2020/03/06 01:06:07 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "env.h"
#include "libft.h"
#include "utils.h"

void	poor(t_env *env, uint32_t data)
{
	char	*tmp;

	tmp = ft_itoa(data);
	info(env, ft_strdup("Not enough money"), v2d(RATIO_GRID_X / 2,
		RATIO_GRID_Y / 4), 1);
	info(env, ft_strdup("You need"), v2d(RATIO_GRID_X / 2,
		RATIO_GRID_Y / 4 + 2), 1);
	info(env, ft_strdup(tmp), v2d(RATIO_GRID_X / 2,
		RATIO_GRID_Y / 4 + 4), 1);
	free(tmp);
}
