/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:00:52 by reda-con          #+#    #+#             */
/*   Updated: 2020/02/21 10:19:43 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "core.h"
#include "utils.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "clean.h"

void		main_err(t_parse *p, t_env *env, int fl)
{
	if (p->total.vert >= 0)
		free(p->ver);
	if (p->total.emy >= 0)
		free(p->emy);
	if (p->total.obj >= 0)
		free(p->obj);
	if (fl == 1)
		clean(env, E_PARSE);
}

void		parse_err(char **tab, t_parse *p, t_env *env)
{
	free_tab(tab);
	main_err(p, env, 1);
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
		parse_err(tab, par, env);
	(i != 0) ? parse_err(tab, par, env) : free_tab(tab);
}

void		tmp(t_sector *s, int nb)
{
	int			i;
	uint32_t	j;
	int			k;

	i = 0;
	while (i < nb)
	{
		s[i].door_neighbor = (int*)malloc(sizeof(int) * s[i].points);
		j = 0;
		while (j < s[i].points)
		{
			k = s[i].neighbor[j];
			s[i].door_neighbor[j] = k;
			if (s[i].type < 0 || (k > 0 && s[k].type < 0))
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
	par.total.vert = -1;
	env->zones = 0;
	par.total.emy = -1;
	par.total.obj = -1;
	while ((gnl = ft_get_next_line(fd, &line)) == 1)
	{
		parse(line, &par, env);
		free(line);
	}
	if (gnl == -1 || close(fd) || env->cam.pos.x <= -1 || env->cam.pos.y <= -1 || env->zones == 0 || par.total.vert == 0)
		main_err(&par, env, 1);
	tmp(env->sector, env->zones);
	main_err(&par, env, 0);
	return (0);
}
