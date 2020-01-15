/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:00:52 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/23 10:33:33 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
//#include "doom.h"
#include "../../libft/incs/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int			verif_player(t_player *pl, char **tab)
{
	if (pl->pos.x != -1 && pl->pos.y != -1)
		return (1);
	if (tab[1] && tab[3] && tab [5] && tab [7] && !ft_strcmp(tab[1], "x")
			&& !ft_strcmp(tab[3], "y") && !ft_strcmp(tab[5], "sector")
			&& !ft_strcmp(tab[7], "angle"))
	{
		if (tab[2] && tab[4] && tab [6] && tab[8] && ft_isnum(tab[2])
				&& ft_isnum(tab[4]) && ft_isnum(tab[6]) && ft_isnum(tab[8]))
		{
			pl->pos = init_vec2d(ft_atoi(tab[2]), ft_atoi(tab[4]));
			pl->sect = ft_atoi(tab[6]);
			pl->angle = ft_atoi(tab[8]);
		}
		else
			return (1);
	}
	else
		return (1);
	return (0);
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

void		parse_err(char **tab)
{
	free_tab(tab);
	exit(1);
}

void		init_total(t_total *total, char **tab, t_parse *par)
{
	total->vert = ft_atoi(tab[2]);
	total->sect = ft_atoi(tab[4]);
	total->emy = ft_atoi(tab[6]);
	total->obj = ft_atoi(tab[8]);
	if (!(par->ver = (t_vec2d*)malloc(sizeof(t_vec2d) * total->vert)))
		parse_err(tab);
	if (!(par->sec = (t_sector*)malloc(sizeof(t_sector) * total->sect)))
		parse_err(tab);
	if (!(par->emy = (t_entity*)malloc(sizeof(t_entity) * total->emy)))
		parse_err(tab);
	if (!(par->obj = (t_entity*)malloc(sizeof(t_entity) * total->obj)))
		parse_err(tab);
}

int			verif_total(t_total *total, char **tab, t_parse *par)
{
	if (tab[1] && tab[3] && tab[5] && tab [7] && !ft_strcmp("vertexes", tab[1])
			&& !ft_strcmp("sectors", tab[3]) && !ft_strcmp("enemies", tab[5])
			&& !ft_strcmp("objects", tab[7]))
	{
		if (tab[2] && tab[4] && tab[6] && tab[8] && ft_isnum(tab[2])
				&& ft_isnum(tab[4]) && ft_isnum(tab[6]) && ft_isnum(tab[8]))
				init_total(total, tab, par);
		else
			return (1);
	}
	else
		return (1);
	return (0);
}

void		parse(char *l, t_parse *par)
{
	char		**tab;
	int			i;

	i = 0;
	tab = ft_strsplit(l, ' ');
	if (tab[0] && !ft_strcmp("total", tab[0]))
		i += verif_total(&par->total, tab, par);
	else if (tab[0] && !ft_strcmp("vertex", tab[0]))
		i += verif_vertex(par->ver, tab);
	else if (tab[0] && !ft_strcmp("enemy", tab[0]))
		i += verif_entity(par->emy, tab);
	else if (tab[0] && !ft_strcmp("object", tab[0]))
		i += verif_entity(par->obj, tab);
	else if (tab[0] && !ft_strcmp("player", tab[0]))
		i += verif_player(&par->plr, tab);
	else if (tab[0] && !ft_strcmp("sector", tab[0]))
		i += verif_sector(par->sec, tab, par->ver);
	else if (verif_blank(tab) && tab[0][0] != '#')
		parse_err(tab);
	(i != 0) ? parse_err(tab) : free_tab(tab);
}

int			main(int ac, char **av)
{
	int		fd;
	int		gnl;
	char	*line;
	t_parse	par;

	(void)ac;
	par.plr.pos = init_vec2d(-1, -1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit(1);
	while ((gnl = ft_get_next_line(fd, &line)) == 1)
	{
		parse(line, &par);
		free(line);
	}
	if (gnl == -1 || close(fd) || par.plr.pos.x <= -1 || par.plr.pos.y <= -1)
		exit(1);
/*	env->vertex = par.v;
	env->entity = par.e;
	env->sprite = par.o;
	env->sector = par.s;
	env->player = par.p;*/
	print_plr(par.plr);
	print_vert(par.ver, par.total.vert);
	print_en(par.emy, par.total.emy);
	print_en(par.obj, par.total.obj);
	print_sec(par.sec, par.total.sect);
	return (0);
}
