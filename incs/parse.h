/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:27:11 by reda-con          #+#    #+#             */
/*   Updated: 2020/03/03 11:23:41 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdint.h>
# include "core.h"

typedef struct	s_parse
{
	t_vec2d		*ver;
	int			total;
	int			nb;
	int			fsl;
}				t_parse;


/*
**tools.c
*/
void			free_tab(char **tab);
int				ft_isnum(char *num);
void			init_parse(t_parse *p);

int				verif_vertex(t_vec2d *vertex, char **tab, int *nb, t_parse *p);
int				verif_sector(t_sector *s, char **tab, t_vec2d *v, t_env *env);
void			parse_err(char **t, t_parse *p, t_env *env, uint8_t tag);
int				main_parse(char **av, t_env *env, int ac);
int				verif_total(char **tab, t_parse *p, t_env *env);
int				verif_player(t_cam *cam, char **tab);
int				verif_blank(char **tab);

void			hard_map_one(t_env *env);
void			hard_map_six(t_env *env);
void			hard_map_last(t_env *env);

void			main_err(t_parse *p, t_env *env, int fl, uint8_t tag);


//
void			sector_triger(t_env *env);
void			poor(t_env *env);

#endif
