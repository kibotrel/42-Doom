#include "editor.h"
#include "libft.h"

static char const	*g_effector[ALL_EFFECTS] = {
	"None", "Jetpack", "Money", "Elevator", "Lava", "Heal", "End", "Skybox"
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
		display_text(WHITE, init_vertex(1460, 50), g_effector[effect], env);
	}
	else if (preset == EFF_DATA && effect != NONE)
	{
		display_text(WHITE, init_vertex(1420, 50), "-", env);
		display_text(WHITE, init_vertex(1615, 55), "+", env);
		display_text(WHITE, init_vertex(1460, 50), ft_itoa(env->editor.count.eff_data[effect]), env);
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
			sect->effect.effects = edit->effects.effects;
			sect->effect.data = edit->count.eff_data[edit->effects.effects];
			return ;
		}
		sect = sect->next;
	}
}