/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:45:57 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/17 18:09:06 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "env.h"
#include "doom.h"

void	menu(t_env *env)
{
	SDL_SetWindowTitle(env->sdl.win, TITLE_MENU);
	draw_buttons(env->data.ui, &env->sdl, WHITE);
}
