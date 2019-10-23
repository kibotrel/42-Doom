/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:27:11 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/23 17:02:23 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_vertex
{
	t_point			pt;
	struct s_vertex	*next;
}				t_vertex;

typedef struct	s_ennemy
{
	int				n;
	t_point			pt;
	struct s_ennemy	*next;
}				t_ennemy;

typedef struct	s_object
{
	int				n;
	t_point			pt;
	struct s_object	*next;
}				t_object;

typedef struct	s_height
{
	int			floor;
	int			ceil;
}				t_height;

typedef struct	s_ver_port
{
	int			size;
	int			*vertex;
	int			*portal;
}				t_ver_port;

typedef struct	s_sector
{
	int				n;
	t_height		h;
	t_ver_port		v_p;
	struct s_sector	*next;
}				t_sector;

typedef struct	s_parse
{
	t_vertex	*v;
	t_ennemy	*e;
	t_object	*o;
	t_sector	*s;
	t_point		p;
}				t_parse;

/*
**debug.g
*/
void			print_vert(t_vertex **v);
void			print_en(t_ennemy **e);
void			print_obj(t_object **o);
void			print_pt(t_point p);
void			print_sec(t_sector **s);

/*
**tools.c
*/
t_point			init_pt(int x, int y);
void			free_tab(char **tab);
int				ft_isnum(char *num);
void			init_parse(t_parse *p);
t_height		init_height(int g, int c);

int				verif_ver(t_vertex **v_s, char **tab);
int				verif_en(t_ennemy **e_s, char **tab);
int				verif_obj(t_object **o_s, char **tab);
int				verif_sec(t_sector **s_s, char **tab);

#endif
