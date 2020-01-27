#include "libft.h"
#include "editor.h"

static char const	*g_first_params[8] = {
	"Sector", "Player", "Enemy", "Object", "Portal", "Clear", "Save",
	"Draw Sector Clockwise"
};

static char const	*g_number[5] = {
	"1", "2", "3", "4", "5"
};

static char const	*g_tab[4][6] = {
	{"Select.", "Floor", "Roof", "Text", "Grav", "Frict"},
	{"Rotate", "Del"},
	{"Select.", "Rotate", "Del", "Type"},
	{"Select.", "Type"}
};

void		display_text(t_editor *edit, t_sdl *sdl, t_vertex pos,
	const char *text)
{
	SDL_Rect	where;
	SDL_Surface	*tmp;
	int			error;

	where.x = pos.x;
	where.y = pos.y;
	error = 0;
	if (!(tmp = TTF_RenderText_Solid(sdl->font, text, sdl->color)))
		error = 1;
	if (!error && SDL_BlitSurface(tmp, 0, sdl->surf, &where))
		error = 2;
	if (error != 1)
		SDL_FreeSurface(tmp);
	if (error)
		clean(edit);
}

static void	print_sector_values(t_sdl *sdl, t_sector *sector, t_presets presets,
	t_editor *edit)
{
	char		*print;

	print = NULL;
	display_text(edit, sdl, init_vertex(1420, 50), "-");
	display_text(edit, sdl, init_vertex(1615, 55), "+");
	if (presets == SECTOR_FLOOR)
		print = ft_itoa(sector->h_floor);
	else if (presets == SECTOR_CEIL)
		print = ft_itoa(sector->h_ceil);
	else if (presets == SECTOR_GRAV)
		print = ft_itoa(sector->gravity);
	else if (presets == SECTOR_FRICTION)
		print = ft_itoa(sector->friction);
	else if (presets == ENTITY_MOVE || presets == SECTOR_MOVE ||
		presets == PORTAL_MOVE)
		display_text(edit, sdl, init_vertex(1455, 50), "Prev./Next");
	else if (presets == PLAYER_ROTATE || presets == ENTITY_ROTATE)
		display_text(edit, sdl, init_vertex(1455, 50), "Left/Right");
	else
		return ;
	if (print)
	{
		display_text(edit, sdl, init_vertex(1510, 50), print);
		free(print);
	}
}

void		print_param_to_screen(t_sdl *sdl, t_settings sett, t_editor *editor)
{
	t_vertex	pos;
	int			i;

	i = -1;
	pos.x = 1410;
	pos.y = 155;
	while (++i < 5)
	{
		display_text(editor, sdl, pos, g_first_params[i]);
		display_text(editor, sdl, init_vertex(pos.x - 45, pos.y), g_number[i]);
		pos.y = pos.y + 100;
	}
	display_text(editor, sdl, init_vertex(1315, 665), g_first_params[5]);
	display_text(editor, sdl, init_vertex(1445, 665), g_first_params[6]);
	if (editor->presets != NONE && editor->sector)
		print_sector_values(sdl, editor->sector, editor->presets, editor);
	if ((editor->presets == ENTITY_TYPE && ((sett == ENEMY && editor->enemy) ||
		(sett == OBJECT && editor->object))) ||
			editor->presets == SECTOR_TEXT ||
				(editor->presets == PORTAL_TYPE && editor->portals))
		print_params_image(editor, editor->presets, editor->sett);
	if (editor->sect_is_closed == false)
		display_text(editor, sdl, init_vertex(1380, 50), g_first_params[7]);
}

void		print_param_in_param(t_editor *edit, t_sdl *sdl, t_settings sett)
{
	t_vertex	where;
	int			i;
	int			j;

	if (sett == PORTAL)
		j = 3;
	else if (sett == SECTOR || sett == PLAYER)
		j = (sett == SECTOR) ? 0 : 1;
	else
		j = 2;
	i = -1;
	where.x = 1610;
	where.y = 155;
	while (++i < 6 && g_tab[j][i])
	{
		display_text(edit, sdl, where, g_tab[j][i]);
		where.y = where.y + 100;
	}
}
