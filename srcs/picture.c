/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:09:35 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/08 11:22:24 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	print_picture(t_editor *editor, int x, int y, t_bmp img)
{
	int xa;
	int	ya;

	ya = y - 1;
	while (++ya < img.height)
	{
		xa = x - 1;
		while (xa < img.width)
			put_pixel(editor->surf, xa, ya, img.pixels[xa + ya * img.width]);
	}
}
