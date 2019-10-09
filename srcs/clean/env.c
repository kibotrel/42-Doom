/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:29:45 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/08 19:34:12 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "doom.h"

static void	env_clean(t_env *env)
{
	if (env->sdl.bmp.pixels)
		free(env->sdl.bmp.pixels);
}

void		clean(t_env *env, int error)
{
	ttf_clean(&env->sdl);
	sdl_clean(&env->sdl);
	env_clean(env);
	ft_print_error(env->error[error], error);
}
