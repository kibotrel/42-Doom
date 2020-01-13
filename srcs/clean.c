/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:14:22 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/13 11:25:52 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			afficher_portal(t_portal *portal)
{
	while (portal)
	{
		printf("oui\n");
		portal = portal->next;
	}
}

void			clean(t_editor *edit)
{
	afficher_portal(edit->portal);
	clear_editor(edit);
	if (edit->which_sector)
		delete_sector(&edit->which_sector);
	if (edit->ab)
		delete_vertex(&edit->ab);
	if (edit->cd)
		delete_vertex(&edit->cd);
	if (edit->sdl.font)
		TTF_CloseFont(edit->sdl.font);
	if (edit->sdl.win)
		SDL_DestroyWindow(edit->sdl.win);
	if (edit->sdl.surf)
		SDL_FreeSurface(edit->sdl.surf);
	TTF_Quit();
	SDL_Quit();
	exit(1);
}
