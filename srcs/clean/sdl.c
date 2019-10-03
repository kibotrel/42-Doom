/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:05 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 10:27:21 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "SDL_ttf.h"
#include "libft.h"
#include "doom.h"

static void	ttf_clean(t_sdl *sdl)
{
	if (sdl->font)
		TTF_CloseFont(sdl->font);
	TTF_Quit();
}

static void	sdl_clean(t_sdl *sdl)
{
	if (sdl->screen)
		SDL_FreeSurface(sdl->screen);
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
	SDL_Quit();
}

void		clean(t_env *env, int error)
{
	ttf_clean(&env->sdl);
	sdl_clean(&env->sdl);
	if (env->sdl.bmp.pixels)
		free(env->sdl.bmp.pixels);
	ft_print_error(env->error[error], error);
}
