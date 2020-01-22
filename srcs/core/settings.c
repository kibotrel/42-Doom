/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:38:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 19:28:02 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"

void	settings(t_env *env)
{
	SDL_SetWindowTitle(env->sdl.win, TITLE_SETTINGS);
}
