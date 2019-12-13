/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:44:48 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/12/13 09:07:19 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

static void	print_more_minus(t_sdl *sdl)
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
	char	*print;

	if (presets == SECTOR_FLOOR)
		print = ft_itoa(sector->h_floor);
	else if (presets == SECTOR_CEIL)
		print = ft_itoa(sector->h_ceil);
	else if (presets == SECTOR_TEXT)
		print = ft_itoa(sector->texture);
	else
		return ;
	where.x = 1510;
	where.y = 50;
	tmp = TTF_RenderText_Solid(sdl->font, print, sdl->color);
	SDL_BlitSurface(tmp, 0, sdl->surf, &where);
	print_more_minus(sdl);
}

static void	print_entity_value(t_sdl *sdl, t_entity *to_print, t_presets presets)
{
	SDL_Rect	where;
	SDL_Surface	*tmp;
	char	*print;

	if (presets == ENTITY_TYPE && to_print)
		print = ft_itoa(to_print->type);
	else
		return ;
	where.x = 1510;
	where.y = 50;
	tmp = TTF_RenderText_Solid(sdl->font, print, sdl->color);
	SDL_BlitSurface(tmp, 0, sdl->surf, &where);
	print_more_minus(sdl);
}

void	print_param_to_screen(t_sdl *sdl, t_settings sett, t_editor *editor)
{
	SDL_Rect	where;
	SDL_Surface	*tmp;
	int			i;
	char	*first_params[5] = {"Sector", "Player", "Enemy", "Object", "Portal"};
	char	*number[5] = {"1", "2", "3", "4", "5"};
	
	i = 0;
	where.x = 1410;
	where.y = 155;
	while (i < 5)
	{
		tmp = TTF_RenderText_Solid(sdl->font, first_params[i], sdl->color);
		SDL_BlitSurface(tmp, 0, sdl->surf, &where);
		tmp = TTF_RenderText_Solid(sdl->font, number[i], sdl->color);
		where.x -= 45;
		SDL_BlitSurface(tmp, 0, sdl->surf, &where);
		where.x += 45;
		where.y = where.y + 100;
		i++;
	}
	if (sett == SECTOR && editor->presets != NONE)
		print_sector_values(sdl, editor->sector, editor->presets);
	else if (sett == OBJECT)
		print_entity_value(sdl, editor->object, editor->presets);
	else if (sett == ENEMY)
		print_entity_value(sdl, editor->enemy, editor->presets);
}

void	print_param_in_param(t_sdl *sdl, t_settings sett)
{
	char 	*tab[3][6] = {{"Prev", "Next", "Floor", "Roof", "Text"}, {"R.Left", "R.Right", "Del"},{"Prev", "Next", "R.Left", "R.Right", "Del", "Type"}};
	SDL_Rect	where;
	SDL_Surface	*tmp;
	int 		i;
	int			max;
	int			j;

	if (sett == PORTAL)
		return ;
	i = 0;
	if (sett == SECTOR || sett == PLAYER)
	{
		if (sett == SECTOR)
		{
			max = 5;
			j = 0;
		}
		else
		{
			max = 3;
			j = 1;
		}
	}
	else
		j = 2;
	max = 6;
	where.x = 1610;
	where.y = 155;
	while (i < max)
	{
		tmp = TTF_RenderText_Solid(sdl->font, tab[j][i], sdl->color);
		SDL_BlitSurface(tmp, 0, sdl->surf, &where);
		where.y = where.y + 100;
		i++;
	}
}
