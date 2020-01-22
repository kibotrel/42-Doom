/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:14:22 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/22 09:52:20 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			clean(t_editor *editor)
{
	clear_editor(editor);
	if (editor->which_sector)
		delete_sector(&editor->which_sector);
	if (editor->ab)
		delete_vertex(&editor->ab);
	if (editor->cd)
		delete_vertex(&editor->cd);
	if (editor->sdl.font)
		TTF_CloseFont(editor->sdl.font);
	if (editor->sdl.win)
		SDL_DestroyWindow(editor->sdl.win);
	if (editor->sdl.surf)
		SDL_FreeSurface(editor->sdl.surf);
	TTF_Quit();
	SDL_Quit();
	exit(1);
}
