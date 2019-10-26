/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:08:43 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/27 00:40:05 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

#include "structs.h"

/*
**	env.c
*/

void	clean(t_env *env, uint8_t error);

/*
**	sdl.c
*/

void	sdl_clean(t_sdl *sdl);

/*
**	ttf.c
*/

void	ttf_clean(t_sdl *sdl);

#endif
