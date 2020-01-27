#include "libft.h"
#include "editor.h"

t_sector	*create_sector(t_editor *edit)
{
	t_sector	*sect;

	if (!(sect = (t_sector*)ft_memalloc(sizeof(t_sector))))
		clean(edit);
	sect->sector_number = edit->count.sector++;
	sect->h_ceil = 20;
	sect->h_floor = 0;
	sect->vertex_count = 0;
	sect->texture = 0;
	sect->gravity = 5;
	sect->friction = 2;
	sect->next = NULL;
	sect->prev = NULL;
	return (sect);
}
