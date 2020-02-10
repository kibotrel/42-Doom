#include "clean.h"
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

static void		draw_asset(t_env *env, t_bmp asset, t_pos shift)
{
	t_pos		p;
	t_pos		px;
	uint32_t	pos;

	p.y = -1;
	while (++p.y < asset.height)
	{
		p.x = -1;
		px.y = shift.y - asset.height + p.y;
		while (++p.x < asset.width)
		{
			px.x = shift.x + p.x;
			pos = p.x + p.y * asset.width;
			if (asset.pixels[pos] != 41704)
				draw_pixel(env, env->sdl.screen, px, asset.pixels[pos]);
		}
	}
}

// static void		draw_ammos(t_env *env, int32_t ammos, int32_t magazines)
// {
// 	(void)ammos;
// 	(void)magazines;
// 	t_pos		p;
// 	t_pos		px;
// 	t_bmp		slug;
// 	uint32_t	pos;
//
// 	if (bmp_to_array("./assets/Shell.bmp", &slug))
// 		clean(env, E_BMP_PARSE);
// 	p.y = -1;
// 	while (++p.y < slug.height)
// 	{
// 		p.x = -1;
// 		px.y = env->data.grid.min.y * 28 - slug.height + p.y;
// 		while (++p.x < slug.width)
// 		{
// 			px.x = env->data.grid.min.x + p.x;
// 			pos = p.x + p.y * slug.width;
// 			if (slug.pixels[pos] != 41704)
// 				draw_pixel(env, env->sdl.screen, px, slug.pixels[pos]);
// 		}
// 	}
// 	if (bmp_to_array("./assets/Shell1.bmp", &slug))
// 		clean(env, E_BMP_PARSE);
// 	p.y = -1;
// 	while (++p.y < slug.height)
// 	{
// 		p.x = -1;
// 		px.y = env->data.grid.min.y * 28 - slug.height + p.y;
// 		while (++p.x < slug.width)
// 		{
// 			px.x = env->data.grid.min.x * 12 + p.x;
// 			pos = p.x + p.y * slug.width;
// 			if (slug.pixels[pos] != 41704)
// 				draw_pixel(env, env->sdl.screen, px, slug.pixels[pos]);
// 		}
// 	}
// }

void			weapon(t_env *env)
{
	t_pos		shift;
	uint32_t	pos;

	pos = 0;
	if (env->data.shot)
	{
		env->tick.shot.new = SDL_GetTicks();
		pos = weapon_frame(env->tick.shot.new - env->tick.shot.old);
		if (!pos)
			env->data.shot = 0;
	}
	shift = (t_pos){env->w / 2 + env->data.grid.min.x * 3, env->h};
	draw_asset(env, env->sdl.bmp[SHOT_0 + pos], shift);
	shift = (t_pos){env->data.grid.min.x, env->data.grid.min.y * 28};
	draw_asset(env, env->sdl.bmp[MAGAZINE], shift);
	shift = (t_pos){shift.x * 12, shift.y};
	draw_asset(env, env->sdl.bmp[SHELL], shift);
}
