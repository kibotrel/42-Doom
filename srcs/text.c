/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:44:48 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/14 15:27:31 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

static char const	*g_first_params[6] = {
	"Sector", "Player", "Enemy", "Object", "Portal", "Clear"
};

static char const	*g_number[5] = {
	"1", "2", "3", "4", "5"
};

static char const	*g_tab[4][6] = {
	{"Select.", "Floor", "Roof", "Text", "Grav", "Visc"},
	{"Rotate", "Del"},
	{"Select.", "Rotate", "Del", "Type"},
	{"Select.", "Type"}
};

void		print_more_minus(t_sdl *sdl)
{
	SDL_Rect	where;
	SDL_Surface	*tmp;

	where.x = 1420;
	where.y = 50;
	tmp = TTF_RenderText_Solid(sdl->font, "-", sdl->color);
	SDL_BlitSurface(tmp, 0, sdl->surf, &where);
	where.x = 1615;
	where.y = 55;
	tmp = TTF_RenderText_Solid(sdl->font, "+", sdl->color);
	SDL_BlitSurface(tmp, 0, sdl->surf, &where);
}

static void	print_sector_values(t_sdl *sdl, t_sector *sector, t_presets presets)
{
	SDL_Rect	where;
	SDL_Surface	*tmp;
	char		*print;

	where.x = 1510;
	if (presets == SECTOR_FLOOR)
		print = ft_itoa(sector->h_floor);
	else if (presets == SECTOR_CEIL)
		print = ft_itoa(sector->h_ceil);
	else if (presets == SECTOR_GRAV)
		print = ft_itoa(sector->gravity);
	else if (presets == SECTOR_VISC)
		print = ft_itoa(sector->viscosity);
	else if (presets == ENTITY_MOVE || presets == SECTOR_MOVE || presets == PORTAL_MOVE)
	{
		print = "Prev./Next";
		where.x = 1453;
	}
	else if (presets == PLAYER_ROTATE || presets == ENTITY_ROTATE)
	{
		print = "Left/Right";
		where.x = 1455;
	}
	else
		print = "";
	where.y = 50;
	tmp = TTF_RenderText_Solid(sdl->font, print, sdl->color);
	SDL_BlitSurface(tmp, 0, sdl->surf, &where);
	print_more_minus(sdl);
}

void		print_param_to_screen(t_sdl *sdl, t_settings sett, t_editor *editor)
{
	SDL_Rect	where;
	SDL_Surface	*tmp;
	int			i;

	i = 0;
	where.x = 1410;
	where.y = 155;
	while (i < 5)
	{
		tmp = TTF_RenderText_Solid(sdl->font, g_first_params[i], sdl->color);
		SDL_BlitSurface(tmp, 0, sdl->surf, &where);
		tmp = TTF_RenderText_Solid(sdl->font, g_number[i], sdl->color);
		where.x -= 45;
		SDL_BlitSurface(tmp, 0, sdl->surf, &where);
		where.x += 45;
		where.y = where.y + 100;
		i++;
	}
	where.x = 1335;
	where.y = 665;
	tmp = TTF_RenderText_Solid(sdl->font, g_first_params[5], sdl->color);
	SDL_BlitSurface(tmp, 0, sdl->surf, &where);
	if (editor->presets != NONE)
		print_sector_values(sdl, editor->sector, editor->presets);
	if ((editor->presets == ENTITY_TYPE && ((sett == ENEMY && editor->enemy)
					|| (sett == OBJECT && editor->object)))
			|| editor->presets == SECTOR_TEXT || (editor->presets == PORTAL_TYPE && editor->portals))
		print_params_image(editor, editor->presets, editor->sett);
}

void		print_param_in_param(t_sdl *sdl, t_settings sett)
{
	SDL_Rect	where;
	SDL_Surface	*tmp;
	int			i;
	int			j;

	if (sett == PORTAL)
		j = 3;
	else if (sett == SECTOR || sett == PLAYER)
		j = (sett == SECTOR) ? 0 : 1;
	else
		j = 2;
	i = -1;
	where.x = 1610;
	where.y = 155;
	while (++i < 6 && g_tab[j][i])
	{
		tmp = TTF_RenderText_Solid(sdl->font, g_tab[j][i], sdl->color);
		SDL_BlitSurface(tmp, 0, sdl->surf, &where);
		where.y = where.y + 100;
	}
}
