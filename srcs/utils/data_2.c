/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:03:37 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 10:47:43 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "utils.h"

char	*txt(char *prefix, char *info, int mode)
{
	char	*string;

	string = ft_strjoin(prefix, info);
	if (mode == 0)
		free(prefix);
	else if (mode == 1)
		free(info);
	else if (mode > 1)
	{
		free(prefix);
		free(info);
	}
	return (string);
}

char	*precision(double value, int precision)
{
	char			*str;
	char			*tmp;
	unsigned int	i;
	unsigned int	max;
	unsigned int	int_part;

	if (value == floor(value) || precision == 0)
		return (ft_itoa((int)value));
	tmp = ft_dtoa(value);
	int_part = ft_numlen((floor(value)), 10);
	if (!(str = malloc(sizeof(char) * int_part + precision + 2)))
		return (NULL);
	i = 0;
	max = int_part + precision + 1;
	while (i < max)
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
	free(tmp);
	return (str);
}

void	update_velocity(t_vec3d *v, t_vec2d *vel)
{
	if (v->x > -0.01 && v->x < 0.01)
	{
		v->x = 0;
		vel->x = 0;
	}
	if (v->y > -0.01 && v->y < 0.01)
	{
		v->y = 0;
		vel->y = 0;
	}
}

void	dimensions(char **str, double x, double y, double z)
{
	*str = txt(precision(x, 2), " / ", 0);
	*str = txt(*str, precision(y, 2), 2);
	*str = txt(*str, " / ", 0);
	*str = txt(*str, precision(z, 2), 2);
}

double	inter(double value, double min, double max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	else
		return (value);
}
