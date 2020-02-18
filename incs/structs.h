/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:48:17 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/18 09:26:41 by nde-jesu         ###   ########.fr       */
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
	int8_t		background;
	uint8_t		button;
}				t_ui;

typedef struct	s_grid
{
	t_pos		min;
	t_pos		max;
}				t_grid;

typedef struct	s_hud
{
	int8_t		debug;
}				t_hud;

typedef struct	s_data
{
	t_ui		ui;
	t_grid		grid;
	t_hud		hud;
	uint8_t		f_size;
	uint8_t		g_size;
	uint32_t	fps;
	uint32_t	w_size;
}				t_data;

/*
typedef struct	s_sector
{
	int			*neighbor;
	double		ceil;
	double		floor;
	t_vec2d		*vertex;
	uint32_t	points;
}				t_sector;
*/

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
	t_tick		debug;
	t_tick		fps;
	t_tick		frame;
	t_tick		editor;
}				t_time;

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
	t_tick			button;
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

typedef struct		s_effector
{
	t_effects		effects;
	int				money_sec;
	int				cost;
	int				*doors;
}					t_effector;

typedef struct		s_ed_sector
{
	t_vertex		*vertex;
	int				vertex_count;
	int				sector_number;
	int				texture;
	t_effector		effect;
	int				type;
	int				gravity;
	int				friction;
	int				light;
	int				light_value;

	int				h_ceil;
	int				h_floor;

	int				*is_portal;

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
	int8_t			grid;
	int8_t			display_portal;
	int8_t			delete;

	bool			sect_is_closed;
	bool			finish;
}					t_editor;

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
	int32_t		w;
	int32_t		h;
	int32_t		input[SDL_NUM_SCANCODES];
	t_editor	editor;
	t_sector	*sector;
	uint32_t	setup;
	uint32_t	zones;
}				t_env;

#endif
