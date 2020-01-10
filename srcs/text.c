/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:44:48 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/10 14:56:49 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

static char const	*g_first_params[5] = {
	"Sector", "Player", "Enemy", "Object", "Portal"
};

static char const	*g_number[5] = {
	"1", "2", "3", "4", "5"
};

static char const	*g_tab[3][4] = {
	{"Select.", "Floor", "Roof", "Text"},
	{"Rotate", "Del"},
	{"Select.", "Rotate", "Del", "Type"}
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

	if (presets == SECTOR_FLOOR)
		print = ft_itoa(sector->h_floor);
	else if (presets == SECTOR_CEIL)
		print = ft_itoa(sector->h_ceil);
	where.x = 1510;
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
	if (sett != PORTAL && editor->presets != NONE)
		print_sector_values(sdl, editor->sector, editor->presets);
	if ((editor->presets == ENTITY_TYPE && ((sett == ENEMY && editor->enemy)
			|| (sett == OBJECT && editor->object)))
			|| editor->presets == SECTOR_TEXT)
		print_params_image(editor, editor->presets, editor->sett);
}

void		print_param_in_param(t_sdl *sdl, t_settings sett)
{
	SDL_Rect	where;
	SDL_Surface	*tmp;
	int			i;
	int			max;
	int			j;

	if (sett == PORTAL)
		return ;
	i = -1;
	if (sett == SECTOR || sett == PLAYER)
	{
		j = (sett == SECTOR) ? 0 : 1;
		max = (sett == SECTOR) ? 4 : 3;
	}
	else
		j = 2;
	max = 4;
	where.x = 1610;
	where.y = 155;
	while (++i < max)
	{
		tmp = TTF_RenderText_Solid(sdl->font, g_tab[j][i], sdl->color);
		SDL_BlitSurface(tmp, 0, sdl->surf, &where);
		where.y = where.y + 100;
	}
}
