/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:45:57 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/17 14:35:16 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include <math.h>
#include "env.h"
#include "doom.h"

static void	draw_background(t_env *env, t_sdl *sdl)
{
	int		n;
	t_point	p;
	t_point	base;

	n = 1;
	base.y = floor(env->h / 9);
	base.x = floor(env->w / 3);

	while (n < 8)
	{
		p.y = base.y * n;
		while (p.y <= base.y * (n + 1))
		{
			p.x = base.x - 1;
			while (++p.x <= base.x * 2)
			{
				if (p.y == base.y * n || p.y == base.y * (n + 1))
					draw_pixel(sdl->screen, p.x, p.y, WHITE);
				if (p.x == base.x || p.x == base.x * 2)
					draw_pixel(sdl->screen, p.x, p.y, WHITE);
			}
			p.y++;
		}
		n += 2;
	}
}

void	menu(t_env *env)
{
	SDL_SetWindowTitle(env->sdl.win, TITLE_MENU);
	draw_background(env, &env->sdl);
}
