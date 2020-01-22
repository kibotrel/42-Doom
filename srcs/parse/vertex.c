/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:20:55 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/22 16:12:06 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>
#include "libft.h"

t_vertex	*ver_new(t_point p)
{
	t_vertex	*new;

	if (!(new = (t_vertex*)malloc(sizeof(t_vertex))))
		return (NULL);
	new->pt = p;
	new->next = NULL;
	return (new);
}

void		free_ver(t_vertex **v)
{
	t_vertex	*tmp;
	t_vertex	*to_free;

	if (*v == NULL)
		return ;
	to_free = *v;
	tmp = *v;
	while (tmp)
	{
		tmp = to_free->next;
		free(to_free);
		to_free = tmp;
	}
	free(v);
}

void		ver_add_back(t_vertex **v, t_point p)
{
	t_vertex	*tmp;

	if (*v == NULL)
	{
		if (!(*v = ver_new(p)))
			exit(1);
	}
	else
	{
		tmp = *v;
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (!(tmp->next = ver_new(p)))
		{
			free_ver(v);
			exit(1);
		}
	}
}

int			verif_ver(t_vertex **v_s, char **tab)
{
	if (tab[1] && tab[3] && !ft_strcmp(tab[1], "y") && !ft_strcmp(tab[3], "x"))
	{
		if (tab[2] && tab[4] && ft_isnum(tab[2]) && ft_isnum(tab[4]))
			ver_add_back(v_s, init_pt(ft_atoi(tab[2]), ft_atoi(tab[4])));
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
