/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:31:58 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/09/17 12:02:35 by nde-jesu         ###   ########.fr       */
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
		ft_putstr_fd("ennemy\tnumber ", fd);
		ft_putnbr_fd(ennemy->number, fd);
		ft_putstr_fd(" y ", fd);
		ft_putnbr_fd(ennemy->y, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(ennemy->x, fd);
		ft_putchar_fd('\n', fd);
		ennemy = ennemy->next;
	}
		ft_putchar_fd('\n', fd);
}

void	print_ennemy(t_editor *edit, int color)
{
	t_vertex	*ennemy;

	ennemy = edit->ennemi;
	while (ennemy)
	{
		put_pixel(edit->sdl, ennemy->x, ennemy->y, color);
		put_pixel(edit->sdl, ennemy->x + 1, ennemy->y, color);
		put_pixel(edit->sdl, ennemy->x, ennemy->y + 1, color);
		put_pixel(edit->sdl, ennemy->x - 1, ennemy->y, color);
		put_pixel(edit->sdl, ennemy->x, ennemy->y - 1, color);
		ennemy = ennemy->next;
	}
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

void	get_ennemy(t_editor *edit, int x, int y)
{
	t_vertex	*new_ennemy;

	new_ennemy = create_vertex(x, y);
	add_ennemy(&edit->ennemi, new_ennemy);
}

