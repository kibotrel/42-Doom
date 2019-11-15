/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:18:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/11/11 11:12:09 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"

void	scale_text(t_env *env, SDL_Rect *where, char *text, uint8_t pos)
{
	t_vec	p;
	t_pos	end;
	t_pos	start;
	t_pos	scale;

	TTF_SizeText(env->sdl.font, text, &p.x, &p.y);
	start.x = env->data.ui.min.x;
	start.y = env->data.ui.min.y * pos;
	end.x = env->data.ui.max.x;
	end.y = start.y + env->data.ui.min.y;
	scale.x = start.x + (end.x - (start.x + p.x)) / 2;
	scale.y = start.y + (end.y - (start.y + p.y)) / 2;
	paste_position(where, scale);
}
