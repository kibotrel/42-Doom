/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <lojesu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:41:32 by lojesu            #+#    #+#             */
/*   Updated: 2020/01/29 07:08:37 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils.h"

static int	ft_protection(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '-')
			i++;
		if (ft_isdigit(s1[i]) == 0)
			return (0);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (ft_isdigit(s2[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_deal_mod(char **s1, char **s2, int mod)
{
	if (mod == 1)
		ft_strdel(s1);
	else if (mod == 2)
		ft_strdel(s2);
	else if (mod == 3)
	{
		ft_strdel(s1);
		ft_strdel(s2);
	}
}

static void	ft_deal_ret(char **tmp, int i, int ret)
{
	while (ret == 1 && i > -1)
	{
		(*tmp)[i] = (*tmp)[i] + ret;
		if ((*tmp)[i] > 57)
		{
			(*tmp)[i] = '0';
			ret = 1;
		}
		else
			ret = 0;
		i--;
	}
	if (ret == 1 && i == -1)
	{
		if (!(*tmp = ft_realloc(*tmp, 1, 1)))
			exit(1);
		(*tmp)[0] = '1';
	}
}

static void	ft_add_s_to_s(char **tmp, char *s, int i, int j)
{
	int	ret;

	ret = 0;
	while (j > -1)
	{
		(*tmp)[i] = (*tmp)[i] + s[j] + ret - 48;
		if ((*tmp)[i] > 57)
		{
			(*tmp)[i] = (*tmp)[i] - 10;
			ret = 1;
		}
		else
			ret = 0;
		i--;
		j--;
	}
	if (ret == 1)
		ft_deal_ret(tmp, i, ret);
}

char		*ft_add_str(char *s1, char *s2, int mod)
{
	char	*tmp;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL || ft_protection(s1, s2) == 0)
		return (0);
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	if (i >= j)
	{
		tmp = ft_strdup(s1);
		tmp[0] == '-' ? tmp[0] = '0' : tmp[0];
		ft_add_s_to_s(&tmp, s2, i, j);
		if (s1[0] == '-' && tmp[0] == '0')
			tmp[0] = '-';
		else if (s1[0] == '-' && tmp[0] != '0')
			tmp = ft_strjoin_free("-", tmp, 2);
	}
	else
	{
		tmp = ft_strdup(s2);
		ft_add_s_to_s(&tmp, s1, j, i);
	}
	ft_deal_mod(&s1, &s2, mod);
	return (tmp);
}
