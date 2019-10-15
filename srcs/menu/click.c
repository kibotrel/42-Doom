/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:33:18 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 19:30:18 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"

void	menu_click(t_env *env, t_ui ui, int x, int y)
{
	int	n;
	int	box;
	int	size;

	n = 1;
	box = 0;
	while (n < 8)
	{
		box++;
		if (y >= ui.min.y * n && y <= ui.min.y * (n + 1)
			&& x >= ui.min.x && x <= ui.max.x)
		{
			env->win = box;
			size = env->sdl.screen->h * env->sdl.screen->pitch;
			ft_bzero(env->sdl.screen->pixels, size);
			selector(env);
			break ;
		}
		n += 2;
	}
}
