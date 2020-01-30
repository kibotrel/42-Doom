/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:59:50 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/30 12:02:03 by nde-jesu         ###   ########.fr       */
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
	ED_TEXT_1,
	ED_TEXT_2,
	ED_TEXT_3,
	ED_TEXT_4,
	ED_OBJ_1,
	ED_OBJ_2,
	ED_OBJ_3,
	ED_OBJ_4,
	ED_ENEMY_1,
	ED_ENEMY_2,
	ED_ENEMY_3,
	ED_ENEMY_4,
	ED_PORTAL_DOOR,
	ED_PORTAL_WALL,
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

/*
**	Enums needed by the editor
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
	SECTOR_MOVE,
	SECTOR_FLOOR,
	SECTOR_CEIL,
	SECTOR_TEXT,
	SECTOR_GRAV,
	SECTOR_FRICTION,
	ENTITY_TYPE,
	ENTITY_MOVE,
	ENTITY_ROTATE,
	PLAYER_ROTATE,
	PORTAL_MOVE,
	PORTAL_TYPE
}					t_presets;

#endif
