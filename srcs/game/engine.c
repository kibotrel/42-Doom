#include <math.h>
#include "env.h"
#include "game.h"
#include "utils.h"

void	physics(t_env *env)
{
	double		sight; // State and height of the camera (standing or crouching)

	sight = env->cam.sneak ? SNEAK_H : CAM_H;
	env->cam.ground = !env->cam.fall;
	// Vertical collision checks (along z axis)
	if (env->cam.fall)
		vertical_movement(env, env->sector[env->cam.sector], sight);
	// Horizontal collisions checks (along x and y axis)
	if (env->cam.move)
		horizontal_movement(env, env->cam.pos, env->cam.v, sight);
}

uint32_t	color_mul(uint32_t color, double mul);	//a mettre dans un .h
uint32_t	color_add(uint32_t color, double add);	//a mettre dans un .h

void	graphics(t_env *env, t_game *var)
{
	uint32_t	i;
	t_item		now;

	i = 0;
	while(i++ == 0 || var->head != var->tail)
	{
		if (cycle_check(var, &now)) // Check if we cross a sector twice and if MAQ_QUEUE loop are reached for the current sector
			continue;
		t_sector *sect = &env->sector[now.sector];
		for(unsigned s = 0; s < sect->points; ++s)
		{
			t_vec2d	v[2];
			t_vec2d	t[2];

			v[0] = v2d(sect->vertex[s].x - env->cam.pos.x, sect->vertex[s].y - env->cam.pos.y);
			v[1] = v2d(sect->vertex[(s + 1) % sect->points].x - env->cam.pos.x, sect->vertex[(s + 1) % sect->points].y - env->cam.pos.y);
			t[0] = v2d(v[0].x * env->cam.sin - v[0].y * env->cam.cos, v[0].x * env->cam.cos + v[0].y * env->cam.sin);
			t[1] = v2d(v[1].x * env->cam.sin - v[1].y * env->cam.cos, v[1].x * env->cam.cos + v[1].y * env->cam.sin);
			if (t[0].y <= 0 && t[1].y <= 0)
				continue;
			if (t[0].y <= 0 || t[1].y <= 0)
			{
				float nearz = 1e-4f;
				float farz = 5;
				float nearside = 1e-5f;
				float farside = 20.f;
				t_vec2d i1 = intersect(t[0].x,t[0].y,t[1].x,t[1].y, -nearside,nearz, -farside,farz);
				t_vec2d i2 = intersect(t[0].x,t[0].y,t[1].x,t[1].y,  nearside,nearz,  farside,farz);
				if (t[0].y < nearz)
					t[0] = (i1.y > 0 ? v2d(i1.x, i1.y) : v2d(i2.x, i2.y));
				if (t[1].y < nearz)
					t[1] = (i1.y > 0 ? v2d(i1.x, i1.y) : v2d(i2.x, i2.y));
			}
			int		border[2];
			t_vec2d	scale[2];

			scale[0] = v2d(env->cam.fov.x / t[0].y, env->cam.fov.y / t[0].y);
			scale[1] = v2d(env->cam.fov.x / t[1].y, env->cam.fov.y / t[1].y);
			border[0] = env->w / 2 - floor(t[0].x * scale[0].x);
			border[1] = env->w / 2 - floor(t[1].x * scale[1].x);
			if (border[0] >= border[1]|| border[1] < now.min || border[0] > now.max)
				continue;
			int		neighbor;
			double	ceil[2];
			double	floor[2];

			ceil[0] = sect->ceil - env->cam.pos.z;
			ceil[1] = 0;
			floor[0] = sect->floor - env->cam.pos.z;
			floor[1] = 0;
			neighbor = sect->neighbor[s];
			if (neighbor >= 0)
			{
				ceil[1]  = env->sector[neighbor].ceil  - env->cam.pos.z;
				floor[1] = env->sector[neighbor].floor - env->cam.pos.z;
			}
			int y1a = env->h / 2 - (int)(gap(ceil[0], t[0].y, env->cam.gap) * scale[0].y);
			int y1b = env->h / 2 - (int)(gap(floor[0], t[0].y, env->cam.gap) * scale[0].y);
			int y2a = env->h / 2 - (int)(gap(ceil[0], t[1].y, env->cam.gap) * scale[1].y);
			int y2b = env->h / 2 - (int)(gap(floor[0], t[1].y, env->cam.gap) * scale[1].y);
			int ny1a = env->h / 2 - (int)(gap(ceil[1], t[0].y, env->cam.gap) * scale[0].y);
			int ny1b = env->h / 2 - (int)(gap(floor[1], t[0].y, env->cam.gap) * scale[0].y);
			int ny2a = env->h / 2 - (int)(gap(ceil[1], t[1].y, env->cam.gap) * scale[1].y);
			int ny2b = env->h / 2 - (int)(gap(floor[1], t[1].y, env->cam.gap) * scale[1].y);
			int start = fmax(border[0], now.min);
			int end = fmin(border[1], now.max);
			for(int x = start; x <= end; ++x)
			{
				int z = ((x - border[0]) * (t[1].y - t[0].y) / (border[1] - border[0]) + t[0].y) * 8;
				int ya = (x - border[0]) * (y2a - y1a) / (border[1] - border[0]) + y1a;
				int cya = bound(ya, var->top[x], var->bottom[x]);
				int yb = (x - border[0]) * (y2b - y1b) / (border[1] - border[0]) + y1b;
				int cyb = bound(yb, var->top[x], var->bottom[x]);
				draw_slice(env, x, var->top[x], cya - 1, 0x111111 ,0x222222,0x111111);//plafond
				draw_slice(env, x, cyb + 1, var->bottom[x], 0x0000FF,0x0000AA,0x0000FF);//sol
				if (neighbor >= 0)
				{
					int nya = (x - border[0]) * (ny2a - ny1a) / (border[1] - border[0]) + ny1a;
					int cnya = bound(nya, var->top[x], var->bottom[x]);
					int nyb = (x - border[0]) * (ny2b - ny1b) / (border[1] - border[0]) + ny1b;
					int cnyb = bound(nyb, var->top[x], var->bottom[x]);
					unsigned r1 = 0x010101 * (255 - z), r2 = 0x040007 * (31 - z / 8);
					draw_slice(env, x, cya, cnya - 1, 0, x == border[0] || x == border[1] ? 0 : r1, 0);
					var->top[x] = bound(fmax(cya, cnya), var->top[x], env->h - 1);
					draw_slice(env, x, cnyb + 1, cyb, 0, x == border[0] || x == border[1] ? 0 : r2, 0);
					var->bottom[x] = bound(fmin(cyb, cnyb), 0, var->bottom[x]);
				}
				else
				{
					unsigned r = color_add(0xFFFFFF, -z);//0xFF0000 * (255-z);//texture
					draw_slice(env, x, cya, cyb, 0, x == border[0] || x == border[1] ? 0 : r, 0);//mur
				}
			}
			if (neighbor >= 0 && end >= start && (var->head - var->tail + 33) % 32)
			{
				*var->head = item(neighbor, start, end);
				if (++var->head == var->queue + 32)
					var->head = var->queue;
			}
		}
		var->render[now.sector]++;
	}
	if (var->top)
		free(var->top);
	if (var->bottom)
		free(var->bottom);
	if (var->render)
		free(var->render);}
