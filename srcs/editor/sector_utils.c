#include "libft.h"
#include "editor.h"

t_ed_sector	*create_sector(t_editor *edit, t_env *env)
{
	t_ed_sector	*sect;

	if (!(sect = (t_ed_sector*)ft_memalloc(sizeof(t_ed_sector))))
		clean_editor(edit, env);
	sect->sector_number = edit->count.sector++;
	sect->h_ceil = 20;
	sect->h_floor = 0;
	sect->vertex_count = 0;
	sect->texture = 0;
	sect->gravity = 10;
	sect->friction = 50;
	sect->next = NULL;
	sect->prev = NULL;
	return (sect);
}
