/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:08:44 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/05 13:10:08 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "libft.h"
#include "editor.h"

static t_ed_entity	*create_entity(int x, int y, int type, t_env *env)
{
	t_ed_entity	*entity;

	if (!(entity = (t_ed_entity*)ft_memalloc(sizeof(t_ed_entity))))
		clean(env, E_EDIT_ENTITY);
	entity->x = x;
	entity->y = y;
	entity->type = type;
	entity->angle = 90;
	entity->prev = NULL;
	entity->next = NULL;
	return (entity);
}

static void			add_enemy(t_ed_entity **enemy, t_ed_entity *new,
	t_count *count)
{
	t_ed_entity		*prev_enemy;

	new->number = count->enemy++;
	if (!*enemy)
		*enemy = new;
	else
	{
		prev_enemy = *enemy;
		while (prev_enemy->next)
			prev_enemy = prev_enemy->next;
		new->prev = prev_enemy;
		prev_enemy->next = new;
	}
}

static void			add_object(t_ed_entity **object, t_ed_entity *new,
	t_count *count)
{
	t_ed_entity		*prev_object;

	new->number = count->object++;
	if (!*object)
		*object = new;
	else
	{
		prev_object = *object;
		while (prev_object->next)
			prev_object = prev_object->next;
		new->prev = prev_object;
		prev_object->next = new;
	}
}

void				place_entity(t_env *env, int x, int y, int type)
{
	t_ed_entity	*new_entity;
	t_vertex	check_sector;

	new_entity = create_entity(x, y, 0, env);
	check_sector.x = x;
	check_sector.y = y;
	new_entity->sector = is_in_sector(&env->editor, check_sector);
	new_entity->x = (x / env->editor.true_grid) * env->editor.true_grid;
	new_entity->y = (y / env->editor.true_grid) * env->editor.true_grid;
	if (new_entity->sector != -1)
	{
		if (type == 0)
			add_enemy(&env->editor.enemy, new_entity, &env->editor.count);
		else if (type == 1)
			add_object(&env->editor.object, new_entity, &env->editor.count);
	}
}

void				place_player(t_editor *editor, int x, int y)
{
	t_ed_player	player;
	t_vertex	check_sector;

	player.x = (x / editor->true_grid) * editor->true_grid;
	player.y = (y / editor->true_grid) * editor->true_grid;
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
