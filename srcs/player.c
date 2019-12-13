/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:16:31 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/12/13 10:10:39 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	delete_player(t_player *player)
{
	player->x = -5;
	player->y = -5;
	player->angle = 90;
	player->sector = -1;
}

void	rotate_player(t_player *player, bool rotation)
{
	if (!player)
		return ;
	if (rotation == true)
		player->angle += 10;
	else
		player->angle -= 10;
	if (player->angle >= 361)
		player->angle = 0;
	else if (player->angle <= -1)
		player->angle = 360;
}
