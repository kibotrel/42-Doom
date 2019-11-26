#include <math.h>
#include <stdlib.h>
#include "game.h"
#include "clean.h"
#include "utils.h"
#include "libft.h"

t_item		item(int sector, int start, int end)
{
	t_item		item;

	item.sector = sector;
	item.sx1 = start;
	item.sx2 = end;
	return (item);
}

static void	queue_setup(t_env *env, t_local *local)
{
	int32_t		x;
	uint32_t	i;

	x = -1;
	while (++x < env->w)
	{
		local->ytop[x] = 0;
		local->ybottom[x] = env->h - 1;
	}
	i = 0;
	while (i < env->zones)
		local->renderedsectors[i++] = 0;
	local->head = local->queue;
	local->tail = local->queue;
	*local->head = item(env->cam.sector, 0, env->w);
	if (++local->head == local->queue + QUEUE_MAX)
		local->head = local->queue;
}

static int	engine_setup(t_env *env, t_local *local)
{
	if (!(local->ytop = (int*)malloc(4 * env->w)))
		return (E_MALLOC);
	if (!(local->ybottom = (int*)malloc(4 * env->w)))
		return (E_MALLOC);
	if (!(local->renderedsectors = (int*)malloc(4 * env->zones)))
		return (E_MALLOC);
	if (!(local->head = (t_item*)malloc(sizeof(t_item) * QUEUE_MAX)))
		return (E_MALLOC);
	if (!(local->tail = (t_item*)malloc(sizeof(t_item) * QUEUE_MAX)))
		return (E_MALLOC);
	queue_setup(env, local);
	return (0);
}

void		translate(t_env *env, t_graphic *p, t_sector *sect, uint32_t i)
{
	p->vx1 = sect->vertex[i].x - env->cam.pos.x;
	p->vy1 = sect->vertex[i].y - env->cam.pos.y;
	p->vx2 = sect->vertex[(i + 1) % sect->points].x - env->cam.pos.x;
	p->vy2 = sect->vertex[(i + 1) % sect->points].y - env->cam.pos.y;
}

void		rotate(t_env *env, t_graphic *p)
{
	p->tx1 = p->vx1 * env->cam.sin - p->vy1 * env->cam.cos;
	p->tz1 = p->vx1 * env->cam.cos + p->vy1 * env->cam.sin;
	p->tx2 = p->vx2 * env->cam.sin - p->vy2 * env->cam.cos;
	p->tz2 = p->vx2 * env->cam.cos + p->vy2 * env->cam.sin;
}

void		view_correct(t_graphic *p)
{
	t_vec2d i[2];

	i[0] = Intersect(p->tx1, p->tz1, p->tx2, p->tz2, -p->nearside, p->nearz, -p->farside, p->farz);
	i[1] = Intersect(p->tx1, p->tz1, p->tx2, p->tz2, p->nearside, p->nearz, p->farside, p->farz);
	if (p->tz1 < p->nearz)
	{
		if (i[0].y > 0)
		{
			p->tx1 = i[0].x;
			p->tz1 = i[0].y;
		}
		else
		{
			p->tx1 = i[1].x;
			p->tz1 = i[1].y;
		}
	}
	if (p->tz2 < p->nearz)
	{
		if (i[1].y > 0)
		{
			p->tx2 = i[0].x;
			p->tz2 = i[0].y;
		}
		else
		{
			p->tx2 = i[1].x;
			p->tz2 = i[1].y;
		}
	}
}

void		setup_process(t_graphic *p)
{
	ft_bzero(p, sizeof(t_graphic));
	p->nearz = 0.0001;
	p->farz = 5;
	p->nearside = 0.00001;
	p->farside = 20;
}

void		transform(t_env *env, t_graphic *p)
{
	p->xscale1 = env->cam.fov.x / p->tz1;
	p->yscale1 = env->cam.fov.y / p->tz1;
	p->xscale2 = env->cam.fov.x / p->tz2;
	p->yscale2 = env->cam.fov.y / p->tz2;
	p->x1 = env->w / 2 - floor(p->tx1 * p->xscale1);
	p->x2 = env->w / 2 - floor(p->tx2 * p->xscale2);
}

void		setup_slice(t_env *env, t_graphic *p, t_sector *sect, t_item *now)
{
	p->yceil = sect->ceil - env->cam.pos.z;
	p->yfloor = sect->floor - env->cam.pos.z;
	// p->nyceil = 0;
	// p->nyfloor = 0;
	if (p->neighbor >= 0)
	{
		p->nyceil  = env->sector[p->neighbor].ceil  - env->cam.pos.z;
		p->nyfloor = env->sector[p->neighbor].floor - env->cam.pos.z;
	}
	p->y1a = env->h / 2 - floor(Yaw(p->yceil, p->tz1, env->cam.gap) * p->yscale1);
	p->y1b = env->h / 2 - floor(Yaw(p->yfloor, p->tz1, env->cam.gap) * p->yscale1);
	p->y2a = env->h / 2 - floor(Yaw(p->yceil, p->tz2, env->cam.gap) * p->yscale2);
	p->y2b = env->h / 2 - floor(Yaw(p->yfloor, p->tz2, env->cam.gap) * p->yscale2);
	p->ny1a = env->h / 2 - floor(Yaw(p->nyceil, p->tz1, env->cam.gap) * p->yscale1);
	p->ny1b = env->h / 2 - floor(Yaw(p->nyfloor, p->tz1, env->cam.gap) * p->yscale1);
	p->ny2a = env->h / 2 - floor(Yaw(p->nyceil, p->tz2, env->cam.gap) * p->yscale2);
	p->ny2b = env->h / 2 - floor(Yaw(p->nyfloor, p->tz2, env->cam.gap) * p->yscale2);
	p->beginx = max(p->x1, now->sx1);
	p->endx = min(p->x2, now->sx2);
}

void		build_slice(t_env *env, t_graphic *p, t_local *local)
{
	int32_t	x;

	x = p->beginx;
	while (x <= p->endx)
	{
		// p->z = ((x - p->x1) * (p->tz2 - p->tz1) / (p->x2 - p->x1) + p->tz1) * 8; // fog
		p->ya = (x - p->x1) * (p->y2a - p->y1a) / (p->x2 - p->x1) + p->y1a;
		p->cya = clamp(p->ya, local->ytop[x], local->ybottom[x]);
		p->yb = (x - p->x1) * (p->y2b - p->y1b) / (p->x2 - p->x1) + p->y1b;
		p->cyb = clamp(p->yb, local->ytop[x], local->ybottom[x]);
		draw_slice(env, x, local->ytop[x], p->cya - 1, 0x111111 ,0x222222,0x111111);
		draw_slice(env, x, p->cyb + 1, local->ybottom[x], 0x0000FF,0x0000AA,0x0000FF);
		if (p->neighbor >= 0)
		{
			// unsigned r1 = 0x010101 * (255 - p->z); // fog
			// unsigned r2 = 0x040007 * (31 - p->z / 8); // fog
			p->nya = (x - p->x1) * (p->ny2a - p->ny1a) / (p->x2 - p->x1) + p->ny1a;
			p->cnya = clamp(p->nya, local->ytop[x], local->ybottom[x]);
			p->nyb = (x - p->x1) * (p->ny2b - p->ny1b) / (p->x2 - p->x1) + p->ny1b;
			p->cnyb = clamp(p->nyb, local->ytop[x], local->ybottom[x]);
			draw_slice(env, x, p->cya, p->cnya - 1, 0, x == p->x1 || x == p->x2 ? 0 : 0x010101, 0);
			local->ytop[x] = clamp(max(p->cya, p->cnya), local->ytop[x], env->h - 1);
			draw_slice(env, x, p->cnyb + 1, p->cyb, 0, x == p->x1 || x == p->x2 ? 0 : 0x040007, 0);
			local->ybottom[x] = clamp(min(p->cyb, p->cnyb), 0, local->ybottom[x]);
		}
		else
		{
			// unsigned r = 0x010101 * (255-z);
			draw_slice(env, x, p->cya, p->cyb, 0, x == p->x1 || x == p->x2 ? 0 : 0xAAAAAA, 0);
		}
		x++;
	}
}

void		process(t_env *env, t_local *local, t_item *now, t_sector *sect)
{
	uint32_t		i;
	t_graphic		p;

	i = 0;
	setup_process(&p);
	while (i < sect->points)
	{
		translate(env, &p, sect, i);
		rotate(env, &p);
		if (p.tz1 <= 0 && p.tz2 <= 0)
			continue;
		if (p.tz1 <= 0 || p.tz2 <= 0)
			view_correct(&p);
		transform(env, &p);
		if (p.x1 >= p.x2 || p.x2 < now->sx1 || p.x1 > now->sx2)
			continue;
		p.neighbor = sect->neighbor[i];
		setup_slice(env, &p, sect, now);
		build_slice(env, &p, local);
		if (p.neighbor >= 0 && p.endx >= p.beginx && (local->head - local->tail + 33) % 32)
		{
			local->head->sector = p.neighbor;
			local->head->sx1 = p.beginx;
			local->head->sx2 = p.endx;
		}
		i++;
	}
}

void		end_process(t_env *env, t_local *local, int status)
{
	if (local->ytop)
		free(local->ytop);
	if (local->ybottom)
		free(local->ybottom);
	if (local->renderedsectors)
		free(local->renderedsectors);
	if (local->head)
		free(local->head);
	if (local->tail)
		free(local->tail);
	if (status)
		clean(env, status);
}

void		graphics(t_env *env, t_local *local)
{
	int			i;
	t_item		now;
	t_sector	*sect = NULL;

	i = 0;
	while(i == 0 || local->head != local->tail)
	{
		i = 1;
		now = *local->tail;
		if (++local->tail == local->queue + QUEUE_MAX)
			local->tail = local->queue;
		if (local->renderedsectors[now.sector] & 0x21)
			continue;
		++local->renderedsectors[now.sector];
		sect = &env->sector[now.sector];
		process(env, local, &now, sect);
		++local->renderedsectors[now.sector];
	}
	end_process(env, local, 0);
}

void		engine(t_env *env)
{
	t_local		local;

	if (engine_setup(env, &local))
		end_process(env, &local, E_MALLOC);
	graphics(env, &local);
}
