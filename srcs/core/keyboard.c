/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:23:52 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/16 16:47:25 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "doom.h"

void	handle_keyboard(t_env *env, t_sdl *sdl)
{
	if (sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		env->run = 0;
}
