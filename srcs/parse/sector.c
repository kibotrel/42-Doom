/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:35:58 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/23 16:57:57 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stdlib.h>

int			third_check(t_sector *s, char **t, t_vec2d *ver, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (t[14 + j] && ft_isnum(t[14 + j]))
			s[ft_atoi(t[2])].vertex[j] = ver[ft_atoi(t[14 + j])];
		else
			return (1);
		if (t[15 + i + j] && ft_isnum(t[15 + i + j]))
			s[ft_atoi(t[2])].neighbor[j] = ft_atoi(t[15 + i + j]);
		else
			return (1);
		if (t[16 + 2 * i + j] && ft_isnum(t[16 + 2 * i]))
			s[ft_atoi(t[2])].portal_type[j] = ft_atoi(t[16 + 2 * i + j]);
		else
			return (1);
		++j;
	}
	return (0);
}

int			second_check(t_sector *s, char **t, t_vec2d *ver, t_parse *p)
{
	int		i;

	i = ft_atoi(t[12]);
	s[ft_atoi(t[2])].floor = ft_atoi(t[4]);
	s[ft_atoi(t[2])].ceil = ft_atoi(t[6]);
	s[ft_atoi(t[2])].gravity = ft_atoi(t[8]) / 100;
	s[ft_atoi(t[2])].viscosity = ft_atoi(t[10]) / 1000;
	s[ft_atoi(t[2])].points = i;
	if (!(s[ft_atoi(t[2])].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * i)))
		parse_err(t, p);
	if (!(s[ft_atoi(t[2])].neighbor = (int*)malloc(sizeof(int) * i)))
		parse_err(t, p);
	if (!(s[ft_atoi(t[2])].portal_type = (int*)malloc(sizeof(int) * i)))
		parse_err(t, p);
	if (t[14 + i] && t[15 + 2 * i] && !ft_strcmp(t[14 + i], "portals")
			&& !ft_strcmp(t[15 + 2 * i], "type"))
	{
		if (third_check(s, t, ver, i))
			return (1);
	}
	else
		return (1);
	return (0);
}

int			verif_sector(t_sector *s, char **t, t_vec2d *ver, t_parse *p)
{
	if (t[1] && t[3] && t[5] && t[7] && t[9] && t[11] && t[13]
			&& !ft_strcmp(t[1], "number") && !ft_strcmp(t[3], "h_floor")
			&& !ft_strcmp(t[5], "h_ceil") && !ft_strcmp(t[7], "gravity")
			&& !ft_strcmp(t[9], "viscosity")
			&& !ft_strcmp(t[11], "vertex_num")
			&& !ft_strcmp(t[13], "vertexes"))
	{
		if (t[2] && t[4] && t[6] && t[8] && t[10] && t[12]
				&& ft_isnum(t[2]) && ft_isnum(t[4]) && ft_isnum(t[6])
				&& ft_isnum(t[8]) && ft_isnum(t[10]) && ft_isnum(t[12]))
		{
			if (second_check(s, t, ver, p))
				return (1);
		}
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
