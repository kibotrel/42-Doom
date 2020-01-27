/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:24:32 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/10 15:22:22 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

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

void		rotate_entity(t_entity *entity, bool rotation)
{
	if (!entity)
		return ;
	if (rotation == false)
		entity->angle += 10;
	else
		entity->angle -= 10;
	if (entity->angle >= 361)
		entity->angle = 0;
	else if (entity->angle <= -1)
		entity->angle = 360;
}
