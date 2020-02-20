/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:48:17 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/20 10:24:30 by reda-con         ###   ########.fr       */
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
**	Miscellaneous structs
*/

typedef struct			s_pos
{
	int32_t				x;
	int32_t				y;
}						t_pos;

typedef struct			s_vec2d
{
	double				x;
	double				y;
}						t_vec2d;

typedef struct			s_vec3d
{
	double				x;
	double				y;
	double				z;
}						t_vec3d;

typedef struct			s_ui
{
	t_pos				min;
	t_pos				max;
	uint8_t				button;
}						t_ui;

typedef struct			s_grid
{
	t_pos				min;
	t_pos				max;
}						t_grid;

typedef struct			s_anime
{
	int32_t				frame;
	int32_t				shift;
}						t_anime;

typedef struct			s_hud
{
	int8_t				last_display;
	t_anime				coin;
	t_anime				shotgun;
}						t_hud;

typedef struct			s_data
{
	t_ui				ui;
	t_hud				hud;
	t_grid				grid;
	double				life;
	uint8_t				shot;
	uint8_t				f_size;
	uint8_t				g_size;
	int32_t				ammos;
	int32_t				magazines;
	uint32_t			fps;
	uint32_t			money;
	uint32_t			w_size;
}						t_data;

typedef struct			s_tick
{
	uint32_t			new;
	uint32_t			old;
}						t_tick;

typedef struct			s_time
{
	t_tick				fly;
	t_tick				fps;
	t_tick				hud;
	t_tick				shot;
	t_tick				debug;
	t_tick				frame;
	t_tick				purse;
	t_tick				reload;
	t_tick				editor;
	t_tick				sector_triger;
}						t_time;

/*
**	Editor structs
*/

typedef struct			s_count
{
	int					enemy;
	int					object;
	int					portal;
	int					sector;
	int					vertex;
	t_tick				button;
}						t_count;

typedef struct			s_ed_player
{
	int					x;
	int					y;
	int					angle;
	int					sector;
}						t_ed_player;

typedef struct			s_ed_entity
{
	int					x;
	int					y;
	int					type;
	int					number;
	int					sector;
	int					angle;
	struct s_ed_entity	*prev;
	struct s_ed_entity	*next;
}						t_ed_entity;

typedef struct			s_vertex
{
	int					x;
	int					y;
	int					vertex_number;
	struct s_vertex		*prev;
	struct s_vertex		*next;
}						t_vertex;

typedef struct			s_portal
{
	int					type;
	t_vertex			extrems[2];
	struct s_portal		*next;
	struct s_portal		*prev;
}						t_portal;

typedef struct		s_effector
{
	t_effects		effects;
	int				money_sec;
	int				cost;
	int				*doors;
}					t_effector;
typedef struct			s_ed_sector
{
	int					type;
	int					light;
	int					h_ceil;
	int					h_floor;
	int					gravity;
	int					texture;
	int					friction;
	int					*is_portal;
	int					light_value;
	int					vertex_count;
	int					sector_number;
	t_vertex			*vertex;
	t_effector			effect;
	struct s_ed_sector	*next;
	struct s_ed_sector	*prev;
}						t_ed_sector;

typedef struct			s_sector
{
	int					type;
	int					*link;
	int					texture;
	int					*neighbor;
	int					num_link;
	int					*doors_neighbor;
	int					light;
	double				ceil;
	double				floor;
	double				gravity;
	double				friction;
	t_vec2d				*vertex;
	uint32_t			points;
}						t_sector;

/*
**	Main structures.
*/

typedef struct			s_editor
{
	int					true_grid;
	int					dist_grid;
	bool				finish;
	bool				map_save;
	bool				sect_is_closed;
	int8_t				grid;
	int8_t				delete;
	int8_t				display_portal;
	t_count				count;
	t_portal			*portals;
	t_vertex			*ab;
	t_vertex			*cd;
	t_vertex			last_vertex;
	t_vertex			portal_points[2];
	t_presets			presets;
	t_settings			sett;
	t_ed_entity			*object;
	t_ed_entity			*enemy;
	t_ed_player			player;
	t_ed_sector			*sector;
	t_ed_sector			*which_sector;
}						t_editor;

typedef struct			s_cam
{
	double				cos;
	double				gap;
	double				sin;
	double				angle;
	double				speed;
	t_vec2d				fov;
	t_vec3d				v;
	t_vec3d				pos;
	int8_t				fly;
	uint8_t				fall;
	uint8_t				move;
	uint8_t				sneak;
	uint8_t				ground;
	uint32_t			sector;
}						t_cam;

typedef struct			s_sdl
{
	t_bmp				bmp[NB_ASSETS];
	TTF_Font			*font[3];
	SDL_Event			event;
	SDL_Color			color;
	SDL_Window			*win;
	SDL_Surface			*screen;
}						t_sdl;

typedef struct			s_env
{
	char				*asset[NB_ASSETS];
	char				*error[NB_ERRORS];
	t_cam				cam;
	t_sdl				sdl;
	t_win				win;
	t_data				data;
	t_time				tick;
	t_state				state;
	int32_t				w;
	int32_t				h;
	int32_t				input[SDL_NUM_SCANCODES];
	t_editor			editor;
	t_sector			*sector;
	uint32_t			setup;
	uint32_t			zones;
	uint32_t				st_fl;
	uint32_t				old_st_fl;
}						t_env;

#endif
