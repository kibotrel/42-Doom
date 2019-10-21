/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:13:52 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/21 16:30:49 by reda-con         ###   ########.fr       */
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
		ft_putnbr(tmp->h.floor);
		ft_putstr(" h_ceil=");
		ft_putnbr(tmp->h.ceil);
		ft_putstr(" size_vp=");
		ft_putnbr(tmp->v_p.size);
		ft_putstr(" vertexes=");
		i = -1;
		while (++i < tmp->v_p.size)
		{
			ft_putnbr(tmp->v_p.vertex[i]);
		ft_putchar(' ');
		}
		i = -1;
		ft_putstr(" portals=");
		while (++i < tmp->v_p.size)
		{
			ft_putnbr(tmp->v_p.portal[i]);
		ft_putchar(' ');
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
