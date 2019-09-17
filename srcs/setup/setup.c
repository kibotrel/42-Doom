/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:58:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/17 15:11:24 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

void		env_setup(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	env->w = WIN_W;
	env->h = WIN_H;
	env->run = 1;
	env->status = NOTHING;
	error_messages(env);
}
