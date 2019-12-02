/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:16:31 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/12/02 11:18:16 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	rotate_entity(t_entity *entity, bool rotation)
{
	if (rotation == true)
		++entity->angle;
	else
		--entity->angle;
	if (entity->angle == 361)
		entity->angle = 0;
	else if (entity->angle == -1)
		entity->angle = 360;
}

void	delete_player(t_player *player)
{
	player->x = -1;
	player->y = -1;
	player->angle = 90;
	player->sector = -1;
}

void rotate_player(t_player *player, bool rotation)
{
	if (rotation == true)
		++player->angle;
	else
		--player->angle;
	if (player->angle == 361)
		player->angle = 0;
	else if (player->angle == -1)
		player->angle = 360;
}

t_entity	*move_in_entities(t_entity *entity, bool way)
{
	if (way == true)
	{
		if (entity->next)
			return (entity->next);
		return (entity);
	}
	else
	{
		if (entity->prev)
			return (entity->prev);
		return (entity);		
	}
}