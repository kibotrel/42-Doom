/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:25 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 15:17:42 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Useful values
*/

# define MIN_UI_X		1200
# define MAX_UI_X		1680
# define RATIO_UI_X		1920
# define RATIO_UI_Y		9
# define MAX_WIDTH		1920
# define MAX_FONT_SIZE	64

/*
** Useful strings
*/

# define E_CODE			"\033[31;1mError:\033[0m "

# define M_SDL_WIN		E_CODE "Can't create SDL window."
# define M_FILENAME		E_CODE "Incorrect filename (*.data)."
# define M_TTF_FONT		E_CODE "Can't load the given font."
# define M_TTF_INIT		E_CODE "Can't initialize TTF connexion."
# define M_SDL_BLIT		E_CODE "Can't blit text with the screen."
# define M_SDL_INIT		E_CODE "Can't initialize SDL connexion."
# define M_BMP_PARSE	E_CODE "Can't parse the given BMP file."
# define M_SDL_UPDATE	E_CODE "Can't update the given frame."
# define M_TTF_RENDER	E_CODE "Can't write text on SDL Surface."
# define M_SDL_WINSURF	E_CODE "Can't retrieve SDL window's surface."

/*
**	Environement informations
*/

# define WIN_W			1920
# define WIN_H			1080

# define TXT_GAME		" - Game"
# define TXT_MENU		" - Menu"
# define TXT_EDITOR		" - Editor"
# define TXT_SETTINGS	" - Settings"
# define TXT_WINDOW		"Doom-Nukem v0.0.3"

# define TITLE_MENU		TXT_WINDOW TXT_MENU
# define TITLE_GAME		TXT_WINDOW TXT_GAME
# define TITLE_EDITOR	TXT_WINDOW TXT_EDITOR
# define TITLE_SETTINGS	TXT_WINDOW TXT_SETTINGS

/*
**	Color codes
*/

# define RED			0xFF0000
# define WHITE			0xFFFFFF

#endif
