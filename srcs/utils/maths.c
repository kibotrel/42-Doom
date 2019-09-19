/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:18:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/19 19:23:17 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "SDL_ttf.h"
#include "doom.h"

void	scale_text(t_env *env, t_sdl *sdl, char *text, int pos)
{
	t_point	end;
	t_point	start;
	t_point	scale;

	TTF_SizeText(sdl->font, text, &sdl->size.x, &sdl->size.y);
	start.x = env->data.ui.x;
	start.y = env->data.ui.y * pos;
	end.x = start.x + env->data.ui.x;
	end.y = start.y + env->data.ui.y;
	scale.x = start.x + (end.x - (start.x + sdl->size.x)) / 2;
	scale.y = start.y + (end.y - (start.y + sdl->size.y)) / 2;
	paste_position(&sdl->pos, scale.x, scale.y);
}
