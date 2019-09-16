/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:54:25 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/16 12:24:53 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Useful macros
*/

# define WIN_W			620
# define WIN_H			480
# define TITLE			"Doom-Nukem v0.0.1"
# define FAILURE		0
# define SUCCESS		1
# define NB_ERRORS		4

/*
**	Error messages
*/

# define E_SDL_WIN		3
# define E_FILENAME		1
# define E_SDL_INIT		2
# define E_SDL_WINSURF	4

#endif
