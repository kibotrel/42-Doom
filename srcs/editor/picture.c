#include "libft.h"
#include "editor.h"

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
	else
		return ;
	print_picture(&env->sdl, 1475, 30, env->sdl.bmp[i + j]);
	display_text(WHITE, init_vertex(1420, 50), "-", env);
	display_text(WHITE, init_vertex(1615, 55), "+", env);
}
