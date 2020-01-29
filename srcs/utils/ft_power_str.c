/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 09:26:44 by roster            #+#    #+#             */
/*   Updated: 2020/01/29 07:13:38 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

char	*ft_power_str(size_t power, size_t base)
{
	char	*tmp;
	char	*str_base;
	size_t	i;

	tmp = ft_strnew(1);
	tmp[0] = '1';
	i = 0;
	if (power == 0)
		return (tmp);
	str_base = ft_itoa(base);
	while (i < power)
	{
		tmp = ft_mul_str(tmp, str_base, 1);
		i++;
	}
	ft_strdel(&str_base);
	return (tmp);
}
