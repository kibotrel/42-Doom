/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:00:52 by reda-con          #+#    #+#             */
/*   Updated: 2020/02/07 13:50:54 by reda-con         ###   ########.fr       */
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
		if (p->sec->portal_type)
			free(p->sec->portal_type);
		if (p->sec->vertex)
			free(p->sec->vertex);
		free(p->sec);
	}
	free_tab(tab);
	exit(1);
}

void		parse(char *l, t_parse *par)
{
	char		**tab;
	int			i;

	i = 0;
	tab = ft_strsplit(l, ' ');
	if (tab[0] && !ft_strcmp("total", tab[0])){//ft_putendl("oui");
		i += verif_total(&par->total, tab, par);}
	else if (tab[0] && !ft_strcmp("vertex", tab[0])){//ft_putendl("non");
		i += verif_vertex(par->ver, tab);}
	else if (tab[0] && !ft_strcmp("enemy", tab[0])){//ft_putendl("peut");
		i += verif_entity(par->emy, tab);}
	else if (tab[0] && !ft_strcmp("object", tab[0])){//ft_putendl("etre");
		i += verif_entity(par->obj, tab);}
	else if (tab[0] && !ft_strcmp("player", tab[0])){//ft_putendl("je");
		i += verif_player(&par->plr, tab);}
	else if (tab[0] && !ft_strcmp("sector", tab[0])){//ft_putendl("ne");
		i += verif_sector(par->sec, tab, par->ver, par);}
	else if (verif_blank(tab) && tab[0][0] != '#')
		parse_err(tab, par);
	(i != 0) ? parse_err(tab, par) : free_tab(tab);
}

int			main_parse(char *file, t_env *env)
{
	int		fd;
	int		gnl;
	char	*line;
	t_parse	par;

	par.plr.pos = init_vec2d(-1, -1);
	if ((fd = open(file, O_RDONLY)) == -1)
		exit(1);
	while ((gnl = ft_get_next_line(fd, &line)) == 1)
	{
		parse(line, &par);
		free(line);
	}
	if (gnl == -1 || close(fd) || par.plr.pos.x <= -1 || par.plr.pos.y <= -1)
		exit(1);
	par.sec[0].num_link = 1;
	par.sec[0].link = malloc(sizeof(int) * par.sec[0].num_link);
	par.sec[0].link[0] = 1;
	par.sec[1].num_link = 1;
	par.sec[1].link = malloc(sizeof(int) * par.sec[1].num_link);
	par.sec[1].link[0] = 0;
	par.sec[2].num_link = 1;
	par.sec[2].link = malloc(sizeof(int) * par.sec[2].num_link);
	par.sec[2].link[0] = 3;
	par.sec[3].num_link = 1;
	par.sec[3].link = malloc(sizeof(int) * par.sec[3].num_link);
	par.sec[3].link[0] = 2;
	env->zones = par.total.sect;
	env->sector = par.sec;
	env->cam.angle = par.plr.angle;
	env->cam.pos = v3d(par.plr.pos.x, par.plr.pos.y, 0);
	env->cam.sector = par.plr.sect;
	return (0);
}
