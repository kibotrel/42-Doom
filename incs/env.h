/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:25 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/17 11:00:28 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Useful macros
*/

# define WIN_W			1280
# define WIN_H			720
# define FAILURE		0
# define SUCCESS		1
# define TXT_GAME		" - Game"
# define TXT_MENU		" - Menu"
# define NB_ERRORS		5
# define TXT_EDITOR		" - Editor"
# define TXT_WINDOW		"Doom-Nukem v0.0.1"
# define TITLE_MENU		TXT_WINDOW TXT_MENU


/*
**	Error messages
*/

# define E_SDL_WIN		3
# define E_FILENAME		1
# define E_SDL_INIT		2
# define E_SDL_UPDATE	5
# define E_SDL_WINSURF	4

#endif
