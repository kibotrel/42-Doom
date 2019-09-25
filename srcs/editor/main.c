/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:58:31 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/09/25 17:15:49 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "SDL.h"
#include "editor.h"
#include "libft.h"

// Replace exits with real functions (with some free)

void	init_editor(t_editor **edit)
{
	SDL_Init(SDL_INIT_VIDEO);
	(*edit)->dist_grid = WIN_W / 50;	
	(*edit)->sett = vertex;
	if (!((*edit)->sdl = (t_sdl*)ft_memalloc(sizeof(t_sdl))))
		exit(0);	
	(*edit)->sdl->win = SDL_CreateWindow("DNME", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, 0);
	if ((*edit)->sdl->win == NULL)
		exit(1);
	(*edit)->sdl->surf = SDL_GetWindowSurface((*edit)->sdl->win);
	if (!((*edit)->sdl->surf))
		exit(1);
	(*edit)->finish = 1;
	(*edit)->player.number = 0;
}

int		main(int ac, char **av)
{
    t_editor    *edit;

	(void)av;

    if (ac == 2)
    {
		if (!(edit = (t_editor*)ft_memalloc(sizeof(t_editor))))
			exit(1);
        init_editor(&edit);
		events(&edit);
		create_map(edit);
    }
}