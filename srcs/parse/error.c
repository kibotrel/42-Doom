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
