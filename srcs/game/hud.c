/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:32:06 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/27 15:31:01 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "game.h"
#include "clean.h"
#include "libft.h"
#include "setup.h"
#include "utils.h"

//Position
//Gravity
//Viscosity

void	hud(t_env *env)
{
	if (env->data.hud.debug > 0)
		debug_hud(env);
}
