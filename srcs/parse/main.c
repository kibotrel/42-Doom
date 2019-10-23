/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:00:52 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/23 18:54:20 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "doom.h"
#include "../../libft/incs/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int			verif_pl(t_point *pl, char **tab)
{
	if (pl->x != -1 && pl->y != -1)
		return (1);
	if (tab[1] && tab[3] && !ft_strcmp(tab[1], "y") && !ft_strcmp(tab[3], "x"))
	{
		if (tab[2] && tab[4] && ft_isnum(tab[2]) && ft_isnum(tab[4]))
			*pl = init_pt(ft_atoi(tab[2]), ft_atoi(tab[4]));
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

void		parse(char *l, t_parse *par)
{
	char		**tab;
	int			i;

	i = 0;
	tab = ft_strsplit(l, ' ');
	if (tab[0] && !ft_strcmp("vertex", tab[0]))
		i += verif_ver(&par->v, tab);
	else if (tab[0] && !ft_strcmp("ennemy", tab[0]))
		i += verif_en(&par->e, tab);
	else if (tab[0] && !ft_strcmp("object", tab[0]))
		i += verif_obj(&par->o, tab);
	else if (tab[0] && !ft_strcmp("player", tab[0]))
		i += verif_pl(&par->p, tab);
	else if (tab[0] && !ft_strcmp("sector", tab[0]))
		i += verif_sec(&par->s, tab);
	else if (verif_blank(tab) && tab[0][0] != '#')
		parse_err(tab);
	i != 0 ? parse_err(tab) : free_tab(tab);
}

int			main_parse(char *file, t_env *env)
{
	int		fd;
	int		gnl;
	char	*line;
	t_parse	par;

	init_parse(&par);
	par.p = init_pt(-1, -1);
	if ((fd = open(file, O_RDONLY)) == -1)
		exit(1);
	while ((gnl = ft_get_next_line(fd, &line)) == 1)
	{
		parse(line, &par);
		free(line);
	}
	if (gnl == -1 || close(fd) || par.p.x <= -1 || par.p.y <= -1)
		exit(1);
	env->vertex = par.v;
	env->entity = par.e;
	env->sprite = par.o;
	env->sector = par.s;
	env->player = par.p;
	return (0);
}
