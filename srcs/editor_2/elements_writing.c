/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_writing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:04:36 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/05 15:38:55 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "libft.h"

void	write_player(t_player player, t_vertex if_no_player, int fd)
{
	if (player.x == -1 && player.y == -1)
	{
		player.x = if_no_player.x;
		player.y = if_no_player.y;
	}
	ft_putstr_fd("player x ", fd);
	ft_putnbr_fd(player.x, fd);
	ft_putstr_fd(" y ", fd);
	ft_putnbr_fd(player.y, fd);
	ft_putstr_fd(" angle ", fd);
	ft_putnbr_fd(player.angle, fd);	
	ft_putchar_fd('\n');
}

void	write_enemies(t_entity *enemies, int fd)
{
	t_entity	*enemy;

	enemy = enemies;
	while (enemy)
	{
		ft_putstr_fd("enemy number ", fd);
		ft_putnbr_fd(enemy->number, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(enemy->x, fd);
		ft_putstr_fd(" y ", fd);
		ft_putnbr_fd(enemy->y, fd);
		ft_putstr_fd(" type ", fd);
		ft_putnbr_fd(enemy->type, fd);
		ft_putchar_fd('\n', fd);
		enemy = enemy->next;
	}
}

void	write_objects(t_entity *objects, int fd)
{
	t_entity	*object;

	object = objects;
	while (object)
	{
		ft_putstr_fd("object number ", fd);
		ft_putnbr_fd(object->number, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(object->x, fd);
		ft_putstr_fd(" y ", fd);
		ft_putnbr_fd(object->y, fd);
		ft_putstr_fd(" type ", fd);
		ft_putnbr_fd(object->type, fd);
		ft_putchar_fd('\n', fd);
		object = object->next;
	}
}

void	write_vertexes(t_vertex *vertexes, int fd)
{
	t_vertex	*vertex;

	vertex = vertexes;
	while (vertex)
	{
		ft_putstr_fd("vertex ", fd);
		ft_putstr_fd("x ", fd);
		ft_putnbr_fd(vertex->x, fd);
		ft_putchar_fd(' ', fd);
		ft_putstr_fd("y ", fd);
		ft_putnbr_fd(vertex->y, fd);
		ft_putchar_fd('\n', fd);		
		vertex = vertex->next;
	}
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
