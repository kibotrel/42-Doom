/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:27:12 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/06 10:34:31 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	settings_keyboard(t_env *env)
{
	if (env->input[SDL_SCANCODE_BACKSPACE])
	{
		env->setup = 0;
		env->win = MENU;
		SDL_ShowCursor(SDL_ENABLE);
		return ;
	}
}
