/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:55:00 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/26 11:15:10 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

int			is_sector_complete(t_vertex *first, t_vertex *last)
{
	if (!first || !last)
		return (0);
	if (first->x == last->x && first->y == last->y)
		return (1);
	return (0);
}

t_sector	*create_sector(void)
{
	static int	sector_num = 0;
	t_sector	*sect;

	sect = NULL;
	if (!(sect = (t_sector*)ft_memalloc(sizeof(t_sector))))
		exit(1);
	if (sect)
	{
		sect->sector_number = sector_num++;
		sect->is_child = -1;
		sect->h_ceil = 20;
		sect->h_floor = 0;
		sect->points_inside = 0;
	}
	return (sect);
}
