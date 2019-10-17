/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:35:58 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/17 16:52:57 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../../libft/incs/libft.h"
#include <stdlib.h>

t_sector	*sec_new(int n, t_height h, int size_vp, int **v_p)
{
	t_sector	*new;

	if (!(new = (t_sector*)malloc(sizeof(t_sector))))
		return (NULL);
	new->n = n;
	new->h = h;
	new->size_vp = size_vp;
	new->v_p = v_p;
	new->next = NULL;
	return (new);
}

void		sec_add_back(t_sector **s, int n, t_height h, int size_vp, int **v_p)
{
	t_sector	*tmp;

	if (*s == NULL)
		*s = sec_new(n, h, size_vp, v_p);
	else
	{
		tmp = *s;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = sec_new(n, h, size_vp, v_p);
	}
}

t_height	init_height(int f, int c)
{
	t_height	ret;

	ret.floor = f;
	ret.ceil = c;
	return (ret);
}

int			verif_vp(char **tab, int **v_p, int j)
{
	int		i;

	i = -1;
	while (++i < j)
		if (!ft_isnumber(tab[10 + i]) || !ft_isnumber(tab[11 + j + i]))
		{
			return (1);
		}
	if (!(v_p = (int**)malloc(sizeof(int*) * 2)))
		return (1);
	if (!(v_p[0] = (int*)malloc(sizeof(int) * j)))
		return (1);
	if (!(v_p[1] = (int*)malloc(sizeof(int) * j)))
		return (1);
	i = -1;
	while (++i < j)
	{
		v_p[0][i] = ft_atoi(tab[10 + i]);
		v_p[1][i] = ft_atoi(tab[11 + j + i]);
	}
	return (0);
}

void		verif_sec(t_sector **s, char **tab)
{
	int		**v_p;
	int		j;

	v_p = NULL;
	if (tab[8] && ft_isnumber(tab[8]) && tab[7] && !ft_strcmp("vertex_num", tab[7]))
	{
		j = ft_atoi(tab[8]);
		if (tab[1] && tab[3] && tab[5] && tab[9] && tab[10 + j]\
				&& !ft_strcmp("number", tab[1]) && !ft_strcmp("h_floor", tab[3])\
				&& !ft_strcmp("h_ceil", tab[5]) && !ft_strcmp("vertexes", tab[9])\
				&& !ft_strcmp("portals", tab[9 + j + 1]))
		{
			if (!verif_vp(tab, v_p, j))
				return ;
			if (tab[2] && tab[4] && tab[6] && tab[8] && ft_isnumber(tab[2])\
					&& ft_isnumber(tab[4]) && ft_isnumber(tab[6]))
				sec_add_back(s, ft_atoi(tab[2]), init_height(ft_atoi(tab[4]), ft_atoi(tab[6])), j, v_p);
		}
	}
}
