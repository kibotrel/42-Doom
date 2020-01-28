/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:18 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/28 16:04:41 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "libft.h"
#include "setup.h"
#include "utils.h"

static void	sdl_setup(t_env *env, t_sdl *sdl)
{
	int32_t		config;
	uint32_t	asset;
	t_pos		p;

	p.x = env->w;
	p.y = env->h;
	asset = -1;
	config = SDL_WINDOWPOS_CENTERED;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		clean(env, E_SDL_INIT);
	if (!(sdl->win = SDL_CreateWindow("", config, config, p.x, p.y, 0)))
		clean(env, E_SDL_WIN);
	if (!(sdl->screen = SDL_GetWindowSurface(sdl->win)))
		clean(env, E_SDL_WINSURF);
	while (++asset < NB_ASSETS)
		if (bmp_to_array(env->asset[asset], &sdl->bmp[asset]))
			clean(env, E_BMP_PARSE);
	env->data.w_size = sdl->screen->h * sdl->screen->pitch;
}

static void	ttf_setup(t_env *env, t_sdl *sdl)
{
	if (TTF_Init())
		clean(env, E_TTF_INIT);
	if (!(sdl->font = TTF_OpenFont("assets/atlas.ttf", env->data.f_size)))
		clean(env, E_TTF_FONT);
	if (!(sdl->editor = TTF_OpenFont("assets/font.ttf", 30)))
		clean(env, E_TTF_FONT);
	police_color(&sdl->color, 0xFF, 0xFF, 0xFF);
}

void		graphic_setup(t_env *env, t_sdl *sdl)
{
	ft_bzero(sdl, sizeof(t_sdl));
	sdl_setup(env, sdl);
	ttf_setup(env, sdl);
}
