/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:01:59 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/02 18:03:17 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "game.h"
# include "structs.h"

typedef struct		s_line
{
	t_pos			sign;		// Slope of the line
	t_pos			delta;		// Global error
	int32_t			error;		// Current error
	int32_t			offset;		// size of the line
}					t_line;

/*
**	usage.c
*/

void	usage(void);

/*
**	graphic_0.c
*/

void	draw_background(t_env *env, t_sdl *sdl, t_bmp img);
void	draw_line(t_env *env, t_pos a, t_pos b, uint32_t color);
void	draw_pixel(t_env *env, SDL_Surface *win, t_pos p, uint32_t c);
void	text_to_screen(t_env *env, t_sdl *sdl, char *text, uint8_t pos);
void	draw_slice(t_env *env, int x, int y1, int y2, int top, int middle, int bottom);

/*
**	graphic_1.c
*/

void	draw_screen(t_env *env, t_game *var);

/*
**	data_0.c
*/

void	paste_position(SDL_Rect *pos, t_pos scale);
void	line_params(t_line *line, t_pos a, t_pos b);
void	police_color(SDL_Color *color, uint8_t r, uint8_t g, uint8_t b);
t_vec2d	v2d(double x, double y);
t_vec3d	v3d(double x, double y, double z);

/*
**	data_1.c
*/

t_item	item(uint32_t sector, uint32_t min, uint32_t max);

/*
**	maths_0.c
*/

int		hitbox(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3);
void	scale_text(t_env *e, SDL_Rect *where, char *text, uint8_t pos);
double	gap(double y, double z, double current_gap);
double	vxs(double x0, double y0, double x1, double y1);
double	bound(double value, double minimum, double maximum);

/*
**	maths_1.c
*/

int		overlap(double a0, double a1, double b0, double b1);
void	vproj(t_vec3d *v, t_vec2d v1, t_vec2d v2);
void	velocity(t_env *env, t_cam *cam, t_vec2d v);
double	side(double px, double py, double x0, double y0, double x1, double y1);
t_vec2d	intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

/*
**	checks.c
*/

char	*get_string(uint8_t n);
void	check_depth(t_game *var, int32_t start, int32_t end);
int8_t	dectect_input(int32_t *input);
int8_t	get_dimensions(int32_t height);
int8_t	cycle_check(t_env *env, t_game *var, t_item *now);

/*
**	engine.c
*/

void	transform(t_cam *cam, t_game *var, uint32_t i);
uint8_t	bound_view(t_game *var);
uint8_t	scale(t_env *env, t_game *var, t_item *now);

#endif
