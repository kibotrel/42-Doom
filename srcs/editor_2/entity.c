/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:55:17 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/05 15:50:55 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	add_enemy(t_entity *enemy, t_entity *new)
{
	static int	enemy_num = 0;
	t_entity		*prev_enemy;

	new->number = enemy_num++;
	if (enemy == NULL)
		enemy = new;
	else
	{
		prev_enemy = enemy;
		while (prev_enemy->next)
			prev_enemy = prev_enemy->next;
		prev_enemy->next = new;
	}
}

static void	add_object(t_entity *object, t_entity *new)
{
	static int		object_num = 0;
	t_entity		*prev_object;

	new->number = object_num++;
	if (object == NULL)
		object = new;
	else
	{
		prev_object = object;
		while (prev_object->next)
			prev_object = prev_object->next;
		prev_object->next = new;
	}
}

void	place_entity(t_editor *editor, int x, int y, int type)
{
	t_entity	*new_entity;

	new_entity = create_entity(x, y);
	new_entity->sector = is_in_sector(editor, *new_entity);
	if (new_entity->sector != -1)
	{
		if (type == 0)
			add_enemy(editor->enemy, new_entity);
		else if (type == 1)
			add_object(editor->object, new_entity);
	}
}

void	place_player(t_editor *editor, int x, int y)
{
	t_player	player;

	player.x = x;
	player.y = y;
	player.sector = is_in_sector(editor, player);
	if (player.sector != -1)
	{
		editor->player.x = player.x;
		editor->player.y = player.y;
	}
}