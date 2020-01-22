/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:35:58 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/22 16:11:54 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
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

void		free_sec(t_sector **s)
{
	t_sector	*tmp;
	t_sector	*to_free;

	if (*s == NULL)
		return ;
	to_free = *s;
	tmp = *s;
	while (tmp)
	{
		tmp = to_free->next;
		free(to_free->v_p.vertex);
		free(to_free->v_p.portal);
		free(to_free);
		to_free = tmp;
	}
	free(s);
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
		{
			free_sec(s);
			exit(1);
		}
	}
}

int			verif_vp(char **tab, t_ver_port *v_p, int j)
{
	int		i;

	i = -1;
	v_p->size = j;
	while (++i < j)
		if (!ft_isnum(tab[10 + i]) || !ft_isnum(tab[11 + j + i]))
			return (1);
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

int			verif_sec(t_sector **s, char **t)
{
	t_ver_port	v_p;

	if (t[8] && ft_isnum(t[8]) && t[7] && !ft_strcmp("vertex_num", t[7]))
	{
		if (t[1] && t[3] && t[5] && t[9] && t[10 + ft_atoi(t[8])]\
			&& !ft_strcmp("number", t[1])\
			&& !ft_strcmp("h_floor", t[3]) && !ft_strcmp("h_ceil", t[5])\
			&& !ft_strcmp("vertexes", t[9])\
			&& !ft_strcmp("portals", t[10 + ft_atoi(t[8])]))
		{
			if (verif_vp(t, &v_p, ft_atoi(t[8])))
				exit(1);
			if (t[2] && t[4] && t[6] && ft_isnum(t[2])\
					&& ft_isnum(t[4]) && ft_isnum(t[6]))
				sec_add_back(s, ft_atoi(t[2]),
					init_height(ft_atoi(t[4]), ft_atoi(t[6])), v_p);
			else
				return (1);
		}
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
