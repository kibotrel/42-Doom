/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:25 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/16 01:32:17 by vivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Useful values
*/

# define SIZE			6
# define CAM_H			6
# define ANGLE 			80
# define WIN_H			720
# define WIN_W			1280
# define SNEAK_H		2.5
# define QUEUE_MAX		32
# define MAX_WIDTH		1920
# define RATIO_UI_X		8
# define RATIO_UI_Y		9
# define MARGIN_HEAD	1
# define MARGIN_KNEE	2
# define RATIO_GRID_Y	32
# define RATIO_GRID_X	56
# define MAX_FONT_SIZE	64

/*
** String macros
*/

# define M_P			"DEPRECATED"
# define M_BKGD			"\033[31;1mError:\033[0m Resolution not supported"
# define M_FLOAT		"DEPRECATED"
# define M_P_GNL		"\033[31;1mError:\033[0m Unable to build line from file"
# define M_MALLOC		"\033[31;1mError:\033[0m Can't allocate memory."
# define M_P_NAME		"DEPRECATED"
# define M_P_OPEN		"\033[31;1mError:\033[0m Can't open the given file"
# define M_THREAD		"\033[31;1mError:\033[0m Can't create a thread."
# define M_P_BLANK		"\033[31;1mError:\033[0m Junk data in the map"
# define M_P_CLOSE		"\033[31;1mError:\033[0m Can't close the given file"
# define M_P_TOTAL		"\033[31;1mError:\033[0m Invalid vertex amount"
# define M_SDL_WIN		"\033[31;1mError:\033[0m Can't create SDL window."
# define M_FILENAME		"\033[31;1mError:\033[0m Incorrect filename (*.data)."
# define M_P_PLAYER		"\033[31;1mError:\033[0m Misformated player location"
# define M_P_SECTOR		"\033[31;1mError:\033[0m Misformated sector declaration"
# define M_P_VERTEX		"\033[31;1mError:\033[0m Misformated vertex declaration"
# define M_SDL_BLIT		"\033[31;1mError:\033[0m Can't blit text on the screen."
# define M_SDL_INIT		"\033[31;1mError:\033[0m Can't init SDL connexion."
# define M_TTF_FONT		"\033[31;1mError:\033[0m Can't load the given font."
# define M_TTF_INIT		"\033[31;1mError:\033[0m Can't init TTF connexion."
# define M_BMP_PARSE	"\033[31;1mError:\033[0m Can't load the given BMP file."
# define M_P_FS_LINE	"\033[31;1mError:\033[0m Misformated map header"
# define M_P_NO_TOTAL	"\033[31;1mError:\033[0m Missing header informormations"
# define M_SDL_UPDATE	"\033[31;1mError:\033[0m Can't update the given frame."
# define M_TTF_RENDER	"\033[31;1mError:\033[0m Can't write text on surface."
# define M_P_NB_SECTOR	"\033[31;1mError:\033[0m Incorrect sector amount"
# define M_P_NB_VERTEX	"\033[31;1mError:\033[0m Incorrect vertex amount"
# define M_P_NO_PLAYER	"\033[31;1mError:\033[0m Invalid player position"
# define M_SDL_WINSURF	"\033[31;1mError:\033[0m Can't retrieve window surface."

# define M_AUDIO_DRIVER	"\033[31;1mError:\033[0m No audio driver available."
# define M_EDIT_ENTITY	"\033[31;1mError:\033[0m Can't create entity."
# define M_EDIT_PORTAL	"\033[31;1mError:\033[0m Can't create portal."
# define M_EDIT_SECTOR	"\033[31;1mError:\033[0m Can't create new sector."
# define M_E_SECT_PORT	"\033[31;1mError:\033[0m Can't create portals for sect."
# define M_EDIT_TEXT	"\033[31;1mError:\033[0m Can't display text."
# define M_EDIT_VERTEX	"\033[31;1mError:\033[0m Can't create vertex."
# define M_DEATH		"\033[31;1mYou died !\033[0m"
# define M_WIN			"\033[32;1mYou win !\033[0m"
# define M_AUDIO_OPEN	"\033[32;1mError :\033[0m Can't open sound stream"
# define M_AUDIO_CLOSE	"\033[32;1mError :\033[0m Can't close sound stream"
# define M_DEVICE_OPEN	"\033[31;1mError:\033[0m Can't open audio device."
# define M_DEVICE_CLOSE "\033[31;1mError:\033[0m Can't close audio device."

# define TITLE_MENU		"Doom-Nukem v0.8.5 - Menu"
# define TITLE_GAME		"Doom-Nukem v0.8.5 - Game"
# define TITLE_EDITOR	"Doom-Nukem v0.8.5 - Editor"
# define TITLE_SETTINGS	"Doom-Nukem v0.8.5 - Settings"

# define TUTO_DMG		"You are taking dommage, sprint with [CONTROL]"
# define TUTO_ELTR		"Now go to the elevator and use [Q]/[E] to move down/up"
# define TUTO_MONEY		"Go to the dark brown room to earn money"
# define TUTO_JETPACK	"Then use Jetpack with [SPACE]"
# define TUTO_CROUCH	"To continue, use [SHIFT] to crouch"
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
