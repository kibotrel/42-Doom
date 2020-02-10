/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:50:27 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/29 11:46:16 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stdlib.h>

t_vec2d		init_vec2d(int x, int y)
{
	t_vec2d	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

int			ft_isnum(char *num)
{
	size_t	i;

	if (!num)
		return (0);
	i = 0;
	if (num[i] == '-' || num[i] == '+')
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
