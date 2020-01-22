/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:14:22 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/22 14:16:47 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			init_count(t_count *count)
{
	count->vertex = 0;
	count->sector = 0;
	count->enemy = 0;
	count->portal = 0;
	count->object = 0;
}

void			clean(t_editor *editor)
{
	clear_editor(editor);
	if (editor->which_sector)
	{
		delete_sector(&editor->which_sector);
		free(editor->which_sector);
	}
	if (editor->sector)
		free(editor->sector);
	if (editor->vertex)
		free(editor->vertex);
	if (editor->object)
		free(editor->object);
	if (editor->enemy)
		free(editor->enemy);
	if (editor->portals)
		free(editor->portals);
	if (editor->ab)
	{
		delete_vertex(&editor->ab);
		free(editor->ab);
	}
	if (editor->cd)
	{
		delete_vertex(&editor->cd);
		free(editor->ab);
	}
	if (editor->sdl.font)
		TTF_CloseFont(editor->sdl.font);
	if (editor->sdl.win)
		SDL_DestroyWindow(editor->sdl.win);
	if (editor->sdl.surf)
		SDL_FreeSurface(editor->sdl.surf);
	// if (editor)
	// 	free(editor);
	TTF_Quit();
	SDL_Quit();
	exit(1);
}
