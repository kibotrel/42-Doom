/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:00:52 by reda-con          #+#    #+#             */
/*   Updated: 2020/02/24 17:29:15 by reda-con         ###   ########.fr       */
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

/*


   static int const		g_neighbor[8][2][8] = {
   {
   {-1, 1, -1, -2, -1, -1, -1},
   {-1, 1, -1, 2, -1, -1, -1}
   },
   {
   {-1, -1, -1, 0},
   {-1, -1, -1, 0}
   },
   {
   {-1, -1, -1, -2},
   {-1, -1, -1, 0}
   },
   {
   {-1, 4, -1, -2},
   {-1, 4, -1, 2}
   },
   {
   {-1, 5, -1, 6, -1, -1, -1, 3},
   {-1, 5, -1, 6, -1, -1, -1, 3}
   },
   {
   {-1, -1, -1, 4},
   {-1, -1, -1, 4}
   },
   {
   {-1, 7, -1, 4},
   {-1, 7, -1, 4}
   },
   {
   {-1, -1, -1, -1, -1, 6},
   {-1, -1, -1, -1, -1, 6}
   },
   };

   static t_sector const	g_hard_sector[8] = {
   {0, 0, (int*)&g_neighbor[0][0], (int*)&g_neighbor[0][1], -1, 0, 14, -3, 10, 50, {g_hard_v[0], g_hard_v[1], g_hard_v[2], g_hard_v[3], g_hard_v[4], g_hard_v[5], g_hard_v[6]}, 7},
   {6, 1, (int*)g_neighbor[1][0], g_neighbor[1][1], -1, 0, 9, -1, 10, 50, {g_hard_v[1], g_hard_v[7], g_hard_v[8], g_hard_v[2]}, 4},
   {-6, 2, g_neighbor[2][0], g_neighbor[2][1], -1, 0, 20, 0, 10, 50, {g_hard_v[3], g_hard_v[9], g_hard_v[10], g_hard_v[4]}, 4},
   {4, 3, g_neighbor[3][0], g_neighbor[3][1], -1, 5, 4, 0, 10, 50, {g_hard_v[9], g_hard_v[11], g_hard_v[12], g_hard_v[10]}, 4},
   {1, 4, g_neighbor[4][0], g_neighbor[4][1], -1, 50, 20, 2, 10, 50, {g_hard_v[11], g_hard_v[13], g_hard_v[14], g_hard_v[15], g_hard_v[16], g_hard_v[17], g_hard_v[18], g_hard_v[12]}, 8},
   {2, 5, g_neighbor[5][0], g_neighbor[5][1], -1, 10, 15, 4, 10, 50, {g_hard_v[13], g_hard_v[19], g_hard_v[20], g_hard_v[14]}, 4},
   {3, 6, g_neighbor[6][0], g_neighbor[6][1], -1, 0, 35, 10, 10, 50, {g_hard_v[15], g_hard_v[21], g_hard_v[22], g_hard_v[16]}, 4},
   {5, 7, g_neighbor[7][0], g_neighbor[7][1], -1, 0, 40, 25, 10, 50, {g_hard_v[21], g_hard_v[23], g_hard_v[24], g_hard_v[25], g_hard_v[26], g_hard_v[22]},},
   };

   static t_vec2d const	g_vertexes[27] = {
   {32.5, 32.5},//0
   {35, 32.5},//1
   {37.5, 32.5},//2
   {40, 32.5},//3
   {40, 35},//4
   {40, 37.5},//5
   {32.5, 37.5},//6
   {35, 30},//7
   {37.5, 30},//8
   {42.5, 32.5},//9
   {42.5, 35},
   {47.5, 32.5},
   {47.5, 35},
   {50, 30},
   {52.5, 30},
   {55, 32.5},
   {55, 35},
   {52.5, 37.5},
   {50, 37.5},
   {50, 27.5},
   {52.5, 27.5},
{57.5, 32.5},
{57.5, 35},
{57.5, 30},
{62.5, 30},
{62.5, 37.5},
{57.5, 37.5},
	};*/

void		oui(t_env *env)
{
	env->zones = 8;
	if (!(env->sector = (t_sector*)malloc(sizeof(t_sector) * 8)))
		clean(env, E_PARSE);
	if (!(env->sector[0].neighbor = (int*)malloc(sizeof(int) * 7)))
		clean(env, E_PARSE);
	if (!(env->sector[0].door_neighbor = (int*)malloc(sizeof(int) * 7)))
		clean(env, E_PARSE);
	if (!(env->sector[0].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 7)))
		clean(env, E_PARSE);
	env->sector[0].texture = 0;
	env->sector[0].type = 0;
	env->sector[0].data = 0;
	env->sector[0].light = -1;
	env->sector[0].floor = -3;
	env->sector[0].ceil = 14;
	env->sector[0].gravity = 10;
	env->sector[0].friction = 50;
	env->sector[0].points = 7;
	env->sector[0].vertex[0] = v2d(32.5, 32.5);
	env->sector[0].vertex[1] = v2d(35.0, 32.5);
	env->sector[0].vertex[2] = v2d(37.5, 32.5);
	env->sector[0].vertex[3] = v2d(40.0, 32.5);
	env->sector[0].vertex[4] = v2d(40.0, 35.0);
	env->sector[0].vertex[5] = v2d(40.0, 37.5);
	env->sector[0].vertex[6] = v2d(32.5, 37.5);
	env->sector[0].neighbor[0] = -1;
	env->sector[0].neighbor[1] = 1;
	env->sector[0].neighbor[2] = -1;
	env->sector[0].neighbor[3] = -2;
	env->sector[0].neighbor[4] = -1;
	env->sector[0].neighbor[5] = -1;
	env->sector[0].neighbor[6] = -1;
	env->sector[0].door_neighbor[0] = -1;
	env->sector[0].door_neighbor[1] = 1;
	env->sector[0].door_neighbor[2] = -1;
	env->sector[0].door_neighbor[3] = 2;
	env->sector[0].door_neighbor[4] = -1;
	env->sector[0].door_neighbor[5] = -1;
	env->sector[0].door_neighbor[6] = -1;
	if (!(env->sector[1].neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_PARSE);
	if (!(env->sector[1].door_neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_PARSE);
	if (!(env->sector[1].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_PARSE);
	env->sector[1].texture = 1;
	env->sector[1].type = 6;
	env->sector[1].data = 0;
	env->sector[1].light = -1;
	env->sector[1].floor = -1;
	env->sector[1].ceil = 9;
	env->sector[1].gravity = 10;
	env->sector[1].friction = 50;
	env->sector[1].points = 4;
	env->sector[1].vertex[0] = v2d(35.0, 32.5);
	env->sector[1].vertex[1] = v2d(35.0, 30.0);
	env->sector[1].vertex[2] = v2d(37.5, 30.0);
	env->sector[1].vertex[3] = v2d(37.5, 32.5);
	env->sector[1].neighbor[0] = -1;
	env->sector[1].neighbor[1] = -1;
	env->sector[1].neighbor[2] = -1;
	env->sector[1].neighbor[3] = 0;
	env->sector[1].door_neighbor[0] = -1;
	env->sector[1].door_neighbor[1] = -1;
	env->sector[1].door_neighbor[2] = -1;
	env->sector[1].door_neighbor[3] = 0;
	if (!(env->sector[2].neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_PARSE);
	if (!(env->sector[2].door_neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_PARSE);
	if (!(env->sector[2].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_PARSE);
	env->sector[2].texture = 2;
	env->sector[2].type = -6;
	env->sector[2].data = 0;
	env->sector[2].light = -1;
	env->sector[2].floor = 0;
	env->sector[2].ceil = 20;
	env->sector[2].gravity = 10;
	env->sector[2].friction = 50;
	env->sector[2].points = 4;
	env->sector[2].vertex[0] = v2d(40, 32.5);
	env->sector[2].vertex[1] = v2d(42.5, 32.5);
	env->sector[2].vertex[2] = v2d(42.5, 35);
	env->sector[2].vertex[3] = v2d(40, 35);
	env->sector[2].neighbor[0] = -1;
	env->sector[2].neighbor[1] = -1;
	env->sector[2].neighbor[2] = -1;
	env->sector[2].neighbor[3] = -2;
	env->sector[2].door_neighbor[0] = -1;
	env->sector[2].door_neighbor[1] = -1;
	env->sector[2].door_neighbor[2] = -1;
	env->sector[2].door_neighbor[3] = 0;
	if (!(env->sector[3].neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_PARSE);
	if (!(env->sector[3].door_neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_PARSE);
	if (!(env->sector[3].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_PARSE);
	env->sector[3].texture = 3;
	env->sector[3].type = 4;
	env->sector[3].data = 5;
	env->sector[3].light = -1;
	env->sector[3].floor = -3;
	env->sector[3].ceil = 4;
	env->sector[3].gravity = 10;
	env->sector[3].friction = 50;
	env->sector[3].points = 4;
	env->sector[3].vertex[0] = v2d(42.5, 32.5);
	env->sector[3].vertex[1] = v2d(47.5, 32.5);
	env->sector[3].vertex[2] = v2d(47.5, 35);
	env->sector[3].vertex[3] = v2d(42.5, 35);
	env->sector[3].neighbor[0] = -1;
	env->sector[3].neighbor[1] = -2;
	env->sector[3].neighbor[2] = -1;
	env->sector[3].neighbor[3] = -2;
	env->sector[3].door_neighbor[0] = -1;
	env->sector[3].door_neighbor[1] = 1;
	env->sector[3].door_neighbor[2] = -1;
	env->sector[3].door_neighbor[3] = 2;
	if (!(env->sector[4].neighbor = (int*)malloc(sizeof(int) * 7)))
		clean(env, E_PARSE);
	if (!(env->sector[4].door_neighbor = (int*)malloc(sizeof(int) * 7)))
		clean(env, E_PARSE);
	if (!(env->sector[4].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 7)))
		clean(env, E_PARSE);
	env->sector[4].texture = 4;
	env->sector[4].type = 1;
	env->sector[4].data = 50;
	env->sector[4].light = -1;
	env->sector[4].floor = 2;
	env->sector[4].ceil = 20;
	env->sector[4].gravity = 10;
	env->sector[4].friction = 50;
	env->sector[4].points = 8;
	env->sector[4].vertex[0] = v2d(47.5, 32.5);
	env->sector[4].vertex[1] = v2d(50, 30);
	env->sector[4].vertex[2] = v2d(52.5, 30);
	env->sector[4].vertex[3] = v2d(55, 32.5);
	env->sector[4].vertex[4] = v2d(55, 35);
	env->sector[4].vertex[5] = v2d(52.5, 37.5);
	env->sector[4].vertex[6] = v2d(50, 37.5);
	env->sector[4].vertex[7] = v2d(47.5, 35);
	env->sector[4].neighbor[0] = -1;
	env->sector[4].neighbor[1] = 5;
	env->sector[4].neighbor[2] = -1;
	env->sector[4].neighbor[3] = 6;
	env->sector[4].neighbor[4] = -1;
	env->sector[4].neighbor[5] = -1;
	env->sector[4].neighbor[6] = -1;
	env->sector[4].neighbor[6] = 3;
	env->sector[4].door_neighbor[0] = -1;
	env->sector[4].door_neighbor[1] = 5;
	env->sector[4].door_neighbor[2] = -1;
	env->sector[4].door_neighbor[3] = 6;
	env->sector[4].door_neighbor[4] = -1;
	env->sector[4].door_neighbor[5] = -1;
	env->sector[4].door_neighbor[6] = -1;
	env->sector[4].door_neighbor[7] = 3;
	if (!(env->sector[5].neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_PARSE);
	if (!(env->sector[5].door_neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_PARSE);
	if (!(env->sector[5].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_PARSE);
	env->sector[5].texture = 5;
	env->sector[5].type = 2;
	env->sector[5].data = 10;
	env->sector[5].light = -1;
	env->sector[5].floor = 4;
	env->sector[5].ceil = 15;
	env->sector[5].gravity = 10;
	env->sector[5].friction = 50;
	env->sector[5].points = 4;
	env->sector[5].vertex[0] = v2d(50, 30);
	env->sector[5].vertex[1] = v2d(50, 27.5);
	env->sector[5].vertex[2] = v2d(52.5, 27.5);
	env->sector[5].vertex[3] = v2d(52.5, 30);
	env->sector[5].neighbor[0] = -1;
	env->sector[5].neighbor[1] = -1;
	env->sector[5].neighbor[2] = -1;
	env->sector[5].neighbor[3] = 4;
	env->sector[5].door_neighbor[0] = -1;
	env->sector[5].door_neighbor[1] = -1;
	env->sector[5].door_neighbor[2] = -1;
	env->sector[5].door_neighbor[3] = 4;
	if (!(env->sector[6].neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_PARSE);
	if (!(env->sector[6].door_neighbor = (int*)malloc(sizeof(int) * 4)))
		clean(env, E_PARSE);
	if (!(env->sector[6].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 4)))
		clean(env, E_PARSE);
	env->sector[6].texture = 6;
	env->sector[6].type = 3;
	env->sector[6].data = 0;
	env->sector[6].light = -1;
	env->sector[6].floor = 10;
	env->sector[6].ceil = 35;
	env->sector[6].gravity = 10;
	env->sector[6].friction = 50;
	env->sector[6].points = 4;
	env->sector[6].vertex[0] = v2d(55, 32.5);
	env->sector[6].vertex[1] = v2d(57.5, 32.5);
	env->sector[6].vertex[2] = v2d(57.5, 35);
	env->sector[6].vertex[3] = v2d(55, 35);
	env->sector[6].neighbor[0] = -1;
	env->sector[6].neighbor[1] = 7;
	env->sector[6].neighbor[2] = -1;
	env->sector[6].neighbor[3] = 4;
	env->sector[6].door_neighbor[0] = -1;
	env->sector[6].door_neighbor[1] = 7;
	env->sector[6].door_neighbor[2] = -1;
	env->sector[6].door_neighbor[3] = 4;
	if (!(env->sector[7].neighbor = (int*)malloc(sizeof(int) * 6)))
		clean(env, E_PARSE);
	if (!(env->sector[7].door_neighbor = (int*)malloc(sizeof(int) * 6)))
		clean(env, E_PARSE);
	if (!(env->sector[7].vertex = (t_vec2d*)malloc(sizeof(t_vec2d) * 6)))
		clean(env, E_PARSE);
	env->sector[7].texture = 7;
	env->sector[7].type = 5;
	env->sector[7].data = 0;
	env->sector[7].light = -1;
	env->sector[7].floor = 25;
	env->sector[7].ceil = 40;
	env->sector[7].gravity = 10;
	env->sector[7].friction = 50;
	env->sector[7].points = 6;
	env->sector[7].vertex[0] = v2d(57.5, 32.5);
	env->sector[7].vertex[1] = v2d(57.5, 30);
	env->sector[7].vertex[2] = v2d(62.5, 30);
	env->sector[7].vertex[3] = v2d(62.5, 37.5);
	env->sector[7].vertex[4] = v2d(57.5, 37.5);
	env->sector[7].vertex[5] = v2d(57.5, 35);
	env->sector[7].neighbor[0] = -1;
	env->sector[7].neighbor[1] = -1;
	env->sector[7].neighbor[2] = -1;
	env->sector[7].neighbor[3] = -1;
	env->sector[7].neighbor[4] = -1;
	env->sector[7].neighbor[5] = 6;
	env->sector[7].door_neighbor[0] = -1;
	env->sector[7].door_neighbor[1] = -1;
	env->sector[7].door_neighbor[2] = -1;
	env->sector[7].door_neighbor[3] = -1;
	env->sector[7].door_neighbor[4] = -1;
	env->sector[7].door_neighbor[5] = 6;
	env->cam.pos = v3d(33.9, 36.1, 0);
}

int			main_parse(char **av, t_env *env, int ac)
{
	int		fd;
	int		gnl;
	char	*line;
	t_parse	par;
	char	*file;

	file = (ac == 2) ? av[1] : "hard_map";
	if (!ft_strcmp(file, "hard_map"))
	{
		oui(env);
	}
	else
	{
		gnl = ft_isvalidname(av[1], ".data");
		if (gnl == 0)
			exit(1);
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
		if (gnl == -1 || close(fd) || env->cam.pos.x <= -1 || env->cam.pos.y <= -1 || env->zones == 0 || par.total.vert == -1)
			main_err(&par, env, 1);
		tmp(env->sector, env->zones);
		main_err(&par, env, 0);
	}
	return (0);
}
