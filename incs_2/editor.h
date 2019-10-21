/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:52:03 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/10/21 14:56:16 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "SDL.h"

/*
**	MACROS
*/

# define WIN_W 1280
# define WIN_H 720 

/* 
**	ENUMS
*/

typedef enum		e_bool
{
	TRUE,
	FALSE
}					t_bool;

typedef enum		e_settings
{
	VERTEX, // Place points
	WALL, // Connect two points
	PORTAL, // Transform a wall into a portal
	PLAYER, // Place the player
	ENEMY, // Place enemies
	OBJECT // Place objects
}					t_settings;

/*
**	STRUCTS
*/

typedef struct 		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_vertex
{
	t_point			coord;
	int				vertex_number;
	struct s_vertex	*next;
}					t_vertex;

typedef struct 		s_player
{
	t_point			coord;
		
}					t_player;

typedef struct		s_wall
{
	t_vertex		points[2];
	t_bool			is_portal;
	
	struct s_wall	*next;
}					t_wall;

typedef struct		s_sector
{
	t_vertex		*vertex;
	int				vertex_count;

	int				h_ceil;
	int				f_floor;

	struct s_sector	*next;
}					t_sector;

typedef	struct		s_sdl
{
	SDL_Window		*win; //editor window
	SDL_Surface		*surf; //Surface for the window
	SDL_Event		event;// Mouse and keyboard events
}					t_sdl;

typedef struct		s_editor
{
	t_sdl			sdl;
	t_settings		sett;
	t_sector		*sector;
	t_wall			*wall;

	int				dist_grid;
}					t_editor;

#endif