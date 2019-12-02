/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:47:35 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/12/02 10:19:39 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "libft.h"

// PENSER AUX FREES ET METTRE LES FONCTIONS POSSIBLES EN STATIC

static void		sdl_init(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit(1);
	sdl->win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, EDIT_W + MENU_W, WIN_H, 0);
	if (sdl->win == NULL)
		exit(1);
	sdl->surf = SDL_GetWindowSurface(sdl->win);
	if (sdl->surf == NULL)
		exit(1);
	if (TTF_Init() != 0)
		exit(1);
	if (!(sdl->font = TTF_OpenFont("map/font.ttf", 30)))
		exit(1);
	sdl->color.r = 0xff;
	sdl->color.g = 0xff;
	sdl->color.b = 0xff;
}

static void		init_chained_list(t_editor *editor)
{
	editor->enemy = NULL;
	editor->sector = NULL;
	editor->vertex = NULL;
	editor->object = NULL;
}

static void		init_editor(t_editor *editor)
{
	sdl_init(&editor->sdl);
	editor->dist_grid = EDIT_W / 50;
	editor->sett = SECTOR;
	editor->finish = false;
	editor->last_vertex.x = -1;
	editor->last_vertex.y = -1;
	editor->map_save = true;
	editor->player.x = -1;
	editor->player.y = -1;
	editor->player.angle = 90;
	init_chained_list(editor);
	init_portals(editor);
}

int				main(void)
{
	t_editor	editor;

	init_editor(&editor);
	events(&editor);
	return (1);
}
