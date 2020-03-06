/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <lojesu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:00:25 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/06 10:51:07 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

char	*ft_strjoin_free(char *s1, char *s2, int mod)
{
	char	*str_join;
	size_t	join_size;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	join_size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str_join = (char *)malloc(sizeof(char) * join_size + 1)))
		return (NULL);
	ft_strcpy(str_join, s1);
	ft_strcat(str_join, s2);
	if (mod == 1)
		ft_strdel(&s1);
	else if (mod == 2)
		ft_strdel(&s2);
	else
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str_join);
}
