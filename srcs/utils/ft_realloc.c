/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <lojesu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:44:21 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/06 10:50:43 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

char	*ft_realloc(char *s, size_t size, size_t mod)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (!(tmp = ft_strnew(ft_strlen(s) + size)))
		return (0);
	if (mod == 0)
		tmp = ft_strcpy(tmp, s);
	else
	{
		while (s[i])
		{
			tmp[i + size] = s[i];
			i++;
		}
	}
	ft_strdel(&s);
	return (tmp);
}
