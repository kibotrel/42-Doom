/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:13:52 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/17 16:19:19 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/incs/libft.h"
#include "parse.h"

void		print_pt(t_point p)
{
	ft_putstr("pt: x=");
	ft_putnbr(p.x);
	ft_putstr("; y=");
	ft_putnbr(p.y);
	ft_putchar('\n');
}

void		print_vert(t_vertex **v)
{
	t_vertex	*tmp;

	tmp = *v;
	while (tmp)
	{
		ft_putstr("vertex: ");
		print_pt(tmp->pt);
		tmp = tmp->next;
	}
}

void		print_en(t_ennemy **e)
{
	t_ennemy	*tmp;

	tmp = *e;
	while (tmp)
	{
		ft_putstr("ennemy: number=");
		ft_putnbr(tmp->n);
		ft_putstr(" ");
		print_pt(tmp->pt);
		tmp = tmp->next;
	}
}

void		print_obj(t_object **o)
{
	t_object	*tmp;

	tmp = *o;
	while (tmp)
	{
		ft_putstr("object: number=");
		ft_putnbr(tmp->n);
		ft_putstr(" ");
		print_pt(tmp->pt);
		tmp = tmp->next;
	}
}

void		print_tab(char **t)
{
	int		i;

	i = 0;
	while (t[i])
	{
		ft_putendl(t[i]);
		++i;
	}
	ft_putchar('\n');
}

void		print_sec(t_sector **s)
{
	t_sector	*tmp;
	int			i;

	tmp = *s;
	while (tmp)
	{
		ft_putstr("sector: number=");
		ft_putnbr(tmp->n);
		ft_putstr(" h_floor=");
		ft_putnbr(tmp->h_floor);
		ft_putstr(" h_ceil=");
		ft_putnbr(tmp->h_ceil);
		ft_putstr(" size_vp=");
		ft_putnbr(tmp->size_vp);
		i = -1;
		ft_putstr(" vertexes=");
		while (++i < tmp->size_vp)
		{
			ft_putnbr(tmp->vertexes[i]);
			ft_putchar(' ');
		}
		i = -1;
		ft_putstr(" portals=");
		while (++i < tmp->size_vp)
		{
			ft_putnbr(tmp->portals[i]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
