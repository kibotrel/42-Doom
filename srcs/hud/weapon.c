#include "utils.h"

static uint32_t	weapon_frame(uint32_t frame)
{
	if (frame < 100)
		return (1);
	else if (frame < 175)
		return (2);
	else if (frame < 250)
		return (3);
	else if (frame < 300)
		return (4);
	else if (frame < 600)
		return (5);
	else if (frame < 800)
		return (6);
	else if (frame < 1000)
		return (5);
	else
		return (0);
}

static void		draw_weapon(t_env *env, t_bmp weapon, int offset)
{
	t_pos		p;
	t_pos		px;
	uint32_t	pos;

	p.y = -1;
	while (++p.y < weapon.height)
	{
		p.x = -1;
		px.y = env->h - weapon.height + p.y;
		while (++p.x < weapon.width)
		{
			px.x = (env->w / 2) + p.x + offset;
			pos = p.x + p.y * weapon.width;
			if (weapon.pixels[pos] != 41704)
				draw_pixel(env, env->sdl.screen, px, weapon.pixels[pos]);
		}
	}
}

static void		draw_ammos(t_env *env, int32_t ammos, int32_t magazines)
{
	(void)env;
	(void)ammos;
	(void)magazines;
}

void			weapon(t_env *env)
{
	uint32_t	pos;

	pos = 0;
	if (env->data.shot)
	{
		env->tick.shot.new = SDL_GetTicks();
		pos = weapon_frame(env->tick.shot.new - env->tick.shot.old);
		if (!pos)
			env->data.shot = 0;
	}
	draw_weapon(env, env->sdl.bmp[SHOT_0 + pos], env->data.grid.min.x * 3);
	draw_ammos(env, env->data.ammos, env->data.magazines);
}
