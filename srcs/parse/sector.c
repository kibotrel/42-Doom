/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:35:58 by reda-con          #+#    #+#             */
/*   Updated: 2020/03/05 17:42:51 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include "clean.h"
#include <stdlib.h>

int			third_check(t_env *e, char **t, t_vec2d *ver, int i)
{
	int j;

	e->sector[ft_atoi(t[2])].elvt = ft_atoi(t[12]);
	e->sector[ft_atoi(t[2])].type = ft_atoi(t[6]);
	e->sector[ft_atoi(t[2])].light = ft_atoi(t[10]);
	j = 0;
	while (j < i)
	{
		if (t[22 + j] && ft_isnum(t[22 + j]) && t[22 + j]
				&& ft_atoi(t[22 + j]) < (int)e->vert_ct
				&& ft_atoi(t[22 + j]) >= 0)
			e->sector[ft_atoi(t[2])].vertex[j] = ver[ft_atoi(t[22 + j])];
		else
			return (4);
		if (t[23 + i + j] && ft_isnum(t[23 + i + j])
				&& ft_atoi(t[23 + i + j]) < (int)e->zones)
			e->sector[ft_atoi(t[2])].neighbor[j] = ft_atoi(t[23 + i + j]);
		else
			return (4);
		++j;
	}
	if (t[23 + i + j])
		return (4);
	return (0);
}

int			second_check(t_sector *s, char **t, t_vec2d *ver, t_env *e)
{
	int		i;
	int		j;

	j = 0;
	while (t[j])
		++j;
	i = ft_atoi(t[20]);
	s[ft_atoi(t[2])].floor = ft_atoi(t[12]);
	s[ft_atoi(t[2])].ceil = ft_atoi(t[14]);
	if ((s[ft_atoi(t[2])].texture = ft_atoi(t[4])) < 0
	|| ft_atoi(t[4]) > 9 || (s[ft_atoi(t[2])].data = ft_atoi(t[8])) < 0
	|| s[ft_atoi(t[2])].floor >= s[ft_atoi(t[2])].ceil
	|| ft_atoi(t[16]) <= 0 || ft_atoi(t[18]) < 0 || (uint32_t)i > e->vert_ct)
		return (4);
	s[ft_atoi(t[2])].gravity = (double)ft_atoi(t[16]) / 100;
	s[ft_atoi(t[2])].friction = (double)ft_atoi(t[18]) / 100;
	s[ft_atoi(t[2])].points = i;
	if (!(s[ft_atoi(t[2])].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * i)))
		clean(e, E_MALLOC);
	if (!(s[ft_atoi(t[2])].neighbor = (int*)malloc(sizeof(int) * i)))
		clean(e, E_MALLOC);
	if (23 + 2 * i < j && t[22 + i] && !ft_strcmp(t[22 + i], "portals"))
	{
		if (third_check(e, t, ver, i))
			return (4);
	}
	else
		return (4);
	return (0);
}

int			verif_sector(t_sector *s, char **t, t_vec2d *ver, t_env *e)
{
	if (t[1] && t[3] && t[5] && t[7] && t[9] && t[11] && t[13] && t[15] && t[17]
			&& t[19] && t[21] && !ft_strcmp(t[1], "number")
			&& !ft_strcmp(t[3], "texture") && !ft_strcmp(t[5], "type")
			&& !ft_strcmp(t[7], "data") && !ft_strcmp(t[9], "light")
			&& !ft_strcmp(t[11], "h_floor") && !ft_strcmp(t[13], "h_ceil")
			&& !ft_strcmp(t[15], "gravity") && !ft_strcmp(t[17], "friction")
			&& !ft_strcmp(t[19], "vertex_num") && !ft_strcmp(t[21], "vertexes"))
	{
		if (t[2] && t[4] && t[6] && t[8] && t[10] && t[12] && t[14] && t[16]
				&& t[18] && t[20] && ft_isnum(t[2]) && ft_isnum(t[4])
				&& ft_isnum(t[6]) && ft_isnum(t[8]) && ft_isnum(t[10])
				&& ft_isnum(t[12]) && ft_isnum(t[14]) && ft_isnum(t[16])
				&& ft_isnum(t[18]) && ft_isnum(t[20]))
		{
			if (second_check(s, t, ver, e) || ft_atoi(t[2]) != (int)e->sect_ct
					|| ft_atoi(t[2]) >= (int)e->zones)
				return (4);
		}
		else
			return (4);
	}
	else
		return (4);
	++e->sect_ct;
	return (0);
}
