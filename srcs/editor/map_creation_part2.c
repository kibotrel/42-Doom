#include "editor.h"
#include "libft.h"

void	write_player(t_ed_player player, t_vertex if_no_player, int fd)
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

void	write_vertexes(t_ed_sector *vertexes, int fd)
{
	t_ed_sector	*sect;
	t_vertex	*vertex;
	int			count;

	count = 0;
	sect = vertexes;
	while (sect)
	{
		vertex = sect->vertex;
		while (vertex)
		{
			if (count <= vertex->vertex_number)
			{
				ft_putstr_fd("vertex number ", fd);
				ft_putnbr_fd(vertex->vertex_number, fd);
				ft_putstr_fd(" x ", fd);
				ft_putnbr_fd(vertex->x, fd);
				ft_putchar_fd(' ', fd);
				ft_putstr_fd("y ", fd);
				ft_putnbr_fd(vertex->y, fd);
				ft_putchar_fd('\n', fd);
				++count;
			}
			vertex = vertex->next;
		}
		sect = sect->next;
	}
	if (vertexes->vertex)
		ft_putchar_fd('\n', fd);
}

void	write_vertex_sector(t_ed_sector *sect, int fd)
{
	t_vertex	*vertex;

	vertex = sect->vertex;
	while (vertex)
	{
		ft_putnbr_fd(vertex->vertex_number, fd);
		if (vertex->next)
			ft_putchar_fd(' ', fd);
		vertex = vertex->next;
	}
	ft_putstr_fd(" portals ", fd);
	write_portals(sect, fd);
}
