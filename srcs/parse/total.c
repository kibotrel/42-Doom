/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:34:34 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/23 16:58:23 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

void	init_total(t_total *total, char **tab, t_parse *par)
{
	total->vert = ft_atoi(tab[2]);
	total->sect = ft_atoi(tab[4]);
	total->emy = ft_atoi(tab[6]);
	total->obj = ft_atoi(tab[8]);
	if (!(par->ver = (t_vec2d*)malloc(sizeof(t_vec2d) * total->vert)))
		parse_err(tab, par);
	if (!(par->sec = (t_sector*)malloc(sizeof(t_sector) * total->sect)))
		parse_err(tab, par);
	if (!(par->emy = (t_entity*)malloc(sizeof(t_entity) * total->emy)))
		parse_err(tab, par);
	if (!(par->obj = (t_entity*)malloc(sizeof(t_entity) * total->obj)))
		parse_err(tab, par);
}

int		verif_total(t_total *total, char **tab, t_parse *par)
{
	if (tab[1] && tab[3] && tab[5] && tab[7] && !ft_strcmp("vertexes", tab[1])
			&& !ft_strcmp("sectors", tab[3]) && !ft_strcmp("enemies", tab[5])
			&& !ft_strcmp("objects", tab[7]))
	{
		if (tab[2] && tab[4] && tab[6] && tab[8] && ft_isnum(tab[2])
				&& ft_isnum(tab[4]) && ft_isnum(tab[6]) && ft_isnum(tab[8]))
			init_total(total, tab, par);
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
