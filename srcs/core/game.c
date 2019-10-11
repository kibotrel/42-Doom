/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/10 19:04:58 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "env.h"
#include "doom.h"

void	game(t_env *env)
{
	int		i = -1;

	while (++i < 4)
		draw_line(env, env->vertex[i], env->vertex[(i + 1) % 4], WHITE);
	draw_pixel(env, env->sdl.screen, env->player.position, RED);
	SDL_SetWindowTitle(env->sdl.win, TITLE_GAME);
}
