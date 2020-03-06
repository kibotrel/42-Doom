/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 01:42:15 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 10:45:14 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
	if (height != 1080 && height != 900 && height != 768 && height != 720)
		return (-1);
	else
		return (1);
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

int8_t	cycle_check(t_env *env, t_game *var, t_item *now)
{
	*now = *var->tail;
	if (++var->tail == var->queue + 32)
		var->tail = var->queue;
	if (var->render[now->sector] >= 32)
		return (1);
	else
	{
		var->s = &env->sector[now->sector];
		var->render[now->sector]++;
		return (0);
	}
}

void	check_depth(t_game *var, int32_t start, int32_t end)
{
	if (var->n >= 0 && end >= start && (var->head - var->tail + 33) % 32)
	{
		*var->head = item(var->n, start, end);
		if (++var->head == var->queue + 32)
			var->head = var->queue;
	}
}
