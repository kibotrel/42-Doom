/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:47:35 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/07 14:12:13 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "libft.h"

// PENSER AUX FREES ET METTRE LES FONCTIONS POSSIBLES EN STATIC

void			draw_bmp(int x, int y, t_sdl *sdl, t_bmp img)
{
	int	x_tmp;

	x_tmp = x;
	while (++y < img.height)
	{
		x = x_tmp;
		while (++x < img.width)
		{
			if (x < EDIT_W && y < WIN_H)
				put_pixel(sdl->surf, x, y, img.pixels[x + y * img.width]);
		}
	}
}

static void		sdl_init(t_sdl *sdl, t_editor *edit)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		clean(edit);
	sdl->win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, EDIT_W + MENU_W, WIN_H, 0);
	if (sdl->win == NULL)
		clean(edit);
	sdl->surf = SDL_GetWindowSurface(sdl->win);
	if (sdl->surf == NULL)
		clean(edit);
	if (TTF_Init() != 0)
		clean(edit);
	if (!(sdl->font = TTF_OpenFont("map/font.ttf", 30)))
		clean(edit);
	sdl->color.r = 0xff;
	sdl->color.g = 0xff;
	sdl->color.b = 0xff;
	ft_bzero(sdl->assets, sizeof(char*));
	sdl->assets[0] = "./map/1.bmp";
	sdl->assets[1] = "./map/2.bmp";
	sdl->assets[2] = "./map/3.bmp";
	bmp_to_array(sdl->assets[0], &sdl->bmp[0]);
	bmp_to_array(sdl->assets[1], &sdl->bmp[1]);
	bmp_to_array(sdl->assets[2], &sdl->bmp[2]);
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
	sdl_init(&editor->sdl, editor);
	editor->dist_grid = EDIT_W / 50;
	editor->sett = SECTOR;
	editor->presets = NONE;
	editor->finish = false;
	editor->sect_is_closed = false;
	editor->last_vertex.x = -1;
	editor->last_vertex.y = -1;
	editor->map_save = true;
	editor->player.x = -5;
	editor->player.y = -5;
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
