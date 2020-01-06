/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_check_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:24:32 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/06 08:37:12 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

void	add_tmp_sector(t_sector *new, t_sector **lst)
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
