/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:58:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/23 19:08:30 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "env.h"
#include "doom.h"

static void	error_messages(t_env *env)
{
	ft_bzero(env->error, sizeof(char*));
	env->error[0] = "";
	env->error[1] = "\033[31;1mError:\033[0m Incorrect filename (*.data).";
	env->error[2] = "\033[31;1mError:\033[0m Can't init SDL connexion.";
	env->error[3] = "\033[31;1mError:\033[0m Can't create SDL window.";
	env->error[4] = "\033[31;1mError:\033[0m Can't retrieve window's surface.";
	env->error[5] = "\033[31;1mError:\033[0m Can't update the given frame.";
	env->error[6] = "\033[31;1mError:\033[0m Can't init TTF connexion.";
	env->error[7] = "\033[31;1mError:\033[0m Can't load the given font.";
	env->error[8] = "\033[31;1mError:\033[0m Can't write text on SDL_Surface.";
	env->error[9] = "\033[31;1mError:\033[0m Can't blit text with the screen.";
}

static void	infos_setup(t_env *env)
{
	env->data.ui.y = floor(env->h / 9);
	env->data.ui.x = floor(env->w / 3);
	env->data.f_size = floor(env->w * MAX_FONT_SIZE / MAX_WIDTH);
}

void		env_setup(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	env->w = WIN_W;
	env->h = WIN_H;
	error_messages(env);
	infos_setup(env);
}
