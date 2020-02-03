#include "libft.h"
#include "editor.h"
#include "utils.h"

static char const	*g_first_params[8] = {
	"Sector", "Player", "Enemy", "Object", "Portal", "Clear", "Save",
	"Draw Sector Clockwise"
};

static char const	*g_number[5] = {
	"1", "2", "3", "4", "5"
};

static char const	*g_tab[4][7] = {
	{"Select.", "Floor", "Roof", "Text","Type", "Grav", "Frict",},
	{"Rotate", "Del"},
	{"Select.", "Rotate", "Del", "Type"},
	{"Select.", "Type"}
};

void		display_text(int color, t_vertex pos, const char *text, t_env *env)
{
	SDL_Rect	where;
	SDL_Surface	*tmp;
	int			error;

	where.x = pos.x;
	where.y = pos.y;
	error = 0;
	police_color(&env->sdl.color, color >> 16, color >> 8, color);
	if (!(tmp = TTF_RenderText_Solid(env->sdl.font[2], text, env->sdl.color)))
		error = 1;
	if (!error && SDL_BlitSurface(tmp, 0, env->sdl.screen, &where))
		error = 2;
	if (error != 1)
		SDL_FreeSurface(tmp);
	if (error)
		clean_editor(&env->editor, env);
}

void		display_sector_type(t_env *env, int t)
{
	char		*print;
	t_vertex 	where;

	where = init_vertex(1465, 50);
	if (t == 0)
	{
		print = "None";
		where.x = 1480;
	}
	else if (t == 1)
		print = "Elevator";
	else if (t == 2)
		print = "Teleport";
	else if (t == 3)
		print = "Something";
	else
		print = NULL;
	if (print)
		display_text(WHITE, where, print, env);
}

static void	print_sector_values(t_ed_sector *sector, t_presets presets, t_env *env)
{
	char		*print;

	print = NULL;
	display_text(WHITE, init_vertex(1420, 50), "-", env);
	display_text(WHITE, init_vertex(1615, 55), "+", env);
	if (presets == SECTOR_FLOOR)
		print = ft_itoa(sector->h_floor);
	else if (presets == SECTOR_CEIL)
		print = ft_itoa(sector->h_ceil);
	else if (presets == SECTOR_TYPE)
		display_sector_type(env, sector->type);
	else if (presets == SECTOR_GRAV)
		print = ft_itoa(sector->gravity);
	else if (presets == SECTOR_FRICTION)
		print = ft_itoa(sector->friction);
	else if (presets == ENTITY_MOVE || presets == PORTAL_MOVE)
		display_text(WHITE, init_vertex(1455, 50), "Prev./Next", env);
	else if (presets == PLAYER_ROTATE || presets == ENTITY_ROTATE)
		display_text(WHITE, init_vertex(1455, 50), "Left/Right", env);
	else
		return ;
	if (print)
	{
		display_text(WHITE, init_vertex(1510, 50), print, env);
		free(print);
	}
}

void		print_param_to_screen(t_env *env, t_settings sett, t_editor *editor)
{
	t_vertex	pos;
	int			i;

	i = -1;
	pos.x = 1410;
	pos.y = 155;
	while (++i < 5)
	{
		display_text(WHITE, pos, g_first_params[i], env);
		display_text(WHITE, init_vertex(pos.x - 45, pos.y), g_number[i], env);
		pos.y = pos.y + 100;
	}
	display_text(WHITE, init_vertex(1315, 765), g_first_params[5], env);
	display_text(WHITE, init_vertex(1445, 765), g_first_params[6], env);
	if (env->editor.grid)
	display_text(env->editor.grid > 0 ? GREEN : RED, init_vertex(1283, 650), "Display grid : END", env);
	display_text(env->editor.display_portal > 0 ? GREEN : RED, init_vertex(1283, 690), "Display portal : P", env);
	if (editor->presets > SECTOR_MOVE && editor->sector)
		print_sector_values(editor->sector, editor->presets, env);
	if ((editor->presets == ENTITY_TYPE && ((sett == ENEMY && editor->enemy) ||
		(sett == OBJECT && editor->object))) ||
			editor->presets == SECTOR_TEXT ||
				(editor->presets == PORTAL_TYPE && editor->portals))
		print_params_image(editor, editor->presets, editor->sett, env);
	if (editor->sect_is_closed == false)
		display_text(WHITE, init_vertex(1380, 50), g_first_params[7], env);
}

void		print_param_in_param(t_settings sett, t_env *env)
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
	while (++i < 7 && g_tab[j][i])
	{
		display_text(WHITE, where, g_tab[j][i], env);
		where.y = where.y + 100;
	}
}
