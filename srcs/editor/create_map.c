/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:02:03 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/09/25 18:07:24 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "editor.h"

void	write_vertex_file(t_editor *edit, int fd)
{
	int			y;
	t_vertex	*vertex;

	vertex = edit->vertex;
	while (vertex)
	{
		ft_putstr_fd("vertex\t", fd);
		ft_putstr_fd("y ", fd);
		ft_putnbr_fd(vertex->y, fd);
		ft_putchar_fd('\t', fd);
		y = vertex->y;			
		ft_putstr_fd("x ", fd);
		while (vertex && vertex->y == y)
		{
			ft_putnbr_fd(vertex->x, fd);
			if (vertex->next != NULL && vertex->next->y == y)
				ft_putchar_fd(' ', fd);
			vertex = vertex->next;
		}
		ft_putchar_fd('\n', fd);
	}
	ft_putchar_fd('\n', fd);
}

void		write_sector_file(t_sector *sector, t_vertex *all, int fd)
{
	t_sector	*sect;
	t_vertex	*vertex;

	sect = sector;
	while (sect)
	{
		vertex = sect->vertex;
		if (vertex)
		{
			ft_putstr_fd("sector\th_floor ", fd);
			ft_putnbr_fd(sect->h_floor, fd);
			ft_putstr_fd(" h_ceil ", fd);
			ft_putnbr_fd(sect->h_ceil, fd);
			ft_putstr_fd("\tvertexes ", fd);
			write_vertex_sector(sect, all, fd);
			ft_putchar_fd('\n', fd);
		}
		sect = sect->next;
	}
}

void		write_file(t_editor *edit, int fd)
{
	write_player(edit, fd);
	write_ennemy(edit, fd);
	write_object(edit, fd);
	write_vertex_file(edit, fd);
	write_sector_file(edit->sector, edit->vertex, fd);
}

void		create_map(t_editor *edit)
{
	int		fd;
	char	*map_path;

	map_path = "./map/editor_map.dn";
	fd = open(map_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	write_file(edit, fd);
	close(fd);
}