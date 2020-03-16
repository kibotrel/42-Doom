/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:34:34 by reda-con          #+#    #+#             */
/*   Updated: 2020/03/15 21:08:47 by vivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include "clean.h"

static void	init_total(t_parse *par, char **tab, t_env *env)
{
	if ((par->total = ft_atoi(tab[2])) <= 0)
		clean(env, E_P_TOTAL);
	if ((env->zones = ft_atoi(tab[4])) < 1)
		clean(env, E_P_NB_SECTOR);
	if (!(par->ver = (t_vec2d*)malloc(sizeof(t_vec2d) * par->total)))
		parse_err(tab, par, env, E_MALLOC);
	if (!(env->sector = (t_sector*)malloc(sizeof(t_sector) * env->zones)))
		parse_err(tab, par, env, E_MALLOC);
	ft_bzero(env->sector, sizeof(t_sector) * env->zones);
}

int			verif_total(char **tab, t_parse *par, t_env *env)
{
	if (tab[1] && tab[3] && !ft_strcmp("vertexes", tab[1])
			&& !ft_strcmp("sectors", tab[3]) && !tab[5])
	{
		if (tab[2] && tab[4] && ft_isnum(tab[2])
				&& ft_isnum(tab[4]))
		{
			init_total(par, tab, env);
		}
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
