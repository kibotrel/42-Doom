/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:35:58 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/21 17:05:44 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../../libft/incs/libft.h"
#include <stdlib.h>

t_sector	*sec_new(int n, t_height h, t_ver_port v_p)
{
	t_sector	*new;

	if (!(new = (t_sector*)malloc(sizeof(t_sector))))
		return (NULL);
	new->n = n;
	new->h = h;
	new->v_p = v_p;
	new->next = NULL;
	return (new);
}

void		sec_add_back(t_sector **s, int n, t_height h, t_ver_port v_p)
{
	t_sector	*tmp;

	if (*s == NULL)
	{
		if (!(*s = sec_new(n, h, v_p)))
			exit(1);
	}
	else
	{
		tmp = *s;
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (!(tmp->next = sec_new(n, h, v_p)))
			exit(1);
	}
}

t_height	init_height(int f, int c)
{
	t_height	ret;

	ret.floor = f;
	ret.ceil = c;
	return (ret);
}

int			verif_vp(char **tab, t_ver_port *v_p, int j)
{
	int		i;

	i = -1;
	v_p->size = j;
	while (++i < j)
		if (!ft_isnumber(tab[10 + i]) || !ft_isnumber(tab[11 + j + i]))
		{
			return (1);
		}
	if (!(v_p->vertex = (int*)malloc(sizeof(int) * j)))
		return (1);
	if (!(v_p->portal = (int*)malloc(sizeof(int) * j)))
	{
		free(v_p->vertex);
		return (1);
	}
	i = -1;
	while (++i < j)
	{
		v_p->vertex[i] = ft_atoi(tab[10 + i]);
		v_p->portal[i] = ft_atoi(tab[11 + j + i]);
	}
	return (0);
}

void		verif_sec(t_sector **s, char **tab)
{
	t_ver_port	v_p;

	if (tab[8] && ft_isnumber(tab[8]) && tab[7]\
		&& !ft_strcmp("vertex_num", tab[7]))
	{
		if (tab[1] && tab[3] && tab[5] && tab[9] && tab[10 + ft_atoi(tab[8])]\
			&& !ft_strcmp("number", tab[1])\
			&& !ft_strcmp("h_floor", tab[3]) && !ft_strcmp("h_ceil", tab[5])\
			&& !ft_strcmp("vertexes", tab[9])\
			&& !ft_strcmp("portals", tab[9 + ft_atoi(tab[8]) + 1]))
		{
			if (verif_vp(tab, &v_p, ft_atoi(tab[8])))
				exit(1);
			if (tab[2] && tab[4] && tab[6] && ft_isnumber(tab[2])\
					&& ft_isnumber(tab[4]) && ft_isnumber(tab[6]))
				sec_add_back(s, ft_atoi(tab[2]),
					init_height(ft_atoi(tab[4]), ft_atoi(tab[6])), v_p);
			else
				exit(1);
		}
		else
			exit(1);
	}
	else
		exit(1);
}
