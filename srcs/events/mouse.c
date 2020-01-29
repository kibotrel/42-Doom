/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:51:13 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 11:53:36 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "menu.h"
#include "editor.h"

void	handle_mouse(t_env *env, t_sdl *sdl)
{
	if (sdl->event.button.button == SDL_BUTTON_LEFT && env->win == MENU)
		menu_click(env, env->data.ui, sdl->event.button.x, sdl->event.button.y);
	else if (sdl->event.button.button == SDL_BUTTON_LEFT && env->win == EDITOR)
		editor_click(&env->editor, sdl->event, env);
	else if(sdl->event.type == SDL_MOUSEWHEEL && env->win == EDITOR)
		editor_mousewheel(&env->editor, sdl->event);
}
