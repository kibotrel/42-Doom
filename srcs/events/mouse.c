/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:51:13 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/27 14:23:46 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "menu.h"
#include "editor.h"

void	handle_mouse(t_env *env, t_sdl *sdl)
{
	if (sdl->event.button.button == SDL_BUTTON_LEFT && env->win == MENU)
		menu_click(env, env->data.ui, sdl->event.button.x, sdl->event.button.y);
	if (sdl->event.button.button == SDL_BUTTON_LEFT && env->win == EDITOR)
		editor_click(&env->editor, sdl->event);
	if(sdl->event.type == SDL_MOUSEWHEEL && env->win == EDITOR)
		editor_mousewheel(&env->editor, sdl->event);
}
