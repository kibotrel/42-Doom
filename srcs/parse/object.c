/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:19:31 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/22 16:11:34 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>
#include "libft.h"

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

void		free_obj(t_object **o)
{
	t_object	*tmp;
	t_object	*to_free;

	if (*o == NULL)
		return ;
	tmp = *o;
	to_free = *o;
	while (tmp)
	{
		tmp = to_free->next;
		free(to_free);
		to_free = tmp;
	}
	free(o);
}

void		obj_add_back(t_object **o, int n, t_point p)
{
	t_object	*tmp;

	if (*o == NULL)
	{
		if (!(*o = obj_new(n, p)))
			exit(1);
	}
	else
	{
		tmp = *o;
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (!(tmp->next = obj_new(n, p)))
		{
			free_obj(o);
			exit(1);
		}
	}
}

int			verif_obj(t_object **o_s, char **tab)
{
	if (tab[1] && tab[3] && tab[5] && !ft_strcmp(tab[1], "number")\
		&& !ft_strcmp(tab[3], "y") && !ft_strcmp(tab[5], "x"))
	{
		if (tab[2] && tab[4] && tab[6] && ft_isnum(tab[2])\
			&& ft_isnum(tab[4]) && ft_isnum(tab[6]))
			obj_add_back(o_s, ft_atoi(tab[2]),\
				init_pt(ft_atoi(tab[4]), ft_atoi(tab[6])));
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
