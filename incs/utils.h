/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:01:59 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/03 15:29:56 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

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
**	graphic.c
*/

void	draw_background(t_env *env, t_sdl *sdl, t_bmp img);
void	draw_line(t_env *env, t_pos a, t_pos b, uint32_t color);
void	draw_pixel(t_env *env, SDL_Surface *win, t_pos p, uint32_t c);
void	text_to_screen(t_env *env, t_sdl *sdl, char *text, uint8_t pos);

/*
**	data.c
*/

void	paste_position(SDL_Rect *pos, t_pos scale);
void	line_params(t_line *line, t_pos a, t_pos b);
void	police_color(SDL_Color *color, uint8_t r, uint8_t g, uint8_t b);
t_vec2d	vector2d(double x, double y);
t_vec3d	vector3d(double x, double y, double z);

/*
**	maths.c
*/

void	scale_text(t_env *e, SDL_Rect *where, char *text, uint8_t pos);
double	cross(t_vec2d a, t_vec2d b);
double	side(t_vec2d cam, t_vec2d a, t_vec2d b);
double	bound(double x, double min, double max);
uint8_t	overlap(double a, double b, double c, double d);
uint8_t	hitbox(t_vec2d a, t_vec2d b, t_vec2d c, t_vec2d d);
t_vec2d	intersect(t_vec2d a, t_vec2d b, t_vec2d c, t_vec2d d);


/*
**	checks.c
*/

char	*get_string(uint8_t n);
int8_t	dectect_input(int32_t *input);
int8_t	get_dimensions(int32_t height);

#endif
