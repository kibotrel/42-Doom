/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:01:39 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/22 15:01:40 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game.h"

void	engine_clean(t_game *var)
{
	if (var->top)
		free(var->top);
	if (var->bottom)
		free(var->bottom);
	if (var->render)
		free(var->render);
}
