/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:22:32 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/10/17 14:30:24 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

void	write_player(t_editor *edit, int fd)
{	
	ft_putstr_fd("player x ", fd);
	if (edit->player.number == 1)
	{
		ft_putnbr_fd(edit->player.x, fd);
		ft_putstr_fd(" y ", fd);
		ft_putnbr_fd(edit->player.y, fd);
	}
	else
	{
		ft_putnbr_fd(0, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(0, fd);
	}
	ft_putstr_fd("\n\n", fd);
}

void	place_player(t_editor **edit, int x, int y)
{
	t_vertex	player;
	int			player_sector;

	player.x = x;
	player.y = y;	
	player_sector = is_in_sector((*edit), player);
	if (player_sector != -1)
	{
		if ((*edit)->player.number == 1)
			print_vertex((*edit)->sdl, &(*edit)->player, 0x000000);
		(*edit)->player.x = player.x;
		(*edit)->player.y = player.y;
		(*edit)->player.number = 1;
	}
}

