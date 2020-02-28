/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:59:50 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/28 17:09:25 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

# define NB_FRAMES	64
# define NB_THREADS	4

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
	BG_MENU,
	ED_TEXT_1,
	ED_TEXT_2,
	ED_TEXT_3,
	ED_TEXT_4,
	ED_TEXT_5,
	ED_TEXT_6,
	ED_TEXT_7,
	ED_TEXT_8,
	ED_TEXT_9,
	ED_TEXT_10,
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
	SHOTGUN,
	MAGAZINE,
	SHELL,
	COIN,
	SKYBOX,
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
	E_PARSE,
	E_SDL_THREAD,
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
	EFFECTOR
}					t_settings;

typedef enum		e_effects
{
	EFF_NONE,
	EFF_JET,
	EFF_ELEV,
	EFF_SKY,
	EFF_FLY,
	EFF_MONEY,
	EFF_SPIKE,
	EFF_GEN,
	EFF_END
}					t_effects;

typedef enum		e_presets
{
	NONE,
	SECTOR_MOVE,
	SECTOR_FLOOR,
	SECTOR_CEIL,
	SECTOR_TEXT,
	SECTOR_TYPE,
	SECTOR_GRAV,
	SECTOR_FRICTION,
	SECTOR_LIGHT,
	ENTITY_TYPE,
	ENTITY_MOVE,
	ENTITY_ROTATE,
	PLAYER_ROTATE,
	EFF_EFFECT,
	EFF_MOVE,
	EFF_COST
}					t_presets;

/*
**	Enum for game state
*/

typedef enum		e_state
{
	PLAY,
	DEBUG,
	INVENTORY,
	SCREENSHOT
}					t_state;

#endif
