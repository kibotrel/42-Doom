/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:14:22 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/07 14:14:59 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			clean(t_editor *edit)
{
	clear_editor(edit);
	if (edit->which_sector)
		free(edit->which_sector);
	if (edit->ab)
		free(edit->ab);
	if (edit->cd)
		free(edit->cd);
	free(edit->sdl.assets);
	if (edit->sdl.win)
		free(edit->sdl.win);
	if (edit->sdl.surf)
		free(edit->sdl.surf);
	if (edit->sdl.font)
		free(edit->sdl.font);
	exit(1);
}
