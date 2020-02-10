/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:18:26 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/23 21:03:43 by demonwaves       ###   ########.fr       */
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

	TTF_SizeText(env->sdl.font[0], text, &p.x, &p.y);
	start.x = env->data.ui.min.x;
	start.y = env->data.ui.min.y * pos;
	end.x = env->data.ui.max.x;
	end.y = start.y + env->data.ui.min.y;
	scale.x = start.x + (end.x - (start.x + p.x)) / 2;
	scale.y = start.y + (end.y - (start.y + p.y)) / 2;
	paste_position(where, scale);
}

double	gap(double y, double z, double current_gap)
{
	return (y + z * current_gap);
}

double	bound(double value, double minimum, double maximum)
{
	return (fmin(fmax(value, minimum), maximum));
}

double	vxs(t_vec2d v0, t_vec2d v1)
{
	return (v0.x * v1.y - v1.x * v0.y);
}

int		overlap(double a0, double a1, double b0, double b1)
{
	return ((fmin(a0, a1) <= fmax(b0, b1) && (fmin(b0, b1) <= fmax(a0, a1))));
}
