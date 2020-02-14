/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:00:52 by reda-con          #+#    #+#             */
/*   Updated: 2020/02/14 13:57:22 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "core.h"
#include "utils.h"
#include "../../libft/incs/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void		parse_err(char **tab, t_parse *p)
{
	if (p->ver)
		free(p->ver);
	if (p->emy)
		free(p->emy);
	if (p->obj)
		free(p->obj);
	if (p->sec)
	{
		if (p->sec->neighbor)
			free(p->sec->neighbor);
		if (p->sec->vertex)
			free(p->sec->vertex);
		free(p->sec);
	}
	free_tab(tab);
	ft_putendl("parse error");
	exit(1);
}

void		parse(char *l, t_parse *par, t_env *env)
{
	char		**tab;
	int			i;

	i = 0;
	tab = ft_strsplit(l, ' ');
	if (tab[0] && !ft_strcmp("total", tab[0])){//ft_putendl("oui");
		i += verif_total(&par->total, tab, par, env);}
	else if (tab[0] && !ft_strcmp("vertex", tab[0])){//ft_putendl("non");
		i += verif_vertex(par->ver, tab);}
	else if (tab[0] && !ft_strcmp("enemy", tab[0])){//ft_putendl("peut");
		i += verif_entity(par->emy, tab);}
	else if (tab[0] && !ft_strcmp("object", tab[0])){//ft_putendl("etre");
		i += verif_entity(par->obj, tab);}
	else if (tab[0] && !ft_strcmp("player", tab[0])){//ft_putendl("je");
		i += verif_player(&env->cam, tab);}
	else if (tab[0] && !ft_strcmp("sector", tab[0])){//ft_putendl("ne");
		i += verif_sector(env->sector, tab, par->ver, env);}
	else if (verif_blank(tab) && tab[0][0] != '#')
		parse_err(tab, par);
	(i != 0) ? parse_err(tab, par) : free_tab(tab);
}

void		parse_end(t_parse p)
{
	free(p.ver);
	free(p.emy);
	free(p.obj);
}

void		tmp(t_sector *s, int nb)
{
	int			i;
	uint32_t	j;

	i = 0;
	while (i < nb)
	{
		s[i].doors_neighbor = (int*)malloc(sizeof(int) * s[i].points);
		j = 0;
		while (j < s[i].points)
		{
			s[i].doors_neighbor[j] = s[i].neighbor[j];
			if (s[i].type == 4 || s[s[i].neighbor[j]].type == 4)
				s[i].neighbor[j] = -2;
			++j;
		}
		++i;
	}
}

int			main_parse(char **av, t_env *env, int ac)
{
	int		fd;
	int		gnl;
	char	*line;
	t_parse	par;
	char	*file;

	gnl = ft_isvalidname(av[1], ".data");
	if (gnl == 0)
		exit(1);
	file = (ac == 2) ? av[1] : "hard_map.data";
	env->cam.pos = v3d(-1, -1, 0);
	if ((fd = open(file, O_RDONLY)) == -1)
		exit(1);
	while ((gnl = ft_get_next_line(fd, &line)) == 1)
	{
		parse(line, &par, env);
		free(line);
	}
	if (gnl == -1 || close(fd) || par.plr.pos.x <= -1 || par.plr.pos.y <= -1)
		exit(1);
	env->sector[0].num_link = 1;
	env->sector[0].link = malloc(sizeof(int) * env->sector[0].num_link);
	env->sector[0].link[0] = 1;
	env->sector[1].num_link = 1;
	env->sector[1].link = malloc(sizeof(int) * env->sector[1].num_link);
	env->sector[1].link[0] = 0;
	env->sector[2].num_link = 1;
	env->sector[2].link = malloc(sizeof(int) * env->sector[2].num_link);
	env->sector[2].link[0] = 3;
	env->sector[3].num_link = 1;
	env->sector[3].link = malloc(sizeof(int) * env->sector[3].num_link);
	env->sector[3].link[0] = 2;
	tmp(env->sector, env->zones);
	parse_end(par);
	return (0);
}
