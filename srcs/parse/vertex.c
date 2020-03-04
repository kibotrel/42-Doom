/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:20:55 by reda-con          #+#    #+#             */
/*   Updated: 2020/03/04 15:09:54 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>
#include "libft.h"
#include "utils.h"

int			verif_vertex(t_vec2d *vec, char **tab, int *nb, t_parse *p)
{
	if (tab[1] && tab[3] && tab[5] && !ft_strcmp(tab[1], "number")
			&& !ft_strcmp(tab[3], "x") && !ft_strcmp(tab[5], "y") && !tab[7])
	{
		if (tab[2] && tab[4] && tab[6] && ft_isnum(tab[2]) && ft_isnum(tab[4])
				&& ft_isnum(tab[6]))
		{
			if (*nb == ft_atoi(tab[2]) && ft_atoi(tab[2]) < p->total
					&& ft_atoi(tab[4]) >= 0 && ft_atoi(tab[6]) >= 0)
				vec[ft_atoi(tab[2])] = v2d(ft_atoi(tab[4]), ft_atoi(tab[6]));
			else
				return (2);
		}
		else
			return (2);
	}
	else
		return (2);
	++*nb;
	return (0);
}
