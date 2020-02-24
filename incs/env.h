/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:25 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/24 05:53:04 by demonwaves       ###   ########.fr       */
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

# define TITLE_MENU		"Doom-Nukem v0.8.5 - Menu"
# define TITLE_GAME		"Doom-Nukem v0.8.5 - Game"
# define TITLE_EDITOR	"Doom-Nukem v0.8.5 - Editor"
# define TITLE_SETTINGS	"Doom-Nukem v0.8.5 - Settings"

# define MAP_PATH 		"./editor_map.data"

/*
**	Color codes
*/

# define RED			0xFF0000
# define GREEN			0x00FF00
# define YELLOW			0xFFFF00
# define ORANGE			0xFFA500
# define WHITE			0xFFFFFF
# define PRPL 			0x5f287e

#endif
