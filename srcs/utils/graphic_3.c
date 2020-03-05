/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:43:32 by lojesu            #+#    #+#             */
/*   Updated: 2020/03/05 12:47:38 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "texture.h"

void	blur(t_env *env, SDL_Surface *win, t_pos p)
{
	int	*px;

	if ((p.x >= 0 && p.x < env->w) && (p.y >= 0 && p.y < env->h))
	{
		px = win->pixels + p.y * win->pitch + p.x * win->format->BytesPerPixel;
		*px = color_add(*px, -45);
	}
}
