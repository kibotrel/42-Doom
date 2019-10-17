/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:00:52 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/17 13:12:26 by reda-con         ###   ########.fr       */
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
	{
		ft_putendl("ta mere");
		return ;
	}
	if (tab[1] && tab[3] && !ft_strcmp(tab[1], "y") && ! ft_strcmp(tab[3], "x"))
		if (tab[2] && tab[4] && ft_isnumber(tab[2]) && ft_isnumber(tab[4]))
			*pl = init_pt(ft_atoi(tab[2]), ft_atoi(tab[4]));
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

void		parse(char *l, t_vertex **v_s, t_ennemy **e_s, t_object **o_s, t_point *pl)
{
	char		**tab;

	tab = ft_strsplit(l, ' ');
	if (tab[0] && !ft_strcmp("vertex", tab[0]))
		verif_ver(v_s, tab);
	else if (tab[0] && !ft_strcmp("ennemy", tab[0]))
		verif_en(e_s, tab);
	else if (tab[0] && !ft_strcmp("object", tab[0]))
		verif_obj(o_s, tab);
	else if (tab[0] && !ft_strcmp("player", tab[0]))
		verif_pl(pl, tab);
	else if (!verif_blank(tab) || tab[0][0] == '#')
		ft_putendl("is ok");
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
	t_point		pl;

	pl = init_pt(-1, -1);
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (1);
		while ((gnl = ft_get_next_line(fd, &line)))
		{
			parse(line, &v, &e, &o, &pl);
			free(line);
		}
		if (gnl == -1)
			return (1);
		if (close(fd) == -1)
			return (1);
		print_vert(&v);
		print_en(&e);
		print_obj(&o);
		ft_putstr("player: ");
		print_pt(pl);
	}
	return (0);
}
