/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:44:48 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/29 07:58:16 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	print_param_to_screen(t_sdl *sdl)
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
}

void	print_param_in_param(t_sdl *sdl, t_settings sett)
{
	char 	*tab[3][6] = {{"Floor", "Roof", "Text"}, {"R.Left", "R.Right", "Del"},{"Prev", "Next", "R.Left", "R.Right", "Del", "Type"}};
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
			j = 0;
		else
			j = 1;
		max = 3;
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