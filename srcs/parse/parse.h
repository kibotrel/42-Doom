/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:27:11 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/16 17:02:15 by reda-con         ###   ########.fr       */
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

/*
**debug.g
*/
void			print_vert(t_vertex **v);
void			print_en(t_ennemy **e);
void			print_obj(t_object **o);
void			print_pt(t_point p);

/*
**tools.c
*/
t_point			init_pt(int x, int y);
void			free_tab(char **tab);
int				ft_isnumber(char *num);

void			verif_ver(t_vertex **v_s, char **tab);
void			verif_en(t_ennemy **e_s, char **tab);
void			verif_obj(t_object **o_s, char **tab);

#endif
