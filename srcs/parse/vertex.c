/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:20:55 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/17 15:17:53 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>
#include "../../libft/incs/libft.h"

t_vertex	*ver_new(t_point p)
{
	t_vertex	*new;

	if (!(new = (t_vertex*)malloc(sizeof(t_vertex))))
		return (NULL);
	new->pt = p;
	new->next = NULL;
	return (new);
}

void		ver_add_back(t_vertex **v, t_point p)
{
	t_vertex	*tmp;

	if (*v == NULL)
		*v = ver_new(p);
	else
	{
		tmp = *v;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ver_new(p);
	}
}

void		verif_ver(t_vertex **v_s, char **tab)
{
	if (tab[1] && tab[3] && !ft_strcmp(tab[1], "y") && !ft_strcmp(tab[3], "x"))
		if (tab[2] && tab[4] && ft_isnumber(tab[2]) && ft_isnumber(tab[4]))
			ver_add_back(v_s, init_pt(ft_atoi(tab[2]), ft_atoi(tab[4])));
}
