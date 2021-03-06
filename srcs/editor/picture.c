/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:32:34 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/05 14:44:57 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	print_picture(t_sdl *sdl, int x, int y, t_bmp img)
{
	int xa;
	int	ya;

	ya = 0;
	while (++ya < img.height)
	{
		xa = 0;
		while (++xa < img.width)
		{
			if (xa + x < 1780 && ya + y < 820)
				put_pixel(sdl->screen, xa + x, ya + y,
					img.pixels[xa + ya * img.width]);
		}
	}
}

void		print_params_image(t_editor *edit, t_presets presets,
	t_settings sett, t_env *env)
{
	int		i;
	int		j;

	if (!edit->sector)
		return ;
	if (sett == SECTOR && presets == SECTOR_TEXT)
	{
		i = ED_TEXT_1;
		j = edit->sector->texture;
	}
	else
		return ;
	rectangle(init_vertex(1491, 41), init_vertex(1557, 106), 0xffffff,
			env->sdl.screen);
	print_picture(&env->sdl, 1492, 42, env->sdl.bmp[i + j]);
	display_text(WHITE, init_vertex(1420, 50), "-", env);
	display_text(WHITE, init_vertex(1615, 55), "+", env);
}
