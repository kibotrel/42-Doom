/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <lojesu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:25:58 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/05 12:30:28 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include "structs.h"
# include "env.h"

# define RESET 0xFFFFFF
# define HIDE 0x969696

# define FOG_START_X 35
# define FOG_START_Y 5
# define FOG_SIZE 7
# define FOG_INTENSITY_SIZE 3

# define BORDER_START_X 35
# define BORDER_START_Y 9
# define BORDER_SIZE 7

# define FLY_START_X 35
# define FLY_START_Y 11
# define FLY_SIZE 7

# define MODE_START_X 35
# define MODE_START_Y 13
# define MODE_SIZE 4

# define RES_START_X 36
# define RES_START_Y 15
# define RES_SIZE 4

# define FOV_START_X 37
# define FOV_START_Y 17
# define FOV_SIZE 2

# define FPS_START_X 35
# define FPS_START_Y 19
# define FPS_SIZE 2

# define LIGHT_START_X 36
# define LIGHT_START_Y 21
# define LIGHT_SIZE 5

# define EASY 1
# define NORMAL 2
# define HARD 3

# define FPS_UNLIMITED -1

/*
** settings/settings_keyboard,
** function which did somethings when you touch a key
*/
void		settings_keyboard(t_env *env);

/*
** settings/settings_click,
** function which did somethings when you click somewhere
*/
void		settings_click(t_env *env);

/*
** settings/setting_tools,
** draw the background darker
*/
void		my_draw_background(t_env *e, t_sdl *s, t_bmp img);

/*
** settings/settings_tools,
** change text color
*/
void		my_police_color(SDL_Color *color, uint32_t color_hex);

/*
** settings/settings_tools,
** put on and off in great color at corresponding lines
*/
void		draw_on_off
	(t_env *env, t_vec2d start, uint32_t color_1, uint32_t color_2);

/*
** settings/settings_tools,
** pdate fov
*/
void		fov_update(t_env *env, int mode);

/*
** settings/draw_arrow_setting,
** for change the resolution with arrows
*/
void		draw_resolution(t_env *env);

/*
** settings/draw_arrow_setting,
** for change the FOV with arrows
*/
void		draw_fov(t_env *env);

/*
** settings/draw_arrow_setting,
** for change the intensity's light with arrows
*/
void		draw_light_intensity(t_env *env);

/*
** settings/draw_on_off_setting,
** for activate/desactivate fog of war
*/
void		draw_fog_of_war(t_env *env);

/*
** settings/draw_on_off_setting,
** for activate/desactivate sector border
*/
void		draw_sector_borders(t_env *env);

/*
** settings/draw_on_off_setting,
** for activate/desactivate the fly mode
*/
void		draw_fly_mode(t_env *env);

/*
** settings/draw_selector_setting,
** for change mode
*/
void		draw_mode(t_env *env);

/*
** settings/draw_selector_setting,
** for change FPS
*/
void		draw_fps(t_env *env);

/*
** settings/settings_click_tools.c,
** for check if you click in good box
*/
bool		check_great_click
	(t_env *env, t_vec2d start, int size, int size_click);

/*
** settings/settings_click_tools.c,
** for click on button on and off
*/
void		click_on_off(t_env *env, t_vec2d start, int size, bool *on_off);

/*
** settings/settings_click_tools.c,
** for click on arrows and change the index
*/
void		click_arrow
	(t_env *env, t_vec3d start, int8_t *index, int8_t index_max);

/*
** settings/resize_window,
** for resize the window
*/
void		resize_window(t_env *env);
#endif
