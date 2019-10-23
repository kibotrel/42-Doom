/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:20:25 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/23 17:02:30 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>
#include "../../libft/incs/libft.h"

t_ennemy	*en_new(int n, t_point pt)
{
	t_ennemy	*new;

	if (!(new = (t_ennemy*)malloc(sizeof(t_ennemy))))
		return (NULL);
	new->n = n;
	new->pt = pt;
	new->next = NULL;
	return (new);
}

void		free_en(t_ennemy **e)
{
	t_ennemy	*tmp;
	t_ennemy	*to_free;

	if (*e == NULL)
		return ;
	tmp = *e;
	to_free = *e;
	while (tmp)
	{
		tmp = to_free->next;
		free(to_free);
		to_free = tmp;
	}
	free(e);
}

void		en_add_back(t_ennemy **e, int n, t_point p)
{
	t_ennemy	*tmp;

	if (*e == NULL)
	{
		if (!(*e = en_new(n, p)))
			exit(1);
	}
	else
	{
		tmp = *e;
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (!(tmp->next = en_new(n, p)))
		{
			free_en(e);
			exit(1);
		}
	}
}

int			verif_en(t_ennemy **e_s, char **tab)
{
	if (tab[1] && tab[3] && tab[5] && !ft_strcmp(tab[1], "number")\
		&& !ft_strcmp(tab[3], "y") && !ft_strcmp(tab[5], "x"))
	{
		if (tab[2] && tab[4] && tab[6] && ft_isnum(tab[2])\
			&& ft_isnum(tab[4]) && ft_isnum(tab[6]))
			en_add_back(e_s, ft_atoi(tab[2]),\
				init_pt(ft_atoi(tab[4]), ft_atoi(tab[6])));
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
