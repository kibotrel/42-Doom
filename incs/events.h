/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:25:01 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/04 14:53:55 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "structs.h"

/*
**	keyboard.c
*/

void	handle_keyboard(t_env *env);

/*
**	mouse.c
*/

void	handle_mouse(t_env *env, t_sdl *sdl);

/*
**	motion.c
*/

void	handle_motion(t_env *env, t_sdl *sdl);

#endif
