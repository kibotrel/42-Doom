/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:01:59 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/27 00:37:22 by demonwaves       ###   ########.fr       */
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

/*
**	maths.c
*/

void	scale_text(t_env *e, SDL_Rect *where, char *text, uint8_t pos);

/*
**	checks.c
*/

char	*get_string(uint8_t n);
int8_t	dectect_input(int32_t *input);
int8_t	get_dimensions(int32_t height);
#endif
