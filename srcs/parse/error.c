/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <reda-con@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:33:55 by reda-con          #+#    #+#             */
/*   Updated: 2020/03/06 10:24:37 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "clean.h"

void		main_err(t_parse *p, t_env *env, int fl, uint8_t tag)
{
	if (p->ver)
		free(p->ver);
	if (fl == 1)
		clean(env, tag);
}

void		parse_err(char **tab, t_parse *p, t_env *env, uint8_t tag)
{
	free_tab(tab);
	main_err(p, env, 1, tag);
}
