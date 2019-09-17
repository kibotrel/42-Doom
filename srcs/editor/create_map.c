/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:02:03 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/09/17 09:42:23 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "editor.h"

void	write_player(t_editor *edit, int fd)
{	
	ft_putstr_fd("player\ty ", fd);
	if (edit->player.number == 1)
	{
		ft_putnbr_fd(edit->player.y, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(edit->player.x, fd);
	}
	else
	{
		ft_putnbr_fd(0, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(0, fd);
	}
	ft_putstr_fd("\n\n", fd);
}

void	write_vertex_file(t_editor *edit, int fd)
{
	t_vertex	*vertex;

	vertex = edit->vertex;
	while (vertex)
	{
		ft_putstr_fd("vertex\tnumber ", fd);
		ft_putnbr_fd(vertex->number, fd);
		ft_putstr_fd(" y ", fd);
		ft_putnbr_fd(vertex->y, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(vertex->x, fd);
		ft_putchar_fd('\n', fd);
		vertex = vertex->next;
	}
		ft_putchar_fd('\n', fd);
}

void		write_file(t_editor *edit, int fd)
{
	write_player(edit, fd);
	write_vertex_file(edit, fd);
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