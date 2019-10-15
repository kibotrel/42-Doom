/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:18:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 21:15:56 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	scale_text(t_env *env, SDL_Rect *where, char *text, int pos)
{
	t_point	end;
	t_point	start;
	t_point	scale;

	TTF_SizeText(env->sdl.font, text, &env->data.size.x, &env->data.size.y);
	start.x = env->data.ui.min.x;
	start.y = env->data.ui.min.y * pos;
	end.x = env->data.ui.max.x;
	end.y = start.y + env->data.ui.min.y;
	scale.x = start.x + (end.x - (start.x + env->data.size.x)) / 2;
	scale.y = start.y + (end.y - (start.y + env->data.size.y)) / 2;
	paste_position(where, scale.x, scale.y);
}
