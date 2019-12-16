/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:41:08 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/16 11:35:02 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h" // Need to fix a bug with this include

void	handle_motion(t_env *env, t_sdl *sdl)
{
	if (env->win == MENU)
		menu_hover(env, env->data.ui, sdl->event.motion.x, sdl->event.motion.y);
	if (env->win == GAME)
		cam_motion(env, &env->cam, sdl->event.motion.x, sdl->event.motion.y);
}
