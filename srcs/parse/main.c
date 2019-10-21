/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:00:52 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/21 16:51:15 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../../libft/incs/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void		verif_pl(t_point *pl, char **tab)
{
	if (pl->x != -1 && pl->y != -1)
		exit(1);
	if (tab[1] && tab[3] && !ft_strcmp(tab[1], "y") && !ft_strcmp(tab[3], "x"))
	{
		if (tab[2] && tab[4] && ft_isnumber(tab[2]) && ft_isnumber(tab[4]))
			*pl = init_pt(ft_atoi(tab[2]), ft_atoi(tab[4]));
		else
			exit(1);
	}
	else
		exit(1);
}

int			verif_blank(char **t)
{
	int		i;
	int		j;

	i = -1;
	while (t[++i])
	{
		j = -1;
		while (t[i][++j])
			if (!ft_isspace(t[i][j]))
				return (1);
	}
	return (0);
}

void		parse(char *l, t_parse *par)
{
	char		**tab;

	tab = ft_strsplit(l, ' ');
	if (tab[0] && !ft_strcmp("vertex", tab[0]))
		verif_ver(&par->v, tab);
	else if (tab[0] && !ft_strcmp("ennemy", tab[0]))
		verif_en(&par->e, tab);
	else if (tab[0] && !ft_strcmp("object", tab[0]))
		verif_obj(&par->o, tab);
	else if (tab[0] && !ft_strcmp("player", tab[0]))
		verif_pl(&par->p, tab);
	else if (tab[0] && !ft_strcmp("sector", tab[0]))
		verif_sec(&par->s, tab);
	else if (verif_blank(tab) && tab[0][0] != '#')
	{
		free_tab(tab);
		exit(1);
	}
	free_tab(tab);
}

int			main(int ac, char **av)
{
	int		fd;
	int		gnl;
	char	*line;
	t_parse	par;

	init_parse(&par);
	par.p = init_pt(-1, -1);
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			exit(1);
		while ((gnl = ft_get_next_line(fd, &line)) == 1)
		{
			parse(line, &par);
			free(line);
		}
		if (gnl == -1)
			exit(1);
		if (close(fd) == -1)
			exit(1);
		if (par.p.x <= -1 || par.p.y <= -1)
			exit(1);
		print_vert(&par.v);
		print_en(&par.e);
		print_obj(&par.o);
		print_sec(&par.s);
		ft_putstr("player: ");
		print_pt(par.p);
	}
	return (0);
}
