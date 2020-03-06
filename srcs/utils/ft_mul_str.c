/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mul_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <lojesu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:03:32 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/06 10:50:19 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static int	ft_protection(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (s1[i])
	{
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

static char	*ft_fill_res_tmp(char *tmp, char *s, int j, int *ret)
{
	int		i;
	char	*tmp_res;

	i = ft_strlen(tmp) - 1;
	tmp_res = ft_strnew(i + 1);
	while (i > -1)
	{
		tmp_res[i] = (tmp[i] - 48) * (s[j] - 48) + *ret;
		if (tmp_res[i] > 9)
		{
			*ret = tmp_res[i] / 10;
			tmp_res[i] = tmp_res[i] % 10 + 48;
		}
		else
		{
			tmp_res[i] = tmp_res[i] + 48;
			*ret = 0;
		}
		i--;
	}
	return (tmp_res);
}

static void	ft_add_s_to_s(char **res, char *s, int j)
{
	int		ret;
	char	*tmp;
	char	*tmp_res;

	tmp = ft_strdup(*res);
	ft_strdel(res);
	while (j > -1)
	{
		ret = 0;
		tmp_res = ft_fill_res_tmp(tmp, s, j, &ret);
		if (ret >= 1)
			tmp_res = ft_strjoin_free(ft_itoa(ret), tmp_res, 0);
		if (j != (int)ft_strlen(s) - 1)
			*res = ft_add_str(*res, tmp_res, 3);
		else
		{
			*res = ft_strdup(tmp_res);
			ft_strdel(&tmp_res);
		}
		tmp = ft_strjoin_free(tmp, "0", 1);
		j--;
	}
	ft_strdel(&tmp);
}

char		*ft_mul_str(char *s1, char *s2, int mod)
{
	char	*res;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL || ft_protection(s1, s2) == 0)
		return (0);
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	if (i >= j)
	{
		res = ft_strdup(s1);
		ft_add_s_to_s(&res, s2, j);
	}
	else
	{
		res = ft_strdup(s2);
		ft_add_s_to_s(&res, s1, i);
	}
	ft_deal_mod(&s1, &s2, mod);
	return (res);
}
