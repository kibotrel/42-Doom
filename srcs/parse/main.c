/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:00:52 by reda-con          #+#    #+#             */
/*   Updated: 2020/03/05 14:07:55 by reda-con         ###   ########.fr       */
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

static void		parse(char *l, t_parse *par, t_env *env)
{
	char		**tab;
	int			i;

	i = 0;
	tab = ft_strsplit(l, ' ');
	if (tab[0] && !ft_strcmp("total", tab[0]) && par->fsl == 0)
	{
		++par->fsl;
		i += verif_total(tab, par, env);
		env->vert_ct = par->total;
	}
	else if (tab[0] && !ft_strcmp("vertex", tab[0]) && par->fsl != 0)
		i += verif_vertex(par->ver, tab, &par->nb, par);
	else if (tab[0] && !ft_strcmp("player", tab[0]) && par->fsl != 0)
		i += verif_player(&env->cam, tab);
	else if (tab[0] && !ft_strcmp("sector", tab[0]) && par->fsl != 0)
		i += verif_sector(env->sector, tab, par->ver, env);
	else if (verif_blank(tab) && tab[0][0] != '#' && par->fsl != 0)
		parse_err(tab, par, env, E_PARSE_BLANK);
	(i != 0) ? parse_err(tab, par, env, E_PARSE + i) : free_tab(tab);
}

static void		set_doors(t_sector *s, int nb)
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
			if (s[i].type < -END || (k > 0 && s[k].type < -END))
				s[i].neighbor[j] = -2;
			++j;
		}
		++i;
	}
}

static void		verif_end(int gnl, int fd, t_env *env, t_parse par)
{
	if (par.fsl == 0)
		main_err(&par, env, 1, E_PARSE_NO_TOTAL);
	if (gnl == -1)
		main_err(&par, env, 1, E_PARSE_GNL);
	if (close(fd))
		main_err(&par, env, 1, E_PARSE_CLOSE);
	if (env->cam.pos.x <= -1 || env->cam.pos.y <= -1)
		main_err(&par, env, 1, E_PARSE_NO_PLAYER);
	if (par.total == -1)
		main_err(&par, env, 1, E_PARSE_TOTAL);
	if (par.nb != par.total)
		main_err(&par, env, 1, E_PARSE_NB_VERTEX);
	if (env->sect_ct != env->zones)
		main_err(&par, env, 1, E_PARSE_NB_SECTOR);
}

static void		read_file(char *file, char **av, t_env *env)
{
	int		fd;
	int		gnl;
	char	*line;
	t_parse	par;

	env->sect_ct = 0;
	ft_bzero(&par, sizeof(t_parse));
	env->cam.pos = v3d(-1, -1, 0);
	env->zones = 0;
	gnl = ft_isvalidname(av[1], ".data");
	if (gnl == 0)
		clean(env, E_PARSE_NAME);
	if ((fd = open(file, O_RDONLY)) == -1)
		clean(env, E_PARSE_OPEN);//ici
	while ((gnl = ft_get_next_line(fd, &line)) == 1)
	{
		parse(line, &par, env);
		free(line);
	}
	verif_end(gnl, fd, env, par);
	set_doors(env->sector, env->zones);
	main_err(&par, env, 0, NOTHING);
}

int				main_parse(char **av, t_env *env, int ac)
{
	char	*file;

	file = (ac == 2) ? av[1] : "hard_map";
	if (!ft_strcmp(file, "hard_map") && ac == 1)
		hard_map_one(env);
	else
		read_file(file, av, env);
	return (0);
}
