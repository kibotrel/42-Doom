/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:04:00 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/12/12 15:34:05 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	move_in_sector(t_sector **sector, bool way)
{
	t_sector *tmp;

	if (!*sector)
		return ;
	tmp = *sector;
	if (way == true)
	{
		if (tmp->next->next)
			tmp = tmp->next;
	}
	else
	{
		if (tmp->prev)
			tmp = tmp->prev;
	}
	*sector = tmp;
}