/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_blank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:36:21 by reda-con          #+#    #+#             */
/*   Updated: 2020/03/05 16:00:01 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include "utils.h"

int		verif_player(t_cam *cam, char **tab)
{
	if (cam->pos.x != -1 && cam->pos.y != -1)
		return (3);
	if (tab[1] && tab[3] && tab[5] && tab[7] && !ft_strcmp(tab[1], "x")
			&& !ft_strcmp(tab[3], "y") && !ft_strcmp(tab[5], "sector")
			&& !ft_strcmp(tab[7], "angle"))
	{
		if (tab[2] && tab[4] && tab[6] && tab[8] && ft_isnum(tab[2])
				&& ft_isnum(tab[4]) && ft_isnum(tab[6]) && ft_isnum(tab[8]))
		{
			if (tab[9])
				return (3);
			cam->pos = v3d(ft_atoi(tab[2]), ft_atoi(tab[4]), 0);
			if (ft_atoi(tab[6]) < 0)
				return (3);
			cam->sector = ft_atoi(tab[6]);
			cam->angle = fabs(ft_radians(ft_atoi(tab[8]) % 360));
		}
		else
			return (3);
	}
	else
		return (3);
	return (0);
}

int		verif_blank(char **t)
{
	int		i;
	int		j;

	i = -1;
	while (t[++i])
	{
		j = -1;
		while (t[i][++j])
			if (!ft_isspace(t[i][j]))
				return (1);
	}
	return (0);
}
