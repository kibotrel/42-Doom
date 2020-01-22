/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:52:03 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/22 11:50:37 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include <stdbool.h>
# include "SDL.h"
# include "SDL_ttf.h"
# include "bmp.h"

/*
**	MACROS
*/
# define R 0xff0000
# define WHITE 0xffffff
# define EDIT_W 1280
# define MENU_W 500
# define WIN_H 720
# define MAP_PATH "./editor_map.data"
# define PRPL 0x5f287e
# define TITLE "Doom-Nukem v0.1.1 - Editor"

/*
**	ENUMS
*/
typedef enum		e_settings
{
	SECTOR,
	WALL,
	PORTAL,
	PLAYER,
	ENEMY,
	OBJECT,
}					t_settings;

typedef enum		e_presets
{
	NONE,
	SECTOR_FLOOR,
	SECTOR_CEIL,
	SECTOR_TEXT,
	SECTOR_MOVE,
	SECTOR_GRAV,
	SECTOR_VISC,
	ENTITY_TYPE,
	ENTITY_MOVE,
	ENTITY_ROTATE,
	PLAYER_ROTATE,
	PORTAL_MOVE,
	PORTAL_TYPE
}					t_presets;
/*
**	STRUCTS
*/

typedef struct		s_line
{
	int				delta_x;
	int				delta_y;
	int				sign_x;
	int				sign_y;
	int				error;
	int				error_2;
}					t_line;

typedef struct		s_count
{
	int				vertex;
	int				sector;
	int				enemy;
	int				object;
	int				portal;
}					t_count;

typedef struct		s_player
{
	int				x;
	int				y;
	int				angle;
	int				sector;
}					t_player;

typedef struct		s_entity
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
	struct s_vertex	*prev;
}					t_vertex;

typedef struct		s_portal
{
	t_vertex		extrems[2];
	int				type;
	struct s_portal	*prev;
	struct s_portal	*next;
}					t_portal;

typedef struct		s_sector
{
	t_vertex		*vertex;
	int				vertex_count;
	int				sector_number;
	int				texture;
	int				gravity;
	int				viscosity;

	int				h_ceil;
	int				h_floor;

	t_portal		*portal;
	int				*is_portal;
	int				*portal_type;

	struct s_sector *prev;
	struct s_sector	*next;

}					t_sector;

typedef	struct		s_sdl
{
	t_bmp			bmp[4][4];
	SDL_Window		*win;
	SDL_Surface		*surf;
	SDL_Event		event;
	TTF_Font		*font;
	SDL_Color		color;
}					t_sdl;

typedef struct		s_editor
{
	t_sdl			sdl;
	t_settings		sett;
	t_presets		presets;
	t_count			count;
	bool			map_save;

	t_sector		*sector;
	t_vertex		*vertex;
	t_player		player;
	t_entity		*object;
	t_entity		*enemy;
	t_portal		*portals;

	t_vertex		last_vertex;

	t_vertex		portal_points[2];
	t_sector		*which_sector;
	t_vertex		*ab;
	t_vertex		*cd;

	int				dist_grid;
	bool			sect_is_closed;
	bool			finish;
}					t_editor;

/*
**	setup/setup.c
*/
void				init_editor(t_editor *editor);
void				init_portals(t_editor *editor);

/*
**	clean/clean.c
*/
void				clean(t_editor *editor);
void				init_count(t_count *count);

/*
**	clean/delete.c
*/
void				delete_vertex(t_vertex **vertex);
void				delete_sector(t_sector **sectors);
void				clear_editor(t_editor *editor);

/*
**	core/events.c
*/
void				events(t_editor *editor);

/*
**	core/events_tools.c
*/
void				next_keydown(SDL_Event event, SDL_Surface *s,
	t_editor *editor);
void				change_value(t_editor *editor, t_presets presets, bool fl);

/*
**	display/display.c
*/
void				display_grid(t_editor *editor);
void				display_line(t_editor *editor, int x, int y);
void				display_sector(t_sdl *sdl, t_sector *sectors, bool fl);
void				draw_walls(t_sdl *sdl, t_sector *sect, t_vertex *vertex,
	int color);
void				display_portals(t_portal *portal, t_sdl *sdl, int color,
	bool fl);

/*
**	display/display_part2.c
*/
void				which_entity_to_display(t_editor *edit);
void				display_mouse(t_sdl *sdl, t_vertex mouse, int color);
void				display_vertex(t_sdl *sdl, t_vertex *vertex, int color);

/*
**	display/display_utils.c
*/
void				put_fov(SDL_Surface *surf, t_vertex pt, int agl, int color);
void				put_pixel(SDL_Surface *surf, int x, int y, int color);
void				draw_line(SDL_Surface *surf, t_vertex start, t_vertex end,
	int color);

/*
**	entity/entity.c
*/
void				place_player(t_editor *editor, int x, int y);
void				place_entity(t_editor *editor, int x, int y, int type);

/*
**	entity/entity_part2.c
*/
void				rotate_entity(t_entity *entity, bool rotation);
void				move_in_entities(t_entity **entity, bool way);
void				del_entity(t_entity **entity);

/*
**	menu/picture.c
*/
void				print_params_image(t_editor *edit, t_presets presets,
	t_settings sett);

/*
**	menu/text.c
*/
void				print_param_in_param(t_sdl *sdl, t_settings sett);
void				print_param_to_screen(t_sdl *sdl, t_settings sett,
	t_editor *editor);
void				print_more_minus(t_sdl *sdl);

/*
**	menu/edit_menu.c
*/
void				motion(t_sdl s, int set, int preset);
void				clic_editor_menu(int x, int y, t_editor *editor);

/*
**	menu/edit_menu_utils.c
*/
void				next_blank_menu(int set, SDL_Surface *s);
void				draw_background(SDL_Surface *s);
void				rectangle(t_vertex start, t_vertex end, int clr,
	SDL_Surface *s);
void				square(int x, int y, int color, SDL_Surface *s);
void				blank_menu(SDL_Surface *s, int set, t_sdl sdl, int preset);

/*
**	menu/sec_edit_menu.c
*/
void				sec_clic_menu_editor(int y, t_editor *editor);
void				sec_blank_menu(SDL_Surface *s, int set, int preset);

/*
**	menu/sec_edit_menu_utils.c
*/
void				next_sec_clic_menu_editor_tool(int y, t_editor *editor);
void				sec_clic_menu_editor_tool(int y, t_editor *editor);

/*
**	player/player.c
*/
void				rotate_player(t_player *player, bool rotation);
void				delete_player(t_player *player);

/*
**	portal/portal.c
*/
void				place_portal(t_editor *editor, int x, int y);

/*
**	portal/portal_utils.c
*/
void				move_in_portals(t_portal **portal, bool way);
void				change_portal_type(t_sector *all, t_portal *portal,
	bool way);
void				add_portal(t_portal **portal, t_vertex v1, t_vertex v2,
	t_editor *edit);
int					compare_coordinates(t_vertex *point, t_vertex *a,
	t_vertex *b);

/*
**	save/map_creation.c
*/
void				create_map(t_editor *editor);
void				write_portals(t_sector *sect, int fd);

/*
**	save/map_creation_part2.c
*/
void				write_vertex_sector(t_sector *sect, t_vertex *all, int fd);
void				write_vertexes(t_vertex *vertexes, int fd);
void				write_entities(t_entity *entities, int fd, bool type);
void				write_player(t_player player, t_vertex if_no_player,
	int fd);
int					search_vertex_num(t_vertex *all, t_vertex *to_find);

/*
**	save/map_creation_utils.c
*/
void				get_elements_number(t_editor *editor, int fd);
int					count_sector(t_sector *all_sector);

/*
**	sector/vertex.c
*/
t_vertex			*get_vertex(t_editor *editor, int x, int y);
void				add_vertex(t_vertex **vertex, t_vertex v,
	bool flag, t_editor *edit);
t_vertex			*create_vertex(t_vertex v, t_editor *edit);
t_vertex			init_vertex(int x, int y);

/*
**	sector/sector.c
*/
void				place_sector(t_editor *editor, int x, int y);

/*
**	sector/sector_part2.c
*/
void				next_display_sector(t_sdl *sdl, t_sector *sectors);
void				move_in_sector(t_sector **sector, bool way);

/*
**	sector/sector_utils.c
*/
t_sector			*create_sector(t_editor *edit);

/*
**	sector/sector_check.c
*/
int					is_in_sector(t_editor *edit, t_vertex point);
int					intersects_count(t_vertex v1, t_vertex v2, t_vertex p1,
	t_vertex p2);

#endif
