/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:25 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/17 17:42:07 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Useful macros
*/

# define FAILURE		0
# define SUCCESS		1
# define NB_ERRORS		5

/*
**	Environement informations
*/

# define WIN_W			1280
# define WIN_H			720
# define TXT_GAME		" - Game"
# define TXT_MENU		" - Menu"
# define TXT_EDITOR		" - Editor"
# define TXT_WINDOW		"Doom-Nukem v0.0.1"
# define TITLE_MENU		TXT_WINDOW TXT_MENU

/*
**	Color codes
*/

# define RED			0xFF0000
# define WHITE			0xFFFFFF

/*
**	Enums
*/

typedef enum			e_win
{
	MENU,
	GAME,
	EDITOR,
	SETTINGS
}						t_win;

typedef enum			e_status
{
	NOTHING,
	E_FILENAME,
	E_SDL_INIT,
	E_SDL_WIN,
	E_SDL_WINSURF,
	E_SDL_UPDATE
}						t_status;

#endif
