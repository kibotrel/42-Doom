/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:23:28 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/24 14:43:30 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			init_portals(t_editor *editor)
{
	editor->portal_points[0].x = -1;
	editor->portal_points[0].y = -1;
	editor->portal_points[1].x = -1;
	editor->portal_points[1].y = -1;
	editor->which_sector = NULL;
	editor->ab = NULL;
	editor->cd = NULL;
}

static void		img_init(t_sdl *sdl)
{
	bmp_to_array("./assets/texture_1.bmp", &sdl->bmp[0][0]);
	bmp_to_array("./assets/texture_2.bmp", &sdl->bmp[0][1]);
	bmp_to_array("./assets/texture_3.bmp", &sdl->bmp[0][2]);
	bmp_to_array("./assets/texture_4.bmp", &sdl->bmp[0][3]);
	bmp_to_array("./assets/object_1.bmp", &sdl->bmp[1][0]);
	bmp_to_array("./assets/object_2.bmp", &sdl->bmp[1][1]);
	bmp_to_array("./assets/object_3.bmp", &sdl->bmp[1][2]);
	bmp_to_array("./assets/object_4.bmp", &sdl->bmp[1][3]);
	bmp_to_array("./assets/enemy_1.bmp", &sdl->bmp[2][0]);
	bmp_to_array("./assets/enemy_2.bmp", &sdl->bmp[2][1]);
	bmp_to_array("./assets/enemy_3.bmp", &sdl->bmp[2][2]);
	bmp_to_array("./assets/enemy_4.bmp", &sdl->bmp[2][3]);
	bmp_to_array("./assets/portal_wall.bmp", &sdl->bmp[3][0]);
	bmp_to_array("./assets/portal_door.bmp", &sdl->bmp[3][1]);
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
	if (!(sdl->font = TTF_OpenFont("assets/font.ttf", 30)))
		clean(edit);
	sdl->color.r = 0xff;
	sdl->color.g = 0xff;
	sdl->color.b = 0xff;
	img_init(sdl);
}

static void		init_chained_list(t_editor *editor)
{
	editor->enemy = NULL;
	editor->sector = NULL;
	editor->vertex = NULL;
	editor->object = NULL;
	editor->portals = NULL;
}

void			init_editor(t_editor *editor)
{
	sdl_init(&editor->sdl, editor);
	editor->dist_grid = 50;
	editor->true_grid = EDIT_W / editor->dist_grid;
	editor->grid = true;
	editor->sett = SECTOR;
	editor->presets = NONE;
	editor->finish = false;
	editor->sect_is_closed = true;
	editor->last_vertex.x = -1;
	editor->last_vertex.y = -1;
	editor->map_save = true;
	editor->player.x = -5;
	editor->player.y = -5;
	editor->player.angle = 90;
	init_chained_list(editor);
	init_portals(editor);
	init_count(&editor->count);
}
