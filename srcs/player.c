/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:16:31 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/12/10 17:55:42 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	rotate_entity(t_entity *entity, bool rotation)
{
	if (!entity)
		return ;
	if (rotation == true)
		entity->angle += 3;
	else
		entity->angle -= 3;
	if (entity->angle >= 361)
		entity->angle = 0;
	else if (entity->angle <= -1)
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
	if (!player)
		return ;
	if (rotation == true)
		player->angle += 3;
	else
		player->angle -= 3;
	if (player->angle >= 361)
		player->angle = 0;
	else if (player->angle <= -1)
		player->angle = 360;
}

void		move_in_entities(t_entity **entity, bool way)
{
	t_entity	*tmp;

	if (!*entity)
		return ;
	tmp = *entity;
	if (way == true)
	{
		if (tmp->next)
			tmp = tmp->next;
	}
	else
	{
		if (tmp->prev)
			tmp = tmp->prev;
	}
	*entity = tmp;
}

void		del_entity(t_entity **entity)
{
	t_entity	*tf;
	t_entity	*tmp;
	t_entity	*tmp2;

	if (*entity == NULL)
		return ;
	tmp = NULL;
	tmp2 = NULL;
	tf = *entity;
	if (tf->prev)
		tmp = tf->prev;
	if (tf->next)
		tmp2 = tf->next;
	free(tf);
	if (tmp)
		tmp->next = tmp2;
	if (tmp2)
		tmp2->prev = tmp;
	if (tmp)
		*entity = tmp;
	else if (tmp2)
		*entity = tmp2;
	else
		*entity = NULL;
}
