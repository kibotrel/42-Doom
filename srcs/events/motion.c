/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:41:08 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 12:01:27 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "menu.h"
#include "editor.h"

void	handle_motion(t_env *env, t_sdl *sdl)
{
	if (env->win == MENU)
		menu_hover(env, env->data.ui, sdl->event.motion.x, sdl->event.motion.y);
	else if (env->win == GAME)
		cam_motion(env, &env->cam, sdl->event.motion.x, sdl->event.motion.y);
	if (env->win == EDITOR)
		editor_motion(*sdl, env->editor.sett, env->editor.presets, &env->editor, env);
}
