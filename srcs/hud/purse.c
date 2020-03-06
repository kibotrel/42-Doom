/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 09:02:51 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 10:23:01 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static void	update_coin_frame(t_env *env)
{
	env->tick.purse.new = SDL_GetTicks();
	if (env->tick.purse.new > env->tick.purse.old + 160)
	{
		env->data.hud.coin.frame = (env->data.hud.coin.frame + 1) % 6;
		env->tick.purse.old = env->tick.purse.new;
	}
}

void		purse(t_env *env)
{
	int		size;
	t_pos	shift;
	t_pos	vertex[2];

	size = (env->h <= 768 ? 55 : 54);
	vertex[0] = p2d(48, 0, env->data.grid.min.x, 0);
	vertex[1] = p2d(env->w, 4, 1, env->data.grid.min.y);
	update_coin_frame(env);
	blur_area(env, vertex[0], vertex[1]);
	shift.x = env->data.grid.min.x * size;
	shift.y = env->data.grid.min.y * 3;
	draw_asset(env, env->sdl.bmp[COIN], shift, &env->data.hud.coin);
	info(env, ft_itoa(env->data.money), v2d(51.25, 1.5), 1);
}
