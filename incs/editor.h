#ifndef EDITOR_H
# define EDITOR_H

# include "structs.h"
# include "env.h"

/*
**	setup/setup.c
*/
void				editor_setup(t_editor *editor);
void				init_portals(t_editor *editor);

/*
**	clean/clean.c
*/
void				clean_editor(t_editor *editor);
void				init_count(t_count *count);

/*
**	clean/delete.c
*/
void				delete_vertex(t_vertex **vertex);
void				delete_sector(t_ed_sector **sectors);
void				clear_editor(t_editor *editor);

/*
**	core/events.c
*/
void				events(t_editor *editor);
bool				is_saved(t_editor *editor);
void				editor_mousewheel(t_editor *editor, SDL_Event event);
void				editor_click(t_editor *editor, SDL_Event event);

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
void				display_sector(t_sdl *sdl, t_ed_sector *sectors, bool fl);
void				draw_walls(t_sdl *sdl, t_ed_sector *sect, t_vertex *vertex,
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
void				draw_ed_line(SDL_Surface *surf, t_vertex start, t_vertex end,
	int color);

/*
**	entity/entity.c
*/
void				place_player(t_editor *editor, int x, int y);
void				place_entity(t_editor *editor, int x, int y, int type);

/*
**	entity/entity_part2.c
*/
void				rotate_entity(t_ed_entity *entity, bool rotation);
void				move_in_entities(t_ed_entity **entity, bool way);
void				del_entity(t_ed_entity **entity);

/*
**	menu/picture.c
*/
void				print_params_image(t_editor *edit, t_presets presets,
	t_settings sett);

/*
**	menu/text.c
*/
void				print_param_in_param(t_editor *edit, t_sdl *sdl,
	t_settings sett);
void				print_param_to_screen(t_env *env, t_settings sett,
	t_editor *editor);
void				print_more_minus(t_sdl *sdl);
void	display_text(t_editor *edit, t_sdl *sdl, t_vertex pos,
	const char *text);

/*
**	menu/edit_menu.c
*/
void				editor_motion(t_sdl s, int set, int preset, t_editor *edit);
void				clic_editor_menu(int x, int y, t_editor *editor);

/*
**	menu/edit_menu_utils.c
*/
void				next_blank_menu(int set, SDL_Surface *s);
void				draw_ed_background(SDL_Surface *s);
void				rectangle(t_vertex start, t_vertex end, int clr,
	SDL_Surface *s);
void				square(int x, int y, int color, SDL_Surface *s);
void				blank_menu(SDL_Surface *s, int set, t_editor *edit,
	int preset);

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
void				rotate_player(t_ed_player *player, bool rotation);
void				delete_player(t_ed_player *player);

/*
**	portal/portal.c
*/
void				place_portal(t_editor *editor, int x, int y);

/*
**	portal/portal_utils.c
*/
void				move_in_portals(t_portal **portal, bool way);
void				change_portal_type(t_ed_sector *all, t_portal *portal,
	bool way);
void				add_portal(t_portal **portal, t_vertex v1, t_vertex v2,
	t_editor *edit);
int					compare_coordinates(t_vertex *point, t_vertex *a,
	t_vertex *b);

/*
**	save/map_creation.c
*/
void				create_map(t_editor *editor);
void				write_portals(t_ed_sector *sect, int fd);

/*
**	save/map_creation_part2.c
*/
void				write_vertex_sector(t_ed_sector *sect, t_vertex *all, int fd);
void				write_vertexes(t_vertex *vertexes, int fd);
void				write_entities(t_ed_entity *entities, int fd, bool type);
void				write_player(t_ed_player player, t_vertex if_no_player,
	int fd);
int					search_vertex_num(t_vertex *all, t_vertex *to_find);

/*
**	save/map_creation_utils.c
*/
void				get_elements_number(t_editor *editor, int fd);
int					count_sector(t_ed_sector *all_sector);

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
void				next_display_sector(t_sdl *sdl, t_ed_sector *sectors);
void				move_in_sector(t_ed_sector **sector, bool way);

/*
**	sector/sector_utils.c
*/
t_ed_sector			*create_sector(t_editor *edit);

/*
**	sector/sector_check.c
*/
int					is_in_sector(t_editor *edit, t_vertex point);
int					intersects_count(t_vertex v1, t_vertex v2, t_vertex p1,
	t_vertex p2);

/*
**	keyboard.c
*/
void				editor_keyboard(t_env *env, t_editor *edit);

#endif
