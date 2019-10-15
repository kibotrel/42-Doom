/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:01:59 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 19:07:41 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"

/*
**	usage.c
*/

void	usage(void);

/*
**	graphic.c
*/

void	draw_background(t_env *env, t_sdl *sdl, t_bmp img);
void	draw_line(t_env *env, t_point a, t_point b, int color);
void	draw_pixel(t_env *env, SDL_Surface *win, t_point p, int c);
void	text_to_screen(t_env *env, t_sdl *sdl, char *text, int pos);

/*
**	data.c
*/

int		get_dimensions(int height);
char	*get_string(int n);
void	paste_position(SDL_Rect *pos, int x, int y);
void	line_params(t_line *line, t_point a, t_point b);
void	police_color(SDL_Color *color, int r, int g, int b);

/*
**	maths.c
*/

void	scale_text(t_env *e, SDL_Rect *where, char *text, int pos);

#endif
