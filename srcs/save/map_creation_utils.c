/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:51:03 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/22 11:12:59 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

static int		count_entity(t_entity *all_entity)
{
	t_entity *entity;

	if (!all_entity)
		return (0);
	entity = all_entity;
	while (entity->next)
		entity = entity->next;
	return (entity->number + 1);
}

int		count_sector(t_sector *all_sector)
{
	t_sector	*sector;

	if (!all_sector)
		return (0);
	sector = all_sector;
	while (sector->next)
		sector = sector->next;
	return (sector->sector_number);
}

static int		count_vertex(t_vertex *all_vertex)
{
	t_vertex	*vertex;
	int			i;

	if (!all_vertex)
		return (0);
	vertex = all_vertex;
	i = 0;
	while (vertex)
	{
		vertex = vertex->next;
		++i;
	}
	return (i);
}

void	get_elements_number(t_editor *editor, int fd)
{
	ft_putstr_fd("total vertexes ", fd);
	ft_putnbr_fd(count_vertex(editor->vertex), fd);
	ft_putstr_fd(" sectors ", fd);
	ft_putnbr_fd(count_sector(editor->sector), fd);
	ft_putstr_fd(" enemies ", fd);
	ft_putnbr_fd(count_entity(editor->enemy), fd);
	ft_putstr_fd(" objects ", fd);
	ft_putnbr_fd(count_entity(editor->object), fd);
	ft_putstr_fd("\n\n", fd);
}