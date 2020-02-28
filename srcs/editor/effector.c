#include "editor.h"

static char const	*g_effector[9] = {
	"None", "Jetpack", "Elevator", "Skybox", "Fly", "Money", "Spike",
		"Generator", "End"
};

void	effector_text(t_env *env, t_presets preset, t_effects effect)
{
	if (preset == EFF_EFFECT || preset == EFF_MOVE)
	{
		if (preset == EFF_EFFECT)
		{
			display_text(WHITE, init_vertex(1420, 50), "-", env);
			display_text(WHITE, init_vertex(1615, 55), "+", env);
		}
		display_text(WHITE, init_vertex(1455, 50), g_effector[effect], env);
	}
}

void	change_effect(t_effects *effect, bool fl)
{
	if (fl == false && *effect > 0)
		--*effect;
	else if (fl == true && *effect < ALL_EFFECTS - 1)
		++*effect;
}

void	apply_effect_in_sector(t_editor *edit, int x, int y)
{
	int				which_sector;
	t_ed_sector 	*sect;

	which_sector = is_in_sector(edit, init_vertex(x, y));
	if (which_sector < 0)
		return ;
	sect = edit->sector;
	while (sect->prev)
		sect = sect->prev;
	while (sect)
	{
		if (sect->sector_number == which_sector)
		{
			sect->effect.effects = edit->effects;
			return ;
		}
		sect = sect->next;
	}
}