/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:47:35 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/10/21 14:58:58 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor_2.h"
#include "libft.h"

void	sdl_init(t_sdl *sdl)
{
	SDL_Init(SDL_INIT_VIDEO);
	sdl->win = SDL_CreateWindow("DNME", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, 0);
	if (sdl->win == NULL)
		exit(1);
	sdl->surf = SDL_GetWindowSurface(sdl->win);
	if (sdl->surf == NULL)
		exit(1);		
}

void	init_editor(t_editor *editor)
{
	sdl_init(&editor->sdl);
	editor->dist_grid = WIN_W / 50;
	editor->sett = vertex;
	
}

int		main(void)
{
	t_editor	editor;

	init_editor(&editor);
	
}