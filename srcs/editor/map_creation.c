#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "editor.h"

static void		write_portal_type(t_sector *sect)
{
	t_portal	*portal;
	t_vertex	*vertex;
	int			i;

	portal = sect->portal;
	while (portal)
	{
		i = 0;
		vertex = sect->vertex;
		while (vertex)
		{
			if (portal->extrems->x == vertex->x &&
				portal->extrems->y == vertex->y)
				sect->portal_type[i] = portal->type;
			vertex = vertex->next;
			++i;
		}
		portal = portal->next;
	}
}

void			write_portals(t_sector *sect, int fd)
{
	int	i;

	i = 0;
	write_portal_type(sect);
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
	while (sect->prev)
		sect = sect->prev;
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
			ft_putstr_fd(" friction ", fd);
			ft_putnbr_fd(sect->friction, fd);
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
		get_elements_number(editor, fd);
		write_player(editor->player, *(editor->vertex), fd);
		if (editor->enemy)
			write_entities(editor->enemy, fd, true);
		if (editor->object)
			write_entities(editor->object, fd, false);
		if (editor->vertex)
			write_vertexes(editor->vertex, fd);
		if (editor->sector)
			write_sectors(editor->sector, editor->vertex, fd);
	}
}

void			create_map(t_editor *editor)
{
	int		fd;

	if (editor->sect_is_closed)
	{
		fd = open(MAP_PATH, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		write_file(editor, fd);
		if (close(fd) == -1)
			exit(1);
		ft_putendl("Map saved");
	}
}
