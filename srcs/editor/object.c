/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:51:23 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/10/17 14:30:37 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "editor.h"

void	write_object(t_editor *edit, int fd)
{
	t_vertex	*object;

	object = edit->object;
	while (object)
	{
		ft_putstr_fd("object number ", fd);
		ft_putnbr_fd(object->number, fd);
		ft_putstr_fd(" x ", fd);
		ft_putnbr_fd(object->x, fd);
		ft_putstr_fd(" y ", fd);
		ft_putnbr_fd(object->y, fd);
		ft_putchar_fd('\n', fd);
		object = object->next;
	}
		ft_putchar_fd('\n', fd);
}

void		add_object(t_vertex **object, t_vertex *new)
{
	static int		object_num = 0;
	t_vertex		*prev_object;

	new->number = object_num++;
	if (*object == NULL)
		*object = new;
	else
	{
		prev_object = *object;
		while (prev_object->next)
			prev_object = prev_object->next;
		prev_object->next = new;
	}
}

void	get_object(t_editor **edit, int x, int y)
{
	t_vertex	*new_object;
	int			object_sector;

	new_object = create_vertex(x, y);
	object_sector = is_in_sector((*edit), *new_object);
	if (object_sector != -1)
		add_object(&(*edit)->object, new_object);
}