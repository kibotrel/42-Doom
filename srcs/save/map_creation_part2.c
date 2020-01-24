/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:04:36 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/24 12:02:07 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "libft.h"

void	write_player(t_player player, t_vertex if_no_player, int fd)
{
	if (player.x < 0 && player.y < 0)
	{
		player.x = if_no_player.x;
		player.y = if_no_player.y;
		player.sector = 0;
	}
	ft_putstr_fd("player x ", fd);
	ft_putnbr_fd(player.x, fd);
	ft_putstr_fd(" y ", fd);
	ft_putnbr_fd(player.y, fd);
	ft_putstr_fd(" sector ", fd);
	ft_putnbr_fd(player.sector, fd);
	ft_putstr_fd(" angle ", fd);
	ft_putnbr_fd(player.angle, fd);
	ft_putstr_fd("\n\n", fd);
}

void	write_entities(t_entity *entities, int fd, bool type)
{
	t_entity	*entity;

	entity = entities;
	while (entity->prev)
		entity = entity->prev;
	while (entity)
	{
		type == true ? ft_putstr_fd("enemy number ", fd) :
			ft_putstr_fd("object number ", fd);
		ft_putnbr_fd(entity->number, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(entity->x, fd);
		ft_putstr_fd(" y ", fd);
		ft_putnbr_fd(entity->y, fd);
		ft_putstr_fd(" sector ", fd);
		ft_putnbr_fd(entity->sector, fd);
		ft_putstr_fd(" angle ", fd);
		ft_putnbr_fd(entity->angle, fd);
		ft_putstr_fd(" type ", fd);
		ft_putnbr_fd(entity->type, fd);
		ft_putchar_fd('\n', fd);
		entity = entity->next;
	}
	if (entities)
		ft_putchar_fd('\n', fd);
}

void	write_vertexes(t_vertex *vertexes, int fd)
{
	t_vertex	*vertex;

	vertex = vertexes;
	while (vertex)
	{
		ft_putstr_fd("vertex number ", fd);
		ft_putnbr_fd(vertex->vertex_number, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(vertex->x, fd);
		ft_putchar_fd(' ', fd);
		ft_putstr_fd("y ", fd);
		ft_putnbr_fd(vertex->y, fd);
		ft_putchar_fd('\n', fd);
		vertex = vertex->next;
	}
	if (vertexes)
		ft_putchar_fd('\n', fd);
}

void	write_vertex_sector(t_sector *sect, t_vertex *all, int fd)
{
	int			pos;
	t_vertex	*vertex;

	vertex = sect->vertex;
	while (vertex)
	{
		pos = search_vertex_num(all, vertex);
		ft_putnbr_fd(pos, fd);
		if (vertex->next)
			ft_putchar_fd(' ', fd);
		vertex = vertex->next;
	}
	ft_putstr_fd(" portals ", fd);
	write_portals(sect, fd);
}
