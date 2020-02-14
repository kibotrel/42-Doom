/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:48:17 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/14 10:27:09 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>
# include <stdbool.h>
# include "SDL.h"
# include "SDL_ttf.h"
# include "bmp.h"
# include "enums.h"

/*
**	Editor structs
*/

typedef struct		s_count
{
	int				vertex;
	int				sector;
	int				enemy;
	int				object;
	int				portal;
}					t_count;

typedef struct		s_ed_player
{
	int				x;
	int				y;
	int				angle;
	int				sector;
}					t_ed_player;

typedef struct		s_ed_entity
{
	int				x;
	int				y;
	int				angle;
	int				type;
	int				number;
	int				sector;
	struct s_ed_entity	*prev;
	struct s_ed_entity	*next;
}					t_ed_entity;

typedef struct		s_vertex
{
	int				x;
	int				y;
	int				vertex_number;
	struct s_vertex	*next;
	struct s_vertex	*prev;
}					t_vertex;

typedef struct		s_portal
{
	t_vertex		extrems[2];
	int				type;
	struct s_portal	*prev;
	struct s_portal	*next;
}					t_portal;

typedef struct		s_ed_sector
{
	t_vertex		*vertex;
	int				vertex_count;
	int				sector_number;
	int				texture;
	int				gravity;
	int				friction;

	int				h_ceil;
	int				h_floor;

	t_portal		*portal;
	int				*is_portal;
	int				*portal_type;

	struct s_ed_sector *prev;
	struct s_ed_sector	*next;

}					t_ed_sector;

typedef struct		s_editor
{
	t_settings		sett;
	t_presets		presets;
	t_count			count;
	bool			map_save;

	t_ed_sector		*sector;
	t_vertex		*vertex;
	t_ed_player		player;
	t_ed_entity		*object;
	t_ed_entity		*enemy;
	t_portal		*portals;

	t_vertex		last_vertex;

	t_vertex		portal_points[2];
	t_ed_sector		*which_sector;
	t_vertex		*ab;
	t_vertex		*cd;

	int				true_grid;
	int				dist_grid;
	bool			grid;

	bool			sect_is_closed;
	bool			finish;
}					t_editor;

/*
**	Position structs
*/


typedef struct	s_pos
{
	int32_t		x;
	int32_t		y;
}				t_pos;

typedef struct	s_vec2d
{
	double		x;
	double		y;
}				t_vec2d;

typedef struct	s_vec3d
{
	double		x;
	double		y;
	double		z;
}				t_vec3d;

typedef struct	s_ui
{
	t_pos		min;
	t_pos		max;
	uint8_t		button;
}				t_ui;

typedef struct	s_grid
{
	t_pos		min;
	t_pos		max;
}				t_grid;

typedef struct	s_hud
{
	int8_t		last_display;
	int32_t		coin_shift;
}				t_hud;

typedef struct	s_data
{
	t_ui		ui;
	t_hud		hud;
	t_grid		grid;
	double		life;
	uint8_t		shot;
	uint8_t		f_size;
	uint8_t		g_size;
	int32_t		ammos;
	int32_t		magazines;
	uint32_t	fps;
	uint32_t	money;
	uint32_t	w_size;
}				t_data;

typedef struct	s_sector
{
	uint32_t	points;
	double		ceil;
	double		floor;
	double		gravity;
	double		friction;
	int			*neighbor;
	int			*portal_type;
	t_vec2d		*vertex;
}				t_sector;

/*
 ** Time tracking
 */

typedef struct	s_tick
{
	uint32_t	new;
	uint32_t	old;
}				t_tick;

typedef struct	s_time
{
	t_tick		fly;
	t_tick		fps;
	t_tick		hud;
	t_tick		shot;
	t_tick		debug;
	t_tick		frame;
	t_tick		purse;
	t_tick		reload;
}				t_time;

/*
**	Main structures.
*/

typedef struct	s_cam
{
	double		cos;
	double		gap;
	double		sin;
	double		angle;
	double		speed;
	t_vec2d		fov;
	t_vec3d		v;
	t_vec3d		pos;
	int8_t		fly;
	uint8_t		fall;
	uint8_t		move;
	uint8_t		sneak;
	uint8_t		ground;
	uint32_t	sector;
}				t_cam;

typedef struct	s_sdl
{
	t_bmp		bmp[NB_ASSETS];
	TTF_Font	*font[3];
	SDL_Event	event;
	SDL_Color	color;
	SDL_Window	*win;
	SDL_Surface	*screen;
}				t_sdl;

typedef struct	s_env
{
	char		*asset[NB_ASSETS];
	char		*error[NB_ERRORS];
	t_cam		cam;
	t_sdl		sdl;
	t_win		win;
	t_data		data;
	t_time		tick;
	t_state		state;
	int32_t		w;
	int32_t		h;
	int32_t		input[SDL_NUM_SCANCODES];
	t_editor	editor;
	t_sector	*sector;
	uint32_t	setup;
	uint32_t	zones;
}				t_env;

#endif
