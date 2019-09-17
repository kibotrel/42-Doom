/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:18 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/17 10:12:24 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "env.h"
#include "doom.h"

void	graphic_setup(t_env *env, t_sdl *sdl)
{
	int	w;
	int	x;
	int	y;

	w = SDL_WINDOWPOS_CENTERED;
	x = env->w;
	y = env->h;
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO))
		env->status = E_SDL_INIT;
	if (!env->status && !(sdl->win = SDL_CreateWindow("", w, w, x, y, 0)))
		env->status = E_SDL_WIN;
	if (!env->status && !(sdl->screen = SDL_GetWindowSurface(sdl->win)))
		env->status = E_SDL_WINSURF;
	if (env->status)
	{
		clean_sdl(sdl);
		ft_print_error(env->error[env->status], env->status);
	}
}
