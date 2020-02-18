/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_mantisse_to_nb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <lojesu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:54:39 by lojesu            #+#    #+#             */
/*   Updated: 2020/02/14 08:02:46 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static char	*ft_adjust_str(int i, int *k)
{
	int		j;
	char	*tmp;

	tmp = ft_power_str((i + 1), 5);
	if (*k == 0)
		*k = i + 1;
	j = (i + 1) - ft_strlen(tmp);
	while (j > 0)
	{
		tmp = ft_strjoin_free("0", tmp, 2);
		j--;
	}
	j = ft_strlen(tmp);
	while (j < *k)
	{
		tmp = ft_strjoin_free(tmp, "0", 1);
		j++;
	}
	return (tmp);
}

char		*ft_str_mantisse_to_nb(char *m, int mod)
{
	char	*res;
	int		i;
	int		k;

	i = ft_strlen(m) - 1;
	res = ft_strnew(1);
	k = 0;
	while (i > -1)
	{
		if (m[i] == '1')
			res = ft_add_str(res, ft_adjust_str(i, &k), 3);
		i--;
	}
	if (mod == 1)
		ft_strdel(&m);
	return (res);
}
