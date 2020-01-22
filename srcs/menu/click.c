/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:33:18 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/22 15:28:08 by kibotrel         ###   ########.fr       */
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
			selector(env);
			break ;
		}
		n += 2;
	}
}
