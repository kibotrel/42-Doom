/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:43:02 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/25 04:55:20 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "game.h"

/*
**	setup.c
*/

void	env_setup(t_env *env);

/*
**	graphic.c
*/

void	graphic_setup(t_env *env, t_sdl *sdl);

/*
**	game_0.c
*/

void	game_setup(t_env *env, t_game *var);
void	skybox_setup(t_env *env, t_skybox *skybox);
void	draw_setup(t_env *env, t_game *var, t_item *now, uint32_t i);

/*
**	game_1.c
*/

void	floor_and_ceil_setup(t_cam *cam, t_game *var);

/*
**	hud.c
*/

void	setup_debug_sector(t_sector *sector, char **str);
void	setup_debug_cam(t_env *env, t_cam *cam, char **str);

#endif
