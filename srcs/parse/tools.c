/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:50:27 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/17 16:32:23 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../../libft/incs/libft.h"
#include <stdlib.h>

t_point		init_pt(int x, int y)
{
	t_point	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

int			ft_isnumber(char *num)
{
	size_t	i;

	if (!num)
		return (0);
	i = 0;
	if (num[i] == '-')
		i++;
	while (ft_isdigit(num[i]))
		i++;
	if (i != ft_strlen(num))
		return (0);
	return (1);
}

void		free_tab(char **t)
{
	int		i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		++i;
	}
	free(t);
}

void		init_parse(t_parse *p)
{
	p->v = NULL;
	p->e = NULL;
	p->o = NULL;
	p->s = NULL;
}
