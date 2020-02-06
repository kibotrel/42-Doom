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
	sect->type = 0;
	sect->gravity = 10;
	sect->friction = 50;
	sect->next = NULL;
	sect->prev = NULL;
	return (sect);
}

// static int		in_how_many_sector(t_vertex vertex, t_ed_sector *sector)
// {
// 	t_ed_sector	*sect;
// 	t_vertex	*vert;
// 	int			how_many;

// 	how_many = 0;
// 	sect = sector;
// 	while (sect->prev)
// 		sect = sect->prev;
// 	while (sect)
// 	{
// 		vert = sect->vertex;
// 		while (vert)
// 		{
// 			if (vertex.x == vert->x && vertex.y == vert->y)
// 				++how_many;
// 			vert = vert->next;
// 		}
// 		sect = sect->next;
// 	}
// 	return (how_many);
// }

void	delete_sector_in_progress(t_ed_sector **sector,t_editor *edit)
{
	t_ed_sector	*sect;

	if (edit->sect_is_closed)
		return ;
	sect = *sector;
	while (sect->next)
		sect = sect->next;
	edit->count.vertex -= count_vertex_in_sector(sect->vertex);
	--edit->count.sector;
	printf("%d", sect->sector_number);
	if (sect->prev)
		sect = sect->prev;
	free(sect->is_portal);
	free(sect->portal_type);
	delete_vertex(&sect->vertex);
	free(sect);
	edit->sect_is_closed = true;
}