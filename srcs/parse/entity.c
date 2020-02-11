/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:06:28 by reda-con          #+#    #+#             */
/*   Updated: 2020/02/06 11:47:31 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>
#include "../../libft/incs/libft.h"

int			verif_entity(t_entity *ent, char **tab)
{
	if (tab[1] && tab[3] && tab[5] && tab[7] && tab[9] && tab[11]
			&& !ft_strcmp(tab[1], "number") && !ft_strcmp(tab[3], "x")
			&& !ft_strcmp(tab[5], "y") && !ft_strcmp(tab[7], "sector")
			&& !ft_strcmp(tab[9], "angle") && !ft_strcmp(tab[11], "type"))
	{
		if (tab[2] && tab[4] && tab[6] && tab[8] && tab[10] && tab[12]
			&& ft_isnum(tab[2]) && ft_isnum(tab[4]) && ft_isnum(tab[6])
			&& ft_isnum(tab[8]) && ft_isnum(tab[10]) && ft_isnum(tab[12]))
		{
			ent[ft_atoi(tab[2])].pos = init_vec2d(ft_atoi(tab[4]),
					ft_atoi(tab[6]));
			ent[ft_atoi(tab[2])].sect = ft_atoi(tab[8]);
			ent[ft_atoi(tab[2])].angle = ft_atoi(tab[10]);
			ent[ft_atoi(tab[2])].type = ft_atoi(tab[12]);
		}
		else
			return (1);
	}
	else if (tab[13])
		return (1);
	else
		return (1);
	return (0);
}
