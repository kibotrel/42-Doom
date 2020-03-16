/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:08:43 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/16 01:34:08 by vivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

# include "game.h"

/*
**	env.c
*/

void	free_map(t_env *env);
void	clean(t_env *env, uint8_t error);

/*
**	sdl.c
*/

void	sdl_clean(t_sdl *sdl);

/*
**	ttf.c
*/

void	ttf_clean(t_sdl *sdl);

/*
**	engine.c
*/

void	engine_clean(t_game *var);

/*
**	audio.c
*/

void	audio_clean(t_env *env);

#endif
