/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:27:47 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/08 19:28:37 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL_ttf.h"
#include "doom.h"

void	ttf_clean(t_sdl *sdl)
{
	if (sdl->font)
		TTF_CloseFont(sdl->font);
	TTF_Quit();
}
