/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 01:42:15 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/16 01:48:32 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "enums.h"

int	dectect_input(int *input)
{
	int	i;

	i = -1;
	while (++i < SDL_NUM_SCANCODES)
		if (input[i])
			return (1);
	return (0);
}

int		get_dimensions(int height)
{
	if (height == 1080)
		return (MENU_1080P);
	if (height == 900)
		return (MENU_900P);
	if (height == 768)
		return (MENU_768P);
	if (height == 720)
		return (MENU_720P);
	else
		return (-1);
}

char	*get_string(int n)
{
	if (n == 1)
		return ("GAME");
	if (n == 3)
		return ("EDITOR");
	if (n == 5)
		return ("SETTINGS");
	if (n == 7)
		return ("QUIT");
	else
		return (NULL);
}
