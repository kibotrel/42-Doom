/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 09:02:51 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/14 11:19:48 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static void	draw_ast(t_env *env, t_bmp asset, t_pos shift, int32_t frame)
{
	t_pos		p;
	t_pos		px;
	t_pos		min;
	uint32_t	pos;


	p.y = -1;
	min.y = shift.y - asset.height;
	while (++p.y < asset.height)
	{
		p.x = -1;
		px.y = min.y + p.y;
		while (++p.x < 48)
		{
			px.x = shift.x + p.x;
			pos = p.x + (frame * 48) + p.y * asset.width;
			if (asset.pixels[pos] != 41704)
				draw_pixel(env, env->sdl.screen, px, asset.pixels[pos]);
		}
	}
}

static void	update_coin_frame(t_env *env)
{
	env->tick.purse.new = SDL_GetTicks();
	if (env->tick.purse.new > env->tick.purse.old + 160)
	{
		env->data.hud.coin_shift = (env->data.hud.coin_shift + 1) % 6;
		env->tick.purse.old = env->tick.purse.new;
	}
}

void		purse(t_env *env)
{
	t_pos	shift;
	t_pos	vertex[2];

	vertex[0] = p2d(48, 0, env->data.grid.min.x, 0);
	vertex[1] = p2d(env->w, 4, 1, env->data.grid.min.y);
	update_coin_frame(env);
	blur_area(env, vertex[0], vertex[1]);
	shift.x = env->data.grid.min.x * 55;
	shift.y = env->data.grid.min.y * 3;
	draw_ast(env, env->sdl.bmp[COIN], shift, env->data.hud.coin_shift);
	info(env, ft_itoa(env->data.money), v2d(51.25, 1.5), 1);
}
