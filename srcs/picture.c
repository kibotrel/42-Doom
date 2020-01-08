/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:09:35 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/08 15:19:14 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	print_picture(t_sdl *sdl, int x, int y, t_bmp img)
{
	int xa;
	int	ya;

	ya = 0;
	while (++ya < img.height)
	{
		xa = 0;
		while (++xa < img.width)
		{
			if (xa + x < EDIT_W + MENU_W && ya + y < WIN_H)
				put_pixel(sdl->surf, xa + x, ya + y,
					img.pixels[xa + ya * img.width]);
		}
	}
}

void	print_params_image(t_editor *edit, t_presets presets, t_settings sett)
{
	int		i;
	int		j;

	if (sett == SECTOR && presets == SECTOR_TEXT)
	{
		i = 0;
		j = edit->sector->texture;
	}
	else if (sett == OBJECT && presets == ENTITY_TYPE)
	{
		if (!edit->object)
			return ;
		i = 1;
		j = edit->object->type;
	}
	else if (sett == ENEMY && presets == ENTITY_TYPE)
	{
		if (!edit->enemy)
			return ;
		i = 2;
		j = edit->enemy->type;
	}
	else
		return ;
	print_picture(&edit->sdl, 1475, 30, edit->sdl.bmp[i][j]);
	print_more_minus(&edit->sdl);
}
