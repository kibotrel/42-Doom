/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:18 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 14:20:50 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "SDL_ttf.h"
#include "bmp.h"
#include "libft.h"
#include "doom.h"

static void	sdl_setup(t_env *env, t_sdl *sdl)
{
	int	x;
	int	y;
	int	config;

	x = env->w;
	y = env->h;
	config = SDL_WINDOWPOS_CENTERED;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		clean(env, E_SDL_INIT);
	if (!(sdl->win = SDL_CreateWindow("", config, config, x, y, 0)))
		clean(env, E_SDL_WIN);
	if (!(sdl->screen = SDL_GetWindowSurface(sdl->win)))
		clean(env, E_SDL_WINSURF);
	if (env->h == 1080 && bmp_to_array("assets/menu_1080.bmp", &sdl->bmp))
		clean(env, E_BMP_PARSE);
	if (env->h == 720 && bmp_to_array("assets/menu_720.bmp", &sdl->bmp))
		clean(env, E_BMP_PARSE);
}

static void	ttf_setup(t_env *env, t_sdl *sdl)
{
	if (TTF_Init())
		clean(env, E_TTF_INIT);
	if (!(sdl->font = TTF_OpenFont("assets/atlas.ttf", env->data.f_size)))
		clean(env, E_TTF_FONT);
	police_color(&sdl->color, 255, 255, 255);
}

void		graphic_setup(t_env *env, t_sdl *sdl)
{
	ft_bzero(sdl, sizeof(t_sdl));
	sdl_setup(env, sdl);
	ttf_setup(env, sdl);
}
