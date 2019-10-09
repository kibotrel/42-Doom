/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:34:23 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/09 02:53:24 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "doom.h"

void	menu_hover(t_env *env, t_ui ui, int x, int y)
{
	int	n;
	int	button;

	n = 1;
	button = env->data.ui.button;
	while (n < 8)
	{
		if (y >= ui.min.y * n && y <= ui.min.y * (n + 1)
			&& x >= ui.min.x && x <= ui.max.x)
		{
			draw_button(env, env->data.ui, RED, n);
			police_color(&env->sdl.color, 255, 0, 0);
			text_to_screen(env, &env->sdl, get_string(n), n);
			police_color(&env->sdl.color, 255, 255, 255);
			env->data.ui.button = n;
			return ;
		}
		n += 2;
	}
	if (button)
	{
		draw_button(env, env->data.ui, WHITE, env->data.ui.button);
		text_to_screen(env, &env->sdl, get_string(button), button);
		env->data.ui.button = 0;
	}
}
