/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:03:37 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/01 04:22:54 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "structs.h"

char	*txt(char *prefix, char *info, int mode)
{
	char	*string;

	string = ft_strjoin(prefix, info);
	if (mode == 0)
		free(prefix);
	else if (mode == 1)
		free(info);
	else
	{
		free(prefix);
		free(info);
	}
	return (string);
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
