/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/27 05:18:13 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "env.h"
#include "core.h"
#include "libft.h"


static t_pos	pos(uin32_t x, uint32_t y)
{
	t_pos		pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

static void		temporary_setup(t_env *env)
{
	uint32_t	i;

	i = 0;
	ft_bzero(&env->cam, sizeof(t_cam));
	env->setup = 1;
	env->zones = 1; // FROM PARSING
	env->cam.angle = 0.0; // FROM PARSING
	env->cam.cos = cos(env->cam.angle);
	env->cam.sin = sin(env->cam.angle);
	env->cam.pos.x = 3.0; // FROM PARSING
	env->cam.pos.y = 3.0; // FROM PARSING
	env->cam.sector = 0; // FROM PARSING
	env->sector = (t_sector*)malloc(sizeof(t_sector))
	env->sector[0] = malloc(sizeof(t_sector));
	env->sector[0].points = 4; //FROM PARSING
	env->sector[0].vertex = (t_pos*)malloc(sizeof(t_pos) * 4)
	while (i < 3)
		env->sector[0].vertex[i++] = malloc(sizeof(t_pos));
	}
	env->sector[0].vertex[0] = pos(0, 0);
	env->sector[0].vertex[1] = pos(5, 0);
	env->sector[0].vertex[2] = pos(5, 5);
	env->sector[0].vertex[3] = pos(0, 5);

}


void			game(t_env *env)
{
	if (!env->setup)
	{
		SDL_SetWindowTitle(env->sdl.win, TITLE_GAME);
		temporary_setup(env);
	}
}
