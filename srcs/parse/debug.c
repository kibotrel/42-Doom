/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:13:52 by reda-con          #+#    #+#             */
/*   Updated: 2020/01/23 10:32:12 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

void		print_pt(t_vec2d p)
{
	ft_putstr("pt: x=");
	ft_putnbr(p.x);
	ft_putstr("; y=");
	ft_putnbr(p.y);
}

void		print_plr(t_player p)
{
	ft_putstr("player: pos=");
	print_pt(p.pos);
	ft_putstr(" sector=");
	ft_putnbr(p.sect);
	ft_putstr(" angle=");
	ft_putnbr(p.angle);
		ft_putchar('\n');
}

void		print_vert(t_vec2d *v, int max)
{
	int		i;

	i = -1;
	while (++i < max)
	{
		ft_putstr("vertex: ");
		print_pt(v[i]);
		ft_putchar('\n');
	}
}

void		print_en(t_entity *e, int max)
{
	int		i;

	i = -1;
	while (++i < max)
	{
		ft_putstr("entity: post=");
		print_pt(e[i].pos);
		ft_putstr(" sect=");
		ft_putnbr(e[i].sect);
		ft_putstr(" angle=");
		ft_putnbr(e[i].angle);
		ft_putstr(" type=");
		ft_putnbr(e[i].type);
		ft_putchar('\n');
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

void		print_sec(t_sector *s, int max)
{
	int			i;
	int			j;

	i = -1;
	while (++i < max)
	{
		ft_putstr("sector: pts=");
		ft_putnbr(s[i].pts);
		ft_putstr(" h_floor=");
		ft_putnbr(s[i].floor);
		ft_putstr(" h_ceil=");
		ft_putnbr(s[i].ceil);
		ft_putstr(" gravity=");
		ft_putnbr(s[i].gravity);
		ft_putstr(" viscosity=");
		ft_putnbr(s[i].viscosity);
		ft_putstr(" vertexes=");
		j = -1;
		while (++j < (int)s[i].pts)
		{
			print_pt(s[i].vert[j]);
			ft_putchar(';');
		}
		j = -1;
		ft_putstr(" portals=");
		while (++j < (int)s[i].pts)
		{
			ft_putnbr(s[i].portal[j]);
			ft_putchar(' ');
		}
		j = -1;
		ft_putstr(" portals type=");
		while (++j < (int)s[i].pts)
		{
			ft_putnbr(s[i].portal_type[j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
