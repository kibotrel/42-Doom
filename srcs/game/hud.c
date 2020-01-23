#include "game.h"
#include "clean.h"
#include "libft.h"
#include "utils.h"

//Position
//Gravity
//Viscosity

static void	display_info(t_env *env, char *info, t_vec2d pos)
{
	t_vec		p;
	SDL_Rect	where;
	SDL_Surface	*tmp;

	TTF_SizeText(env->sdl.font[1], info, &p.x, &p.y);
	where.x = env->data.grid.min.x * pos.x;
	where.y = env->data.grid.min.y * pos.y;
	if (!(tmp = TTF_RenderText_Solid(env->sdl.font[1], info, env->sdl.color)))
		clean(env, E_TTF_RENDER);
	if (SDL_BlitSurface(tmp, 0, env->sdl.screen, &where))
		clean(env, E_SDL_BLIT);
	else
		SDL_FreeSurface(tmp);
	free(info);
}

void		hud(t_env *env, t_game *var)
{
	(void)var;
	display_info(env, ft_strjoin("FPS : ", ft_itoa(env->data.fps)), v2d(3, 1));
	display_info(env, ft_strjoin("Sector : ", ft_itoa(env->cam.sector)), v2d(10,1));
	display_info(env, ft_strjoin("Altitude : ", ft_itoa(env->cam.pos.z)), v2d(18,1));
	display_info(env, ft_strjoin("Angle : ", ft_itoa((int)fabs(ft_degrees(env->cam.angle)) % 360)), v2d(10,2));
	if (env->cam.fly > 0)
		display_info(env, ft_strdup("Fly : ON"), v2d(3, 2));
	else
		display_info(env, ft_strdup("Fly : OFF"), v2d(3, 2));
}
