/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_check_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:24:32 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/26 11:54:20 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

void 	add_tmp_sector(t_sector *new, t_sector **lst)
{
	t_sector	*sect;
	
	if (!*lst)
		*lst = new;
	else
	{
		sect = *lst;
		while (sect)
			sect = sect->next;
		sect->next = new;
	}
}

int		check_which_sector(t_sector *sectors)
{
// 	// t_sector 	*sect_1;
// 	// t_sector	*sect_2;
// 	// t_sector	*result;
// 	// t_sector	*tmp;

// 	// if (!sectors->next)
	return (sectors->sector_number);
// 	// while (sectors->next)
// 	// {
// 	// 	sect_1 = sectors;
// 	// 	sect_2 = sector->next;
// 	// 	result = verif_sector(sect_1, sect_2);
// 	// 	tmp = result;
// 	// 	sectors = sectors->next;
// 	// }
}