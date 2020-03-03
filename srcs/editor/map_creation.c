#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "editor.h"

void			write_portals(t_ed_sector *sect, int fd)
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
}

static void		write_sectors(t_ed_sector *sector, int fd)
{
	t_ed_sector	*sect;

	sect = sector;
	while (sect)
	{
		if (sect->vertex)
		{
			ft_putstr_fd("sector number ", fd);
			ft_putnbr_fd(sect->sector_number, fd);
			ft_putstr_fd(" texture ", fd);
			ft_putnbr_fd(sect->texture, fd);
			ft_putstr_fd(" type ", fd);
			if (sect->effect.effects == EFF_ELEV && sect->effect.data < 0)
			{
				ft_putnbr_fd(sect->effect.effects * -1, fd);
				ft_putstr_fd(" data ", fd);
				ft_putnbr_fd(sect->effect.data * -1, fd);
			}
			else
			{
				ft_putnbr_fd(sect->effect.effects, fd);
				ft_putstr_fd(" data ", fd);
				ft_putnbr_fd(sect->effect.data, fd);
			}
			ft_putstr_fd(" light ", fd);
			ft_putnbr_fd(sect->light_value, fd);
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
			write_vertex_sector(sect, fd);
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
	t_ed_sector		*sector;

	sector = editor->sector;
	while (sector->prev)
		sector = sector->prev;
	if (sector->vertex)
	{
		get_elements_number(editor, fd);
		write_player(editor->player, *(sector->vertex), fd);
		write_vertexes(sector, fd);
		write_sectors(sector, fd);
	}
}

void			create_map(t_editor *editor)
{
	int		fd;

	if (editor->sect_is_closed && editor->sector)
	{
		fd = open(MAP_PATH, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		if (editor->sector)
			write_file(editor, fd);
		if (close(fd) == -1)
			exit(1);
		ft_putendl("Map saved");
	}
}
