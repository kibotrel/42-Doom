/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:32:06 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/04 04:32:09 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "game.h"
#include "clean.h"
#include "libft.h"
#include "setup.h"
#include "utils.h"

void	hud(t_env *env)
{
	if (env->data.hud.debug > 0)
		debug_hud(env);
	crosshair(env);
}
