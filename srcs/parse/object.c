/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:19:31 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/16 16:48:56 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>
#include "../../libft/incs/libft.h"

t_object	*obj_new(int n, t_point p)
{
	t_object	*new;

	if (!(new = (t_object*)malloc(sizeof(t_object))))
		return (NULL);
	new->n = n;
	new->pt = p;
	new->next = NULL;
	return (new);
}

void		obj_add_back(t_object **o, int n, t_point p)
{
	t_object	*tmp;

	if (*o == NULL)
		*o = obj_new(n, p);
	else
	{
		tmp = *o;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = obj_new(n, p);
	}
}

void		verif_obj(t_object **o_s, char **tab)
{
	if (tab[1] && tab[3] && tab[5] && !ft_strcmp(tab[1], "number")\
		&& !ft_strcmp(tab[3], "y") && !ft_strcmp(tab[5], "x"))
		if (tab[2] && tab[4] && tab[6] && ft_isnumber(tab[2])\
			&& ft_isnumber(tab[4]) && ft_isnumber(tab[6]))
			obj_add_back(o_s, ft_atoi(tab[2]),\
				init_pt(ft_atoi(tab[4]), ft_atoi(tab[6])));
}
