/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:58:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 14:35:42 by kibotrel         ###   ########.fr       */
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
	env->error[1] = M_FILENAME;
	env->error[2] = M_SDL_INIT;
	env->error[3] = M_SDL_WIN;
	env->error[4] = M_SDL_WINSURF;
	env->error[5] = M_SDL_UPDATE;
	env->error[6] = M_TTF_INIT;
	env->error[7] = M_TTF_FONT;
	env->error[8] = M_TTF_RENDER;
	env->error[9] = M_SDL_BLIT;
	env->error[10] = M_BMP_PARSE;
}

static void	infos_setup(t_env *env)
{
	env->data.ui.y = floor(env->h / RATIO_UI_Y);
	env->data.ui.x = floor(env->w / RATIO_UI_X);
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
