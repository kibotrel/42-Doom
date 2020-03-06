/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:01:39 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 09:56:13 by reda-con         ###   ########.fr       */
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
