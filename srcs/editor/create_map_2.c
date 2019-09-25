/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:48:19 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/09/25 17:58:09 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

int		search_vertex(t_vertex *all, t_vertex *to_find)
{
	t_vertex	*vertex;

	vertex = all;
	while (vertex)
	{
		if (vertex->x == to_find->x && vertex->y == to_find->y)
			return (vertex->number);
		vertex = vertex->next;
	}
	return (-1);
}

void	write_portals(t_sector *sect, int fd)
{
	int 	i;

	i = 0;
	while (i < sect->num_vertex)
	{
		ft_putnbr_fd(sect->is_portal[i], fd);
		if (i + 1 < sect->num_vertex)
			ft_putchar_fd(' ', fd);
		++i;
	}
}

void	write_vertex_sector(t_sector *sect, t_vertex *all, int fd)
{
	int			pos;
	t_vertex	*vertex;

	vertex = sect->vertex;
	while (vertex)
	{
		pos = search_vertex(all, vertex);
		ft_putnbr_fd(pos, fd);
		if (vertex->next)
			ft_putchar_fd(' ', fd);
		vertex = vertex->next;
	}
	ft_putchar_fd('\t', fd);
	write_portals(sect, fd);
	ft_putchar_fd('\t', fd);
}