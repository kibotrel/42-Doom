/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:57:24 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/14 12:53:53 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "editor.h"

int				search_vertex_num(t_vertex *all, t_vertex *to_find)
{
	t_vertex	*vertex;

	vertex = all;
	while (vertex)
	{
		if (vertex->x == to_find->x && vertex->y == to_find->y)
			return (vertex->vertex_number);
		vertex = vertex->next;
	}
	return (-1);
}

void			write_portals(t_sector *sect, int fd)
{
	int	i;

	i = 0;
	while (i < sect->vertex_count)
	{
		ft_putnbr_fd(sect->is_portal[i], fd);
		if (i + 1 < sect->vertex_count)
			ft_putchar_fd(' ', fd);
		++i;
	}
	i = 0;
	ft_putstr_fd(" type ", fd);
	while (i < sect->vertex_count)
	{
		ft_putnbr_fd(sect->portal_type[i], fd);
		if (i + 1 < sect->vertex_count)
			ft_putchar_fd(' ', fd);
		++i;
	}
}

static void		write_sectors(t_sector *sector, t_vertex *all, int fd)
{
	t_sector	*sect;

	sect = sector;
	while (sect)
	{
		if (sect->vertex)
		{
			ft_putstr_fd("sector number ", fd);
			ft_putnbr_fd(sect->sector_number, fd);
			ft_putstr_fd(" h_floor ", fd);
			ft_putnbr_fd(sect->h_floor, fd);
			ft_putstr_fd(" h_ceil ", fd);
			ft_putnbr_fd(sect->h_ceil, fd);
			ft_putstr_fd(" gravity ", fd);
			ft_putnbr_fd(sect->gravity, fd);
			ft_putstr_fd(" viscosity ", fd);
			ft_putnbr_fd(sect->viscosity, fd);
			ft_putstr_fd(" vertex_num ", fd);
			ft_putnbr_fd(sect->vertex_count, fd);
			ft_putstr_fd(" vertexes ", fd);
			write_vertex_sector(sect, all, fd);
			if (sect->next)
				ft_putchar_fd('\n', fd);
		}
		sect = sect->next;
		if (sector)
			ft_putchar_fd('\n', fd);
	}
}

static void		write_file(t_editor *editor, int fd)
{
	if (editor->vertex)
	{
		write_player(editor->player, *(editor->vertex), fd);
		write_entities(editor->enemy, fd, true);
		write_entities(editor->object, fd, false);
		write_vertexes(editor->vertex, fd);
		write_sectors(editor->sector, editor->vertex, fd);
	}
}

// static void			place_portal_type(t_portal *from, t_sector **all_portals)
// {
// 	t_sector	*sector;
// 	t_portal	*p1;
// 	t_portal	*p2;

// 	sector = *all_portals;
// 	p1 = from;
// 	while (sector->prev)
// 		sector = sector->prev;
// 	while (sector)
// 	{
// 		p2 = sector->portal;
// 		while (p2)
// 		{
// 			p2->type = p1->type;
// 			p1 = p1->next;
// 			p2 = p2->next;
// 		}
// 		sector = sector->next;
// 	}
// }

// static void			fill_portal_tab(t_sector **sector)
// {
// 	t_portal	*port;
// 	t_sector	*sect;
// 	int			i;

// 	sect = *sector;
// 	while (sect->prev)
// 		sect = sect->prev;
// 	while (sect)
// 	{
// 		port = sect->portal;
// 		i = -1;
// 		while (++i < sect->vertex_count)
// 		{
// 			if (sect->is_portal[i] != -1)
// 			{
// 				sect->portal_type[i] = 1;
// 				// if (port->next)
// 					// port = port->next;
// 			}
// 		}
// 		sect = sect->next;
// 	}
// }

// void	oui(t_sector *sect)
// {
// 	t_sector *oui;
// 	t_portal *non;

// 	oui = sect;
// 	while (oui->prev)
// 		oui = oui->prev;
// 	while (oui)
// 	{
// 		non = oui->portal;
// 		while (non)
// 		{
// 			printf("peut etre\n");
// 			non = non->next;
// 		}
// 		oui = oui->next;
// 	}
// }

void			create_map(t_editor *editor)
{
	int		fd;

	fd = open(MAP_PATH, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	// oui(editor->sector);
	// if (editor->portals)
	// {
	// 	place_portal_type(editor->portals, &editor->sector);
	// 	fill_portal_tab(&editor->sector);
	// }
	write_file(editor, fd);
	if (close(fd) == -1)
		exit(1);
	ft_putendl("Map saved");
}
