/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:52:03 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/10/24 13:05:30 by nde-jesu         ###   ########.fr       */
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

typedef struct 		s_line
{
		int			delta_x;
		int			delta_y;
		int			sign_x;
		int			sign_y;
		int			error;
		int			error_2;
}					t_line;

typedef struct 		s_player
{
	int				x;
	int				y;
	int				angle;
}					t_player;

typedef struct 		s_entity
{
	int				x;
	int				y;
	int				type;
	struct s_object	*next;
}					t_entity;

typedef struct		s_vertex
{
	int				x;
	int				y;
	int				vertex_number;
	struct s_vertex	*next;
}					t_vertex;

typedef struct		s_sector
{
	t_vertex		*vertex;
	int				vertex_count;
	int				sector_number;

	int				h_ceil;
	int				f_floor;

	t_bool			is_child;
	int				*is_portal;

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
	int				map_save;

	t_sector		*sector;
	t_player		player;
	t_entity		*object;
	t_entity		*enemy;

	t_vertex		last_vertex;

	t_vertex		portal_point[2];
	t_sector		*which_sector;
	t_vertex		*ab;
	t_vertex		*cd;

	int				dist_grid;
	t_bool			sect_is_closed;
	t_bool			finish;
}					t_editor;

#endif