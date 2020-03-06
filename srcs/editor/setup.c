/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:36:42 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/06 08:54:13 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "libft.h"

void			init_portals(t_editor *editor)
{
	editor->portal_points[0].x = -1;
	editor->portal_points[0].y = -1;
	editor->portal_points[1].x = -1;
	editor->portal_points[1].y = -1;
	editor->which_sector = NULL;
	editor->ab = NULL;
	editor->cd = NULL;
}

static void		init_tab_num(char *tab[6], char *tab_2[9])
{
	tab[0] = "0";
	tab[1] = "1";
	tab[2] = "2";
	tab[3] = "3";
	tab[4] = "4";
	tab[5] = "5";
	tab_2[0] = "Sector";
	tab_2[1] = "Player";
	tab_2[2] = "Enemy";
	tab_2[3] = "Object";
	tab_2[4] = "Portal";
	tab_2[5] = "Effect";
	tab_2[6] = "Clear";
	tab_2[7] = "Save";
	tab_2[8] = "Draw Sector Clockwise";
}

static void		init_tab_effectors(char *tab[ALL_EFFECTS])
{
	tab[NONE] = "None";
	tab[EFF_JET] = "Jetpack";
	tab[EFF_MONEY] = "Money";
	tab[EFF_ELEV] = "Elevator";
	tab[EFF_LAVA] = "Lava";
	tab[EFF_HEAL] = "Heal";
	tab[EFF_SKY] = "Sky";
	tab[EFF_END] = "End";
	tab[EFF_PLATE] = "Plate";
}

static void		init_tab(char *tab[4][7])
{
	tab[0][0] = "Select.";
	tab[0][1] = "Floor";
	tab[0][2] = "Roof";
	tab[0][3] = "Text";
	tab[0][4] = "Grav";
	tab[0][5] = "Frict";
	tab[0][6] = "Light";
	tab[1][0] = "Rotate";
	tab[1][1] = "Del.";
	tab[2][0] = "Select.";
	tab[2][1] = "Rotate";
	tab[2][2] = "Del.";
	tab[2][3] = "Type";
	tab[3][0] = "Effect";
	tab[3][1] = "Select";
	tab[3][2] = "Data";
	tab[3][3] = "Cost";
	tab[3][4] = " / sec";
}

void			editor_setup(t_editor *editor)
{
	ft_bzero(editor, sizeof(t_editor));
	editor->true_grid = 1280 / 100;
	editor->grid = 1;
	editor->finish = false;
	editor->display_portal = -1;
	editor->delete = -1;
	editor->sect_is_closed = true;
	editor->last_vertex.x = -1;
	editor->last_vertex.y = -1;
	editor->player.x = -5;
	editor->player.y = -5;
	editor->player.angle = 0;
	init_tab_num(editor->numbers, editor->first_params);
	init_tab_effectors(editor->effector);
	init_tab(editor->tab);
	init_portals(editor);
	init_count(&editor->count);
}
