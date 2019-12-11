/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:52:03 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/12/11 16:41:26 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include <stdbool.h>
# include "SDL.h"
# include "SDL_ttf.h"

/*
**	MACROS
*/

# define R 0xff0000
# define EDIT_W 1280
# define MENU_W 500
# define WIN_H 720
# define MAP_PATH "./map/editor_map.data"
# define PRPL 0x5f287e
# define TITLE "Doom-Nukem v0.1.1 - Editor"

/* 
**	ENUMS
*/

typedef enum		e_settings
{
	SECTOR, // Place points
	WALL, // Connect two points
	PORTAL, // Transform a wall into a portal
	PLAYER, // Place the player
	ENEMY, // Place enemies
	OBJECT, // Place objects
	MODIFY_SECTOR
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
	int				sector;
}					t_player;

typedef struct 		s_entity
{
	int				x;
	int				y;
	int				angle;
	int				type;
	int				number;
	int				sector;
	struct s_entity	*prev;
	struct s_entity	*next;
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
	int				h_floor;

	int				points_inside;

	int				is_child;
	int				*is_portal;

	struct s_sector *prev;
	struct s_sector	*next;
}					t_sector;

typedef	struct		s_sdl
{
	SDL_Window		*win; //editor window
	SDL_Surface		*surf; //Surface for the window
	SDL_Event		event;// Mouse and keyboard events
	TTF_Font		*font;
	SDL_Color		color;
}					t_sdl;

typedef struct		s_editor
{
	t_sdl			sdl;
	t_settings		sett;
	bool			map_save;

	t_sector		*sector;
	t_vertex		*vertex;
	t_player		player;
	t_entity		*object;
	t_entity		*enemy;

	t_vertex		last_vertex;

	t_vertex		portal_points[2];
	t_sector		*which_sector;
	t_vertex		*ab;
	t_vertex		*cd;

	int				dist_grid;
	bool			sect_is_closed;
	bool			finish;
}					t_editor;

#endif

//	main.c

void				init_portals(t_editor *editor);

//	display_part1.c

void				display_grid(t_editor *editor);
void				display_line(t_editor *editor, int x, int y);
void				display_sector(t_sdl *sdl, t_sector *sectors, bool fl);

//	display_part2.c

void				display_vertex(t_sdl *sdl, t_vertex *vertex, int color);
void				display_entities(t_sdl *sdl, t_entity *entity, int color, bool fl);
void				display_mouse(t_sdl *sdl, t_vertex mouse, int color);

//	display_utils.c

void				put_pixel(SDL_Surface *surf, int x, int y, int color);
void				draw_line(SDL_Surface *surf, t_vertex start, t_vertex end, int color);

//	elements_writing.c

void				write_vertex_sector(t_sector *sect, t_vertex *all, int fd);
void				write_vertexes(t_vertex *vertexes, int fd);
void				write_entities(t_entity *entities, int fd, bool type);
void				write_player(t_player player, t_vertex if_no_player, int fd);

//	entity.c

void				place_player(t_editor *editor, int x, int y);
void				place_entity(t_editor *editor, int x, int y, int type);

//	entity2.c

void				change_ent_type(t_entity *ent);

//	events.c

void				events(t_editor *editor);

//	events_tools.c

void				next_keydown(SDL_Event event, SDL_Surface *surf, t_editor *editor);

//	map_creation.c

int					search_vertex_num(t_vertex *all, t_vertex *to_find);
void				write_portals(t_sector *sect, int fd);
void				create_map(t_editor *editor);

//	portal_utils.c

int					compare_coordinates(t_vertex *point, t_vertex *a, t_vertex *b);
void				init_portals(t_editor *edit);

//	portal.c

void				place_portal(t_editor *editor, int x, int y);

//	sector_check.c

int					intersects_count(t_vertex v1, t_vertex v2, t_vertex p1, t_vertex p2);
int					is_in_sector(t_editor *edit, t_vertex point);
bool				is_in_this_sector(t_vertex point, t_sector *sector);

//	sector_check_2.c

void				add_tmp_sector(t_sector *new, t_sector **lst);
int					check_which_sector(t_sector *sectors);

//	sector_utils.c

t_sector			*create_sector(void);

//	sector.c

void				place_sector(t_editor *editor, int x, int y);

//	vertex.c

t_vertex			*create_vertex(int x, int y);
void				add_vertex(t_vertex **vertex, int x, int y, bool flag);
t_vertex			*get_vertex(t_editor *editor, int x, int y);

//	edit_menu.c

void				motion(t_sdl sdl, int sett);	
void				blank_menu(SDL_Surface *surf, int set, t_sdl sdl);
void				clic_editor_menu(int x, int y, t_editor *editor);

//	edit_menu_tools.c

void				square(int x, int y, int clr, SDL_Surface *surf);
void				rectangle(t_vertex start, t_vertex end, int clr, SDL_Surface *surf);
t_vertex			init_vertex(int x, int y);
void				draw_back_ground(SDL_Surface *surf);
void				next_blank_menu(int set, SDL_Surface *surf);

//	height.c

void				change_sector_height(t_editor *editor, int x, int y);

//	text.c

void				print_param_to_screen(t_sdl *sdl);
void				print_param_in_param(t_sdl *sdl, t_settings sett);

//	player.c

void				delete_player(t_player *player);
void				rotate_player(t_player *player, bool rotation);

//	delete.c

void				clear_editor(t_editor *editor);


//tmp
//
void				rotate_entity(t_entity *entity, bool rotation);
void				move_in_entities(t_entity **entity, bool way);
void				del_entity(t_entity **entity);
void				put_fov(SDL_Surface *surf, t_vertex pt, int agl, int color);
