/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:33:18 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 11:23:10 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"

void	menu_click(t_env *env, t_ui ui, int x, int y)
{
	uint8_t	n;
	uint8_t	box;

	n = 1;
	box = 0;
	while (n < 8)
	{
		box++;
		if (y >= ui.min.y * n && y <= ui.min.y * (n + 1)
			&& x >= ui.min.x && x <= ui.max.x)
		{
			env->win = box;
			ft_bzero(env->sdl.screen->pixels, env->data.w_size);
			break ;
		}
		n += 2;
	}
}
