/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:26:14 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/23 17:27:24 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	editor_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_BACKSPACE])
		env->win = MENU;
}
