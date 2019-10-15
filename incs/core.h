/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:02:10 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 19:05:05 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "structs.h"

/*
**	game.c
*/

void	game(t_env *env);

/*
**	hooks.c
*/

void	hooks(t_env *env, t_sdl *sdl);

/*
**	menu.c
*/

void	menu(t_env *env);
void	draw_ui(t_env *env);
void	draw_button(t_env *env, t_ui ui, int color, int n);

/*
**	editor.c
*/

void	editor(t_env *env);

/*
**	selector.c
*/

void	selector(t_env *env);

/*
**	settings.c
*/

void	settings(t_env *env);

#endif
