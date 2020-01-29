/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:27:47 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 07:29:38 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	ttf_clean(t_sdl *sdl)
{
	if (sdl->font[0])
		TTF_CloseFont(sdl->font[0]);
	if (sdl->font[1])
		TTF_CloseFont(sdl->font[1]);
	TTF_Quit();
}
