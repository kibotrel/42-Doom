/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:59:45 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/09/14 11:56:15 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "env.h"
# include "SDL.h"

typedef struct 			s_line
{
	int					delta_x;
	int					delta_y;
	int					sign_x;
	int					sign_y;
	int					error;
	int					error_2;
}						t_line;

typedef struct 			s_vertex
{
	int					x;
	int					y;
	int					number;
	struct s_vertex		*next;
}						t_vertex;

typedef struct          s_sdl
{
    SDL_Window         	*win;
	SDL_Surface			*surf;
    SDL_Event           event;
}                       t_sdl;

typedef struct          s_editor
{
    t_sdl               *sdl;

	t_vertex			*vertex;
    
	int					finish;
	int					dist_grid;
}                       t_editor;

void					events(t_editor ** edit);

void		get_vertex(t_editor **edit, int x, int y);



void		put_pixel(t_sdl *sdl, int x, int y, int color);
void		draw_line(t_sdl *sdl, t_vertex start, t_vertex end, int color);
void		print_grid(t_editor *edit);
#endif