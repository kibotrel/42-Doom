/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:02:10 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/28 11:39:44 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "structs.h"

/*
**	game.c
*/

void	game(t_env *env, int ac, char **av);

/*
**	hooks.c
*/

void	global_hooks(t_env *env, t_sdl *sdl);

/*
**	menu.c
*/

void	menu(t_env *env);
void	draw_ui(t_env *env);
void	draw_button(t_env *env, t_ui ui, uint32_t color, uint8_t n);

/*
**	editor.c
*/

void	editor(t_env *env);

/*
**	selector.c
*/

void	selector(t_env *env, int ac, char **av);

/*
**	settings.c
*/

void	settings(t_env *env);

/*
**	tuto.c
*/

void	tuto(t_env *env);

#endif
