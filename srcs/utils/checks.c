/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 01:42:15 by kibotrel          #+#    #+#             */
/*   Updated: 2019/12/16 21:07:31 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int8_t	dectect_input(int32_t *input)
{
	uint16_t	i;

	i = 0;
	while (i < SDL_NUM_SCANCODES)
		if (input[i++])
			return (1);
	return (0);
}

int8_t	get_dimensions(int32_t height)
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

char	*get_string(uint8_t n)
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

int8_t	cycle_check(t_game *var, t_item *now)
{
	*now = *var->tail;
	if (++var->tail == var->queue + 32)
		var->tail = var->queue;
	if (var->render[now->sector] >= 32)
		return (1);
	else
	{
		var->render[now->sector]++;
		return (0);
	}
}
