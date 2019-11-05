/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:31:58 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/10/17 14:30:32 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

void	write_ennemy(t_editor *edit, int fd)
{
	t_vertex	*ennemy;

	ennemy = edit->ennemi;
	while (ennemy)
	{
		ft_putstr_fd("ennemy number ", fd);
		ft_putnbr_fd(ennemy->number, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(ennemy->x, fd);
		ft_putstr_fd(" y ", fd);
		ft_putnbr_fd(ennemy->y, fd);
		ft_putchar_fd('\n', fd);
		ennemy = ennemy->next;
	}
		ft_putchar_fd('\n', fd);
}

void		add_ennemy(t_vertex **ennemy, t_vertex *new)
{
	static int		ennemy_num = 0;
	t_vertex		*prev_ennemy;

	new->number = ennemy_num++;
	if (*ennemy == NULL)
		*ennemy = new;
	else
	{
		prev_ennemy = *ennemy;
		while (prev_ennemy->next)
			prev_ennemy = prev_ennemy->next;
		prev_ennemy->next = new;
	}
}

void	get_ennemy(t_editor **edit, int x, int y)
{
	t_vertex	*new_ennemy;
	int			ennemy_sector;

	new_ennemy = create_vertex(x, y);
	ennemy_sector = is_in_sector((*edit), *new_ennemy);
	if (ennemy_sector != -1)
		add_ennemy(&(*edit)->ennemi, new_ennemy);
}

