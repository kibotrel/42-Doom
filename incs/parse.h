/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:27:11 by reda-con          #+#    #+#             */
/*   Updated: 2020/02/14 12:04:01 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdint.h>
# include "core.h"

typedef struct	s_entity
{
	t_vec2d		pos;
	int			sect;
	int			angle;
	int			type;
}				t_entity;

typedef struct	s_player
{
	t_vec2d		pos;
	int			sect;
	int			angle;
}				t_player;

typedef struct	s_total
{
	int			vert;
	int			sect;
	int			emy;
	int			obj;
}				t_total;

typedef struct	s_parse
{
	t_vec2d		*ver;
	t_entity	*emy;
	t_entity	*obj;
	t_sector	*sec;
	t_player	plr;
	t_total		total;
}				t_parse;

/*
**debug.c
*/
void			print_vert(t_vec2d *v, int max);
void			print_en(t_entity *e, int max);
void			print_obj(t_entity *o, int max);
void			print_pt(t_vec2d p);
void			print_sec(t_sector *s, int max);
void			print_plr(t_player p);

/*
**tools.c
*/
void			free_tab(char **tab);
int				ft_isnum(char *num);
void			init_parse(t_parse *p);

int				verif_vertex(t_vec2d *vertex, char **tab);
int				verif_entity(t_entity *ent, char **tab);
int				verif_sector(t_sector *s, char **tab, t_vec2d *v, t_env *env);
void			parse_err(char **t, t_parse *p);
int				main_parse(char **av, t_env *env, int ac);
int				verif_total(t_total *t, char **tab, t_parse *p, t_env *env);
int				verif_player(t_cam *cam, char **tab);
int				verif_blank(char **tab);




//
void			sector_triger(t_env *env);

#endif
