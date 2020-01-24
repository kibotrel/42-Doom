/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:55:00 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/24 11:31:06 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

t_sector	*create_sector(t_editor *edit)
{
	t_sector	*sect;

	if (!(sect = (t_sector*)ft_memalloc(sizeof(t_sector))))
		clean(edit);
	sect->sector_number = edit->count.sector++;
	sect->h_ceil = 20;
	sect->h_floor = 0;
	sect->vertex_count = 0;
	sect->texture = 0;
	sect->gravity = 5;
	sect->friction = 2;
	sect->next = NULL;
	sect->prev = NULL;
	return (sect);
}
