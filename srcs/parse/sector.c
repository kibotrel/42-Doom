/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:35:58 by reda-con          #+#    #+#             */
/*   Updated: 2020/02/20 11:49:49 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include "clean.h"
#include <stdlib.h>

int			third_check(t_sector *s, char **t, t_vec2d *ver, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (t[20 + j] && ft_isnum(t[20 + j]))
			s[ft_atoi(t[2])].vertex[j] = ver[ft_atoi(t[20 + j])];
		else{ft_putendl("oui");
			return (1);}
		if (t[21 + i + j] && ft_isnum(t[21 + i + j]))
			s[ft_atoi(t[2])].neighbor[j] = ft_atoi(t[21 + i + j]);
		else{ft_putendl("non");
			return (1);}
		++j;
	}
	if (t[21 + i + j])
		return (1);
	return (0);
}

int			second_check(t_sector *s, char **t, t_vec2d *ver, t_env *e)
{
	int		i;

	i = ft_atoi(t[18]);
	s[ft_atoi(t[2])].texture = ft_atoi(t[4]);
	s[ft_atoi(t[2])].type = ft_atoi(t[6]);
	s[ft_atoi(t[2])].light = ft_atoi(t[8]);
	s[ft_atoi(t[2])].floor = ft_atoi(t[10]);
	s[ft_atoi(t[2])].ceil = ft_atoi(t[12]);
	if (s[ft_atoi(t[2])].floor >= s[ft_atoi(t[2])].ceil)
		clean(e, E_PARSE);
	s[ft_atoi(t[2])].gravity = (double)ft_atoi(t[14]) / 100;
	s[ft_atoi(t[2])].friction = (double)ft_atoi(t[16]) / 100;
	s[ft_atoi(t[2])].points = i;
	if (!(s[ft_atoi(t[2])].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * i)))
		clean(e, E_PARSE);
	if (!(s[ft_atoi(t[2])].neighbor = (int*)malloc(sizeof(int) * i)))
		clean(e, E_PARSE);
	if (t[20 + i] && !ft_strcmp(t[20 + i], "portals"))
	{
		if (third_check(s, t, ver, i))
			return (1);
	}
	else
		return (1);
	return (0);
}

int			verif_sector(t_sector *s, char **t, t_vec2d *ver, t_env *e)
{
	if (t[1] && t[3] && t[5] && t[7] && t[9] && t[11] && t[13] && t[15] && t[17]
			&& t[19]
			&& !ft_strcmp(t[1], "number") && !ft_strcmp(t[3], "texture")
			&& !ft_strcmp(t[5], "type") && !ft_strcmp(t[7], "light")
			&& !ft_strcmp(t[9], "h_floor") && !ft_strcmp(t[11], "h_ceil")
			&& !ft_strcmp(t[13], "gravity") && !ft_strcmp(t[15], "friction")
			&& !ft_strcmp(t[17], "vertex_num") && !ft_strcmp(t[19], "vertexes"))
	{
		if (t[2] && t[4] && t[6] && t[8] && t[10] && t[12] && t[14] && t[16] && t[18]
				&& ft_isnum(t[2]) && ft_isnum(t[4]) && ft_isnum(t[6])
				&& ft_isnum(t[8]) && ft_isnum(t[10]) && ft_isnum(t[12])
				&& ft_isnum(t[14]) && ft_isnum(t[16]) && ft_isnum(t[18]))
		{
			if (second_check(s, t, ver, e))
				return (1);
		}
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
