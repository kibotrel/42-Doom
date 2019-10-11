/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:47:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/11 13:16:16 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "env.h"
#include "doom.h"

void	update_position(t_env *env)
{
	draw_pixel(env, env->sdl.screen, env->player.position, 0);
	if (env->input[SDL_SCANCODE_W] && env->player.position.y > env->vertex[0].y + 1)
		env->player.position.y -= 1;
	if (env->input[SDL_SCANCODE_A] && env->player.position.x > env->vertex[0].x + 1)
		env->player.position.x -= 1;
	if (env->input[SDL_SCANCODE_S] && env->player.position.y < env->vertex[2].y - 1)
		env->player.position.y += 1;
	if (env->input[SDL_SCANCODE_D] && env->player.position.x < env->vertex[1].x - 1)
		env->player.position.x += 1;
	draw_pixel(env, env->sdl.screen, env->player.position, RED);
}
