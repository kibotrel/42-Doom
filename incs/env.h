/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:25 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/19 19:31:03 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Useful macros
*/

# define DEFAULT		64
# define NB_ERRORS		9

/*
**	Environement informations
*/

# define WIN_W			1280
# define WIN_H			720
# define TXT_GAME		" - Game"
# define TXT_MENU		" - Menu"
# define TXT_EDITOR		" - Editor"
# define TXT_SETTINGS	" - Settings"
# define TXT_WINDOW		"Doom-Nukem v0.0.2"
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
