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
	sect->light = -1;
	sect->light_value = -1;
	sect->next = NULL;
	sect->prev = NULL;
	return (sect);
}

void			print_sector_light(t_env *env, int light, t_ed_sector *sect)
{
	int		color;

	rectangle(init_vertex(1499, 49), init_vertex(1550, 100), 0xffffff, env->sdl.screen);
	if (light == -1)
	{
		sect->light_value = -1;
		return ;
	}
	else if (light == 0)
		color = 0xff0000;
	else if (light == 1)
		color = 0x00ff00;
	else if (light == 2)
		color = 0x0000ff;
	else if (light == 3)
		color = 0xcc6075;
	else if (light == 4)
		color = 0xe69a01;
	else if (light == 5)
		color = 0x999999;
	else if (light == 6)
		color = 0x04c39a;
	else
		return ;
	sect->light_value = color;
	square(1550, 100, color, env->sdl.screen);
}

static int		reset_count(t_vertex *vertex, t_ed_sector *sector)
{
	t_ed_sector	*sect;
	t_vertex	*vert_1;
	t_vertex	*vert_2;
	int			ret;
	int			minus;

	ret = 0;
	minus = 0;
	vert_1 = vertex;
	sect = sector;
	while (vert_1)
	{
		while (sect->prev)
			sect = sect->prev;
		while (sect && sect->sector_number < sector->sector_number)
		{
			vert_2 = sect->vertex;
			while (vert_2)
			{
				if (vert_2->x == vert_1->x && vert_2->y == vert_1->y)
					++minus;
				vert_2 = vert_2->next;
			}
			sect = sect->next;
		}
		++ret;
		vert_1 = vert_1->next;
	}
	return (ret - minus);
}

void	delete_sector_in_progress(t_ed_sector **sector,t_editor *edit)
{
	t_ed_sector	*sect;

	if (edit->sect_is_closed)
		return ;
	sect = *sector;
	while (sect->next)
		sect = sect->next;
	edit->count.vertex -= reset_count(sect->vertex, sect);
	delete_vertex(&sect->vertex);
	edit->sect_is_closed = true;
}