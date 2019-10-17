/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42/.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:58:47 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/17 16:18:26 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../../libft/incs/libft.h"
#include <stdlib.h>

t_sector	*sec_new(int n, int h_floor, int h_ceil, int size_vp, int *vs, int *ps)
{
	t_sector	*new;

	if (!(new = (t_sector*)malloc(sizeof(t_sector))))
		return (NULL);
	new->n = n;
	new->h_floor = h_floor;
	new->h_ceil = h_ceil;
	new->size_vp = size_vp;
	new->vertexes = vs;
	new->portals = ps;
	new->next = NULL;
	return (new);
}

void		sec_add_back(t_sector **s, int n, int h_floor, int h_ceil, int size_vp, int *vs, int *ps)
{
	t_sector	*tmp;

	if (*s == NULL)
		*s = sec_new(n, h_floor, h_ceil, size_vp, vs, ps);
	else
	{
		tmp = *s;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = sec_new(n, h_floor, h_ceil, size_vp, vs, ps);
	}
}

void		verif_sec(t_sector **s, char **tab)
{
	int		*v;
	int		*p;
	int		i;
	int		j;

	i = -1;
	if (tab[8] && ft_isnumber(tab[8]) && tab[7] && !ft_strcmp("vertex_num", tab[7]))
	{
		j = ft_atoi(tab[8]);
		if (tab[1] && tab[3] && tab[5] && tab[9] && tab[10 + j]\
			&& !ft_strcmp("number", tab[1]) && !ft_strcmp("h_floor", tab[3])\
			&& !ft_strcmp("h_ceil", tab[5]) && !ft_strcmp("vertexes", tab[9])\
			&& !ft_strcmp("portals", tab[9 + j + 1]))
		{
			while (++i < j)
				if (!ft_isnumber(tab[10 + i]) || !ft_isnumber(tab[11 + j + i]))
				{
					return ;
				}
			if (!(v = (int*)malloc(sizeof(int) * j)))
				return ;
			if (!(p = (int*)malloc(sizeof(int) * j)))
				return ;
			i = -1;
			while (++i < j)
			{
				v[i] = ft_atoi(tab[10 + i]);
				p[i] = ft_atoi(tab[11 + j + i]);
			}
			if (tab[2] && tab[4] && tab[6] && tab[8] && ft_isnumber(tab[2])\
				&& ft_isnumber(tab[4]) && ft_isnumber(tab[6]))
				sec_add_back(s, ft_atoi(tab[2]), ft_atoi(tab[4]), ft_atoi(tab[6]), j, v, p);
		}
	}
}
