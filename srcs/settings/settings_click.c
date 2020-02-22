/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_click.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:03:15 by lojesu            #+#    #+#             */
/*   Updated: 2020/02/22 18:48:49 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"
#include "settings.h"
#include "libft.h"

static void click_on_off(t_env *env, SDL_Event event, t_vec2d start, int size)
{
    if (event.motion.x <= (start.x + size) * env->data.grid.min.x +
			env->data.grid.min.x && event.motion.x >= (start.x + size) *
			env->data.grid.min.x && event.motion.y >= start.y *
			env->data.grid.min.y && event.motion.y <= start.y *
			env->data.grid.min.y + env->data.grid.min.y)
    {
		draw_on_off(env, v2d(start.x + size, start.y), RESET, HIDE);
		env->setting.true_false = true;
    }
	else if (event.motion.x <= (start.x + size + 2) * env->data.grid.min.x +
			env->data.grid.min.x && event.motion.x >= (start.x + size + 2) *
			env->data.grid.min.x && event.motion.y >= start.y *
			env->data.grid.min.y && event.motion.y <= start.y *
			env->data.grid.min.y + env->data.grid.min.y)
    {
		draw_on_off(env, v2d(start.x + size, start.y), HIDE, RESET);
		env->setting.true_false = false;
    }
}

void        settings_click(t_env *env, SDL_Event event)
{
    click_on_off(env, event, v2d(FOG_START_X, FOG_START_Y), FOG_SIZE);
	env->setting.fog_on_off = env->setting.true_false;
    click_on_off(env, event, v2d(BORDER_START_X, BORDER_START_Y), BORDER_SIZE);
	env->setting.border_on_off = env->setting.true_false;
}
