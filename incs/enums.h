/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:59:50 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/11 12:43:11 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENUMS_H
# define ENUMS_H

/*
**	To switch between menus.
*/

typedef enum	e_win
{
	MENU,
	GAME,
	EDITOR,
	SETTINGS,
	QUIT
}				t_win;

/*
**	List of assets needed to populate the texture's array of structures.
*/

typedef enum	e_assets
{
	MENU_1080P,
	MENU_900P,
	MENU_768P,
	MENU_720P,
	NB_ASSETS
}				t_assets;

/*
**	The different error codes than can be retrived by the program
*/

typedef enum	e_status
{
	NOTHING,
	E_FILENAME,
	E_SDL_INIT,
	E_SDL_WIN,
	E_SDL_WINSURF,
	E_SDL_UPDATE,
	E_TTF_INIT,
	E_TTF_FONT,
	E_TTF_RENDER,
	E_SDL_BLIT,
	E_BMP_PARSE,
	E_BKGD,
	E_MALLOC,
	NB_ERRORS
}				t_status;

#endif
