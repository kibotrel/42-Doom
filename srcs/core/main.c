/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:47:35 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/01/22 11:33:05 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "libft.h"

/*
** PENSER AUX FREES ET METTRE LES FONCTIONS POSSIBLES EN STATIC
*/

int				main(void)
{
	t_editor	editor;

	init_editor(&editor);
	events(&editor);
	return (1);
}
