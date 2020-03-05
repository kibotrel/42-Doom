/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:16:41 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/05 14:20:53 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "clean.h"
#include "libft.h"
#include "setup.h"
#include "utils.h"
#include "editor.h"
#include "struct.h"
#include "settings.h"
#include "texture.h"

static void	error_messages_part2(t_env *env)
{
	env->error[E_P_OPEN] = M_P_OPEN;
	env->error[E_P_GNL] = M_P_GNL;
	env->error[E_P_CLOSE] = M_P_CLOSE;
	env->error[E_P_NO_PLAYER] = M_P_NO_PLAYER;
	env->error[E_P_TOTAL] = M_P_TOTAL;
	env->error[E_P_NB_VERTEX] = M_P_NB_VERTEX;
	env->error[E_P_NB_SECTOR] = M_P_NB_SECTOR;
	env->error[E_P_NO_TOTAL] = M_P_NO_TOTAL;
	env->error[E_SDL_THREAD] = M_SDL_THREAD;
	env->error[E_AUDIO_DRIVER] = M_AUDIO_DRIVER;
	env->error[E_FLOAT] = M_FLOAT;
	env->error[E_EDIT_ENTITY] = M_EDIT_ENTITY;
	env->error[E_EDIT_PORTAL] = M_EDIT_PORTAL;
	env->error[E_EDIT_SECT_PORTAL] = M_E_SECT_PORT;
	env->error[E_EDIT_SECTOR] = M_EDIT_SECTOR;
	env->error[E_EDIT_TEXT] = M_EDIT_TEXT;
	env->error[E_EDIT_VERTEX] = M_EDIT_VERTEX;
	env->error[DEATH] = M_DEATH;
	env->error[WIN] = M_WIN;
}

void		error_messages(t_env *env)
{
	env->error[NOTHING] = "";
	env->error[E_FILENAME] = M_FILENAME;
	env->error[E_SDL_INIT] = M_SDL_INIT;
	env->error[E_SDL_WIN] = M_SDL_WIN;
	env->error[E_SDL_WINSURF] = M_SDL_WINSURF;
	env->error[E_SDL_UPDATE] = M_SDL_UPDATE;
	env->error[E_TTF_INIT] = M_TTF_INIT;
	env->error[E_TTF_FONT] = M_TTF_FONT;
	env->error[E_TTF_RENDER] = M_TTF_RENDER;
	env->error[E_SDL_BLIT] = M_SDL_BLIT;
	env->error[E_BMP_PARSE] = M_BMP_PARSE;
	env->error[E_MALLOC] = M_MALLOC;
	env->error[E_BKGD] = M_BKGD;
	env->error[E_P] = M_P;
	env->error[E_P_FS_LINE] = M_P_FS_LINE;
	env->error[E_P_VERTEX] = M_P_VERTEX;
	env->error[E_P_PLAYER] = M_P_PLAYER;
	env->error[E_P_SECTOR] = M_P_SECTOR;
	env->error[E_P_BLANK] = M_P_BLANK;
	env->error[E_P_NAME] = M_P_NAME;
	error_messages_part2(env);
}
