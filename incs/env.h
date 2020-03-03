/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:25 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/05 10:11:02 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Useful values
*/

# define SIZE			6
# define CAM_H			6
# define WIN_H			720
# define WIN_W			1280
# define SNEAK_H		2.5
# define QUEUE_MAX		32
# define MAX_WIDTH		1920
# define RATIO_UI_X		8
# define RATIO_UI_Y		9
# define MARGIN_HEAD	1
# define MARGIN_KNEE	2
# define RATIO_GRID_X	56
# define RATIO_GRID_Y	32
# define MAX_FONT_SIZE	64
# define MENU_W 		500
# define EDIT_W 		1280
# define EDIT_H			820
# define ANGLE 			80
# define SIZE 			6

/*
** String macros
*/

# define M_BKGD			"\033[31;1mError:\033[0m Menu background not available"
# define M_PARSE		"\033[31;1mError:\033[0m Parse error"
# define M_PARSE_FS_LINE		"\033[31;1mError:\033[0m Wrong total line"
# define M_PARSE_VERTEX		"\033[31;1mError:\033[0m Wrong vertex line"
# define M_PARSE_PLAYER		"\033[31;1mError:\033[0m Wrong player line"
# define M_PARSE_SECTOR		"\033[31;1mError:\033[0m Wrong sector line"
# define M_PARSE_BLANK		"\033[31;1mError:\033[0m Wrong blank in map"
# define M_PARSE_NAME		"\033[31;1mError:\033[0m Wrong file name"
# define M_PARSE_OPEN		"\033[31;1mError:\033[0m Can't open map"
# define M_PARSE_GNL		"\033[31;1mError:\033[0m Error in reading map"
# define M_PARSE_CLOSE		"\033[31;1mError:\033[0m Can't close map"
# define M_PARSE_NO_PLAYER		"\033[31;1mError:\033[0m Problem with player in map"
# define M_PARSE_TOTAL		"\033[31;1mError:\033[0m No vertex in map"
# define M_PARSE_NB_VERTEX		"\033[31;1mError:\033[0m Not enough vertex in map"
# define M_PARSE_NB_SECTOR		"\033[31;1mError:\033[0m Not enough sector in map"
# define M_PARSE_NO_TOTAL		"\033[31;1mError:\033[0m Total line must be the first line"
# define M_MALLOC		"\033[31;1mError:\033[0m Can't allocate memory."
# define M_SDL_WIN		"\033[31;1mError:\033[0m Can't create SDL window."
# define M_FILENAME		"\033[31;1mError:\033[0m Incorrect filename (*.data)."
# define M_TTF_FONT		"\033[31;1mError:\033[0m Can't load the given font."
# define M_TTF_INIT		"\033[31;1mError:\033[0m Can't init TTF connexion."
# define M_SDL_BLIT		"\033[31;1mError:\033[0m Can't blit text on the screen."
# define M_SDL_INIT		"\033[31;1mError:\033[0m Can't init SDL connexion."
# define M_BMP_PARSE	"\033[31;1mError:\033[0m Can't load the given BMP file."
# define M_SDL_THREAD	"\033[31;1mError:\033[0m Can't create SDL Thread."
# define M_SDL_UPDATE	"\033[31;1mError:\033[0m Can't update the given frame."
# define M_TTF_RENDER	"\033[31;1mError:\033[0m Can't write text on surface."
# define M_SDL_WINSURF	"\033[31;1mError:\033[0m Can't retrieve window surface."
# define M_AUDIO_DRIVER	"\033[31;1mError:\033[0m No audio driver available."
# define M_FLOAT		"\033[31;1mError:\033[0m Division by zero"
# define M_EDIT_ENTITY	"\033[31;1mError:\033[0m Can't create entity."
# define M_EDIT_PORTAL	"\033[31;1mError:\033[0m Can't create portal."
# define M_EDIT_SECTOR	"\033[31;1mError:\033[0m Can't create new sector."
# define M_E_SECT_PORT	"\033[31;1mError:\033[0m Can't create portals for sect."
# define M_EDIT_TEXT	"\033[31;1mError:\033[0m Can't display text."
# define M_EDIT_VERTEX	"\033[31;1mError:\033[0m Can't create vertex."

# define TITLE_MENU		"Doom-Nukem v0.8.5 - Menu"
# define TITLE_GAME		"Doom-Nukem v0.8.5 - Game"
# define TITLE_EDITOR	"Doom-Nukem v0.8.5 - Editor"
# define TITLE_SETTINGS	"Doom-Nukem v0.8.5 - Settings"

# define MAP_PATH 		"./editor_map.data"

# define TUTO_DMG		"You are taking dommage, sprint with [CONTROL]"
# define TUTO_ELTR		"Now go to the elevator and use [Q] or [E] to move down or up"
# define TUTO_MONEY		"Go to the dark brown room to earn money"
# define TUTO_JETPACK		"Then use Jetpack with [SPACE]"
# define TUTO_CROUCH		"To continue, use [SHIFT] to crouch"
# define TUTO_JUMP		"To go to the next room, you have to jump with [SPACE]"
# define TUTO_DOOR		"Go to the green room and press [E] to open the door"
# define TUTO_MOVE		"Use [W], [Q], [S], [D] to move"

/*
**	Color codes
*/

# define RED			0xFF0000
# define GREEN			0x00FF00
# define YELLOW			0xFFFF00
# define ORANGE			0xFFA500
# define WHITE			0xFFFFFF
# define PRPL 			0x5f287e
# define PINK			0xFF69B4

#endif
