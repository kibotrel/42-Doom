#include "editor.h"
#include "libft.h"

int		main_editor(t_env *env)
{
	events(&env->editor, env);
	return (0);
}
