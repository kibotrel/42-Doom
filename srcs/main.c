/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:47:35 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/06 08:29:12 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "libft.h"

// PENSER AUX FREES ET METTRE LES FONCTIONS POSSIBLES EN STATIC

static void	sdl_init(t_sdl *sdl)
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

static void	init_editor(t_editor *editor)
{
	sdl_init(&editor->sdl);
	editor->dist_grid = WIN_W / 50;
	editor->sett = SECTOR;
	editor->finish = 1;
	editor->last_vertex.x = -1;
	editor->last_vertex.y = -1;
	editor->map_save = 2;
	editor->player.x = -1;
	editor->player.y = -1;
	editor->player.angle = 90;
	init_portals(editor);
}

int		main(void)
{
	t_editor	editor;

	init_editor(&editor);
	events(&editor);
	return (1);
}