#include "libft.h"
#include "editor.h"

static int	get_portal_type(t_portal *portal, t_ed_sector *sector)
{
	t_ed_sector *sect;
	t_portal *port;

	sect = sector;
	while (sect->prev)
		sect = sect->prev;
	while (sect)
	{
		port = sect->portal;
		while (port)
		{
			if (port->extrems[0].x == portal->extrems[0].x &&
				port->extrems[0].y == portal->extrems[0].y &&
					port->extrems[1].x == portal->extrems[1].x &&
						port->extrems[1].y == portal->extrems[1].y)
				return (port->type);
			port = port->next;
		}
		sect = sect->next;
	}
	return (0);
}

static void	print_picture(t_sdl *sdl, int x, int y, t_bmp img)
{
	int xa;
	int	ya;

	ya = 0;
	while (++ya < img.height)
	{
		xa = 0;
		while (++xa < img.width)
		{
			if (xa + x < EDIT_W + MENU_W && ya + y < WIN_H)
				put_pixel(sdl->screen, xa + x, ya + y,
					img.pixels[xa + ya * img.width]);
		}
	}
}

void		print_params_image(t_editor *edit, t_presets presets,
	t_settings sett, t_env *env)
{
	int		i;
	int		j;

	if (!edit->sector)
		return ;
	if (sett == SECTOR && presets == SECTOR_TEXT)
	{
		i = ED_TEXT_1;
		j = edit->sector->texture;
	}
	else if (sett == OBJECT && presets == ENTITY_TYPE)
	{
		i = ED_OBJ_1;
		j = edit->object->type;
	}
	else if (sett == ENEMY && presets == ENTITY_TYPE)
	{
		i = ED_ENEMY_1;
		j = edit->enemy->type;
	}
	else if (sett == PORTAL && presets == PORTAL_TYPE)
	{
		i = ED_PORTAL_DOOR;
		j = get_portal_type(edit->portals, edit->sector);
	}
	else
		return ;
	print_picture(&env->sdl, 1475, 30, edit->sdl.bmp[i + j]);
	display_text(edit, &env->sdl, init_vertex(1420, 50), "-");
	display_text(edit, &env->sdl, init_vertex(1615, 55), "+");
}
