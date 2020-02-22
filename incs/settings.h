/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:25:58 by lojesu            #+#    #+#             */
/*   Updated: 2020/02/22 18:48:52 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SETTINGS_H
# define SETTINGS_H

# include "struct.h"
# include "env.h"

# define RESET 0xFFFFFF
# define HIDE 0x969696

# define FOG_START_X 35
# define FOG_START_Y 5
# define FOG_SIZE 7

# define BORDER_START_X 35
# define BORDER_START_Y 7
# define BORDER_SIZE 7


/*
** settings/settings_keyboard, function which did somethings when you touche a key
*/
void		settings_keyboard(t_env *env);

/*
** settings/settings_click, function which did somethings when you click somewhere
*/
void		settings_click(t_env *env, SDL_Event event);

/*
** settings/setting_utils, draw the background darker
*/
void		my_draw_background(t_env *e, t_sdl *s, t_bmp img);

/*
** settings/settings_tools, change text color
*/
void		my_police_color(SDL_Color *color, uint32_t color_hex);

/*
** settings/settings_tools, put on and off in great color at corresponding lines
*/
void    draw_on_off
	(t_env *env, t_vec2d start, uint32_t color_1, uint32_t color_2);

#endif
