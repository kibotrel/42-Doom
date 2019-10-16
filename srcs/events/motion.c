/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:41:08 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/08 19:52:07 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	handle_motion(t_env *env, t_sdl *sdl)
{
	if (env->win == MENU)
		menu_hover(env, env->data.ui, sdl->event.motion.x, sdl->event.motion.y);
}