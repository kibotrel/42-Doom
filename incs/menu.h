/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:24:54 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/14 13:04:04 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# include "structs.h"

/*
**	click.c
*/

void	menu_click(t_env *env, t_ui ui, int x, int y);

/*
**	motion.c
*/

void	menu_hover(t_env *env, t_ui ui, int x, int y);
void	cam_motion(t_env *env, t_cam *cam, int x, int y);

#endif
