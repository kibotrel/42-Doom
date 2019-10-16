/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:00:52 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/16 16:30:03 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../../libft/incs/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

t_point		init_pt(int x, int y)
{
	t_point	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

int			ft_isnumber(char *num)
{
	size_t	i;

	if (!num)
		return (0);
	i = 0;
	if (num[i] == '-')
		i++;
	while (ft_isdigit(num[i]))
		i++;
	if (i != ft_strlen(num))
		return (0);
	return (1);
}

void		free_tab(char **t)
{
	int		i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		++i;
	}
	free(t);
}

void		parse(char *l, t_vertex **v_s, t_ennemy **e_s, t_object **o_s)
{
	char		**tab;

	tab = ft_strsplit(l, ' ');
	if (tab[0] && !ft_strcmp("vertex", tab[0]))
		verif_ver(v_s, tab);
	else if (tab[0] && !ft_strcmp("ennemy", tab[0]))
		verif_en(e_s, tab);
	else if (tab[0] && !ft_strcmp("object", tab[0]))
		verif_obj(o_s, tab);
	else
		ft_putendl("ta race");
	free_tab(tab);
}

int			main(int ac, char **av)
{
	int		fd;
	int		gnl;
	char	*line;
	t_vertex	*v;
	t_ennemy	*e;
	t_object	*o;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (1);
		while ((gnl = ft_get_next_line(fd, &line)))
		{
			parse(line, &v, &e, &o);
			free(line);
		}
		if (gnl == -1)
			return (1);
		if (close(fd) == -1)
			return (1);
		print_vert(&v);
		print_en(&e);
		print_obj(&o);
	}
	return (0);
}
