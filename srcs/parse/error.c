#include <stdio.h>
#include "parse.h"
#include "clean.h"

void		main_err(t_parse *p, t_env *env, int fl)
{
	if (p->total.vert >= 0)
		free(p->ver);
	if (p->total.emy >= 0)
		free(p->emy);
	if (p->total.obj >= 0)
		free(p->obj);
	if (fl == 1)
		clean(env, E_PARSE);
}

void		parse_err(char **tab, t_parse *p, t_env *env)
{
	free_tab(tab);
	main_err(p, env, 1);
}
