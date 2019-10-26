/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:29:45 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/27 00:39:16 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "clean.h"

static void	env_clean(t_env *env)
{
	uint32_t	asset;

	asset = 0;
	while (asset < NB_ASSETS)
	if (env->sdl.bmp[asset++].pixels)
		free(env->sdl.bmp[asset - 1].pixels);
}

void		clean(t_env *env, uint8_t error)
{
	ttf_clean(&env->sdl);
	sdl_clean(&env->sdl);
	env_clean(env);
	error ? ft_print_error(env->error[error], error) : exit(0);
}
