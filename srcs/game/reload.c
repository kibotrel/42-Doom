/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:00:50 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 10:20:29 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	reload(t_env *env)
{
	env->tick.reload.new = SDL_GetTicks();
	if (env->tick.reload.new > env->tick.reload.old + 200)
	{
		if (env->data.ammos < 5 && env->data.magazines)
		{
			env->data.magazines--;
			env->data.ammos = 5;
		}
	}
	env->tick.reload.old = env->tick.reload.new;
}
