/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:01:59 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/23 20:16:43 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "game.h"

typedef struct		s_line
{
	t_pos			sign;
	t_pos			delta;
	int32_t			error;
	int32_t			offset;
}					t_line;

typedef struct		s_palette
{
	int				top;
	int				middle;
	int				bottom;
}					t_palette;

typedef struct		s_height
{
	int				top;
	int				bottom;
}					t_height;

/*
**	usage.c
*/

void				usage(void);

/*
**	graphic_0.c
*/

void				draw_slice(t_env *env, int x, t_height y, t_palette c);
void				draw_background(t_env *env, t_sdl *sdl, t_bmp img);
void				draw_line(t_env *env, t_pos a, t_pos b, uint32_t color);
void				draw_pixel(t_env *env, SDL_Surface *w, t_pos p, uint32_t c);
void				text_to_screen(t_env *env, t_sdl *sdl, char *txt,
									uint8_t p);

/*
**	graphic_1.c
*/

void				draw_screen(t_env *env, t_game *var);

/*
**	data_0.c
*/

void				paste_position(SDL_Rect *pos, t_pos scale);
void				line_params(t_line *line, t_pos a, t_pos b);
void				police_color(SDL_Color *c, uint8_t r, uint8_t g, uint8_t b);
t_vec2d				v2d(double x, double y);
t_vec3d				v3d(double x, double y, double z);

/*
**	data_1.c
*/

void				fps_counter(t_env *env);
void				side_infos(t_game *var);
t_item				item(uint32_t sector, uint32_t min, uint32_t max);
t_height			lim(int y1, int y2);
t_palette			flat(int top, int middle, int bottom);

/*
**	maths_0.c
*/

int					hitbox(t_vec2d v0, t_vec2d v1, t_vec2d v2, t_vec2d v3);
void				scale_text(t_env *e, SDL_Rect *where, char *text,
								uint8_t pos);
double				gap(double y, double z, double current_gap);
double				vxs(t_vec2d v0, t_vec2d v1);
double				bound(double value, double minimum, double maximum);

/*
**	maths_1.c
*/

int					overlap(double a0, double a1, double b0, double b1);
void				vproj(t_vec3d *v, t_vec2d v1, t_vec2d v2);
void				velocity(t_env *env, t_cam *cam, t_vec2d v);
double				side(t_vec2d p, t_vec2d v0, t_vec2d v1);
t_vec2d				intersect(t_vec2d v1, t_vec2d v2, t_vec2d v3, t_vec2d v4);

/*
**	checks_00.c
*/

char				*get_string(uint8_t n);
void				check_depth(t_game *var, int32_t start, int32_t end);
int8_t				dectect_input(int32_t *input);
int8_t				get_dimensions(int32_t height);
int8_t				cycle_check(t_env *env, t_game *var, t_item *now);

/*
**	checks_01.c
*/

void				speed_check(t_env *env);

/*
**	engine.c
*/

void				transform(t_cam *cam, t_game *var, uint32_t i);
uint8_t				bound_view(t_game *var);
uint8_t				scale(t_env *env, t_game *var, t_item *now);

#endif
