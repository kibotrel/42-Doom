/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_binary_to_nb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:42:12 by roster            #+#    #+#             */
/*   Updated: 2020/01/29 07:02:19 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static int	ft_protection(char *bin)
{
	size_t	i;

	i = 0;
	while (bin[i])
	{
		if (bin[i] != '1' && bin[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char		*ft_str_binary_to_nb(char *bin, int mod)
{
	int		i;
	int		j;
	char	*res;

	if (!bin || ft_protection(bin) == 0)
		return (0);
	res = ft_strnew(1);
	res[0] = '0';
	i = 0;
	j = ft_strlen(bin) - 1;
	while (bin[i])
	{
		if (bin[i] == '1')
			res = ft_add_str(res, ft_power_str((j - i), 2), 3);
		i++;
	}
	if (mod == 1)
		ft_strdel(&bin);
	return (res);
}
