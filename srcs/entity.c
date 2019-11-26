/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:55:17 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/26 11:54:28 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

static t_entity		*create_entity(int x, int y, int type)
{
	t_entity	*entity;

	if (!(entity = (t_entity*)ft_memalloc(sizeof(t_entity))))
		exit(1);
	entity->x = x;
	entity->y = y;
	entity->type = type;
	return (entity);
}

static void			add_enemy(t_entity **enemy, t_entity *new)
{
	static int		enemy_num = 0;
	t_entity		*prev_enemy;

	new->number = enemy_num++;
	if (!*enemy)
		*enemy = new;
	else
	{
		prev_enemy = *enemy;
		while (prev_enemy->next)
			prev_enemy = prev_enemy->next;
		prev_enemy->next = new;
	}
}

static void			add_object(t_entity **object, t_entity *new)
{
	static int		object_num = 0;
	t_entity		*prev_object;

	new->number = object_num++;
	if (!*object)
		*object = new;
	else
	{
		prev_object = *object;
		while (prev_object->next)
			prev_object = prev_object->next;
		prev_object->next = new;
	}
}

void				place_entity(t_editor *editor, int x, int y, int type)
{
	t_entity	*new_entity;
	t_vertex	check_sector;

	new_entity = create_entity(x, y, 1);
	check_sector.x = x;
	check_sector.y = y;
	new_entity->sector = is_in_sector(editor, check_sector);
	if (new_entity->sector != -1)
	{
		if (type == 0)
			add_enemy(&editor->enemy, new_entity);
		else if (type == 1)
			add_object(&editor->object, new_entity);
	}
}

void				place_player(t_editor *editor, int x, int y)
{
	t_player	player;
	t_vertex	check_sector;

	player.x = x;
	player.y = y;
	check_sector.x = x;
	check_sector.y = y;
	player.sector = is_in_sector(editor, check_sector);
	if (player.sector != -1)
	{
		editor->player.x = player.x;
		editor->player.y = player.y;
		editor->player.sector = player.sector;
	}
}
