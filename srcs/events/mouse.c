/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:51:13 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/18 09:40:18 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "game.h"
#include "menu.h"
#include "editor.h"


void	handle_mousewheel(t_env *env, t_sdl *sdl)
{
	if (env->win == EDITOR)
		editor_mousewheel(&env->editor, sdl->event);
}

void	handle_mouse(t_env *env, t_sdl *sdl)
{
	if (sdl->event.button.button == SDL_BUTTON_LEFT && env->win == MENU)
		menu_click(env, env->data.ui, sdl->event.button.x, sdl->event.button.y);
	else if (sdl->event.button.button == SDL_BUTTON_LEFT && env->win == EDITOR)
		editor_click(&env->editor, sdl->event, env);
	else if (sdl->event.type == SDL_MOUSEWHEEL && env->win == EDITOR)
		editor_mousewheel(&env->editor, sdl->event);
	else if (sdl->event.button.button == SDL_BUTTON_LEFT && env->win == GAME)
		game_click(env, sdl->event.button.x, sdl->event.button.y);
}
