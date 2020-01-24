/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:32:06 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/24 15:02:32 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "clean.h"
#include "libft.h"
#include "setup.h"
#include "utils.h"

//Position
//Gravity
//Viscosity

static void	display_info(t_env *env, char *info, t_vec2d pos)
{
	t_vec		p;
	SDL_Rect	where;
	uint32_t	error;
	SDL_Surface	*tmp;

	error = 0;
	if (!info)
		return ;
	TTF_SizeText(env->sdl.font[1], info, &p.x, &p.y);
	where.x = env->data.grid.min.x * pos.x;
	where.y = env->data.grid.min.y * pos.y;
	if (!(tmp = TTF_RenderText_Blended(env->sdl.font[1], info, env->sdl.color)))
		error = E_TTF_RENDER;
	if (!error && SDL_BlitSurface(tmp, 0, env->sdl.screen, &where))
		error = E_SDL_BLIT;
	if (error != E_TTF_RENDER)
		SDL_FreeSurface(tmp);
	if (error)
		clean(env, error);
	free(info);
}

void		hud(t_env *env)
{
	hud_setup(env);
	display_info(env, env->data.hud.fps, v2d(3, 1));
	// display_info(env, env->data.hud.sector, v2d(10,1));
	// display_info(env, "Altitude : ", ft_itoa(env->cam.pos.z), v2d(18,1));
	// display_info(env, env->data.hud.angle, v2d(10,2));
	// if (env->cam.fly > 0)
	// 	display_info(env, "Fly   : ON", v2d(3, 2));
	// else
	// 	display_info(env, "Fly   : OFF", v2d(3, 2));
}
