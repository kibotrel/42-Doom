/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:33:33 by roster            #+#    #+#             */
/*   Updated: 2020/01/29 06:50:45 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static int	ft_check_mantisse(char *m, size_t i)
{
	while (m[i])
	{
		if (m[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_mantisse_float(char *m, int res, int i)
{
	char *new_m;

	if (res < 0)
	{
		new_m = ft_strsub(m, i, ft_strlen(m) - i);
		new_m = ft_strjoin_free("1", new_m, 2);
		while (res < -1)
		{
			new_m = ft_strjoin_free("0", new_m, 2);
			res++;
		}
	}
	else
	{
		if ((int)ft_strlen(m) - i - res > 0)
			new_m = ft_strsub(m, i + res, (int)ft_strlen(m) - i - res);
		else
			new_m = ft_strnew(1);
	}
	return (ft_str_mantisse_to_nb(new_m, 1));
}

static void	ft_mantisse_int(char *m, char **str_res, int res, int i)
{
	if (res < 0)
	{
		*str_res = ft_strnew(1);
		(*str_res)[0] = '0';
	}
	else
	{
		*str_res = ft_strnew(res + 1);
		(*str_res)[0] = '1';
		while (m[i] != '\0' && (i - 11) <= res)
		{
			(*str_res)[i - 11] = m[i];
			i++;
		}
		while (i - 11 <= res)
		{
			(*str_res)[i - 11] = '0';
			i++;
		}
		*str_res = ft_str_binary_to_nb(*str_res, 1);
	}
}

static char	*ft_deal_mantisse(char *m)
{
	int		i;
	int		res;
	char	*str_res;

	i = 1;
	res = 0;
	while (i < 12)
	{
		if (m[i] == '1')
			res = res + ft_power(2, 11 - i);
		i++;
	}
	if (res == 2047)
	{
		if (ft_check_mantisse(m, i) == 1)
			return (ft_strdup("nan"));
		else
			return (ft_strdup("inf"));
	}
	res = res - 1023;
	ft_mantisse_int(m, &str_res, res, i);
	str_res = ft_strjoin_free(str_res, ".", 1);
	str_res = ft_strjoin_free(str_res, ft_mantisse_float(m, res, i), 0);
	return (str_res);
}

char		*ft_dtoa(double d)
{
	unsigned long int	uli;
	int					i;
	char				*m;
	char				*str_res;

	m = ft_strnew(64);
	uli = *((unsigned long int*)(&d));
	i = 63;
	while (uli)
	{
		if (uli & 1)
			m[i] = '1';
		else
			m[i] = '0';
		i--;
		uli >>= 1;
	}
	while (i >= 0)
		m[i--] = '0';
	str_res = ft_deal_mantisse(m);
	if (m[0] == '1' && str_res[0] != 'n')
		str_res = ft_strjoin_free("-", str_res, 2);
	ft_strdel(&m);
	return (str_res);
}
