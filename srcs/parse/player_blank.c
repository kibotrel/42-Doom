/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_blank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:36:21 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/27 10:19:09 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

int		verif_player(t_player *pl, char **tab)
{
	if (pl->pos.x != -1 && pl->pos.y != -1)
		return (1);
	if (tab[1] && tab[3] && tab[5] && tab[7] && !ft_strcmp(tab[1], "x")
			&& !ft_strcmp(tab[3], "y") && !ft_strcmp(tab[5], "sector")
			&& !ft_strcmp(tab[7], "angle"))
	{
		if (tab[2] && tab[4] && tab[6] && tab[8] && ft_isnum(tab[2])
				&& ft_isnum(tab[4]) && ft_isnum(tab[6]) && ft_isnum(tab[8]))
		{
			pl->pos = init_vec2d(floor(ft_atoi(tab[2]) / 10), floor(ft_atoi(tab[4]) / 10));
			pl->sect = ft_atoi(tab[6]);
			pl->angle = ft_atoi(tab[8]);
		}
		else
			return (1);
	}
	else
		return (1);
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
