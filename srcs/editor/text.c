/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:12:38 by nde-jesu          #+#    #+#             */
/*   Updated: 2020/03/06 10:12:25 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "editor.h"
#include "utils.h"

void			display_text(int color, t_vertex pos, const char *text,
	t_env *env)
{
	SDL_Rect	where;
	SDL_Surface	*tmp;
	int			error;

	where.x = pos.x;
	where.y = pos.y;
	error = 0;
	police_color(&env->sdl.color, color >> 16, color >> 8, color);
	if (!(tmp = TTF_RenderText_Solid(env->sdl.font[2], text, env->sdl.color)))
		error = 1;
	if (!error && SDL_BlitSurface(tmp, 0, env->sdl.screen, &where))
		error = 2;
	if (error != 1)
		SDL_FreeSurface(tmp);
	if (error)
		clean(env, E_EDIT_TEXT);
	police_color(&env->sdl.color, 0xff, 0xff, 0xff);
}

static void		print_text_param(t_env *env, t_settings sett, int j)
{
	t_vertex	where;
	int			i;

	i = -1;
	where = init_vertex(1610, 155);
	while (++i < 7 && env->editor.tab[j][i])
	{
		if (sett == EFFECTOR && i == 2)
		{
			if (env->editor.effects.effects == EFF_JET
				|| env->editor.effects.effects == EFF_END)
				i = 3;
			else if (env->editor.effects.effects == EFF_MONEY
				|| env->editor.effects.effects == EFF_LAVA
					|| env->editor.effects.effects == EFF_HEAL)
				i = 4;
			display_text(WHITE, where, env->editor.tab[j][i], env);
			return ;
		}
		display_text(WHITE, where, env->editor.tab[j][i], env);
		where.y = where.y + 100;
	}
}

void			print_param_in_param(t_settings sett, t_env *env)
{
	int			j;

	if (sett == PORTAL)
		return ;
	if (sett == SECTOR || sett == PLAYER)
		j = (sett == SECTOR) ? 0 : 1;
	else if (sett == EFFECTOR)
		j = 3;
	else
		j = 2;
	print_text_param(env, sett, j);
}
