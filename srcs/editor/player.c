/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:22:32 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/09/17 12:02:46 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

void	write_player(t_editor *edit, int fd)
{	
	ft_putstr_fd("player\ty ", fd);
	if (edit->player.number == 1)
	{
		ft_putnbr_fd(edit->player.y, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(edit->player.x, fd);
	}
	else
	{
		ft_putnbr_fd(0, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(0, fd);
	}
	ft_putstr_fd("\n\n", fd);
}

void	print_player(t_editor *edit, int color)
{
	if (edit->player.number != 0)
	{
		put_pixel(edit->sdl, edit->player.x, edit->player.y, color);
		put_pixel(edit->sdl, edit->player.x + 1, edit->player.y, color);
		put_pixel(edit->sdl, edit->player.x, edit->player.y + 1, color);
		put_pixel(edit->sdl, edit->player.x - 1, edit->player.y, color);
		put_pixel(edit->sdl, edit->player.x, edit->player.y - 1, color);
	}
}

void	place_player(t_editor *edit, int x, int y)
{
	if (edit->player.number == 1)
		print_player(edit, 0x000000);
	edit->player.x = x;
	edit->player.y = y;
	edit->player.number = 1;
}

