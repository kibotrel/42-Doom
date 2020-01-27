#include "env.h"
#include "utils.h"
#include "editor.h"


void			draw_ed_line(SDL_Surface *surf, t_vertex start, t_vertex end,
	int color)
{
	t_line		line;

	line.delta.x = abs(end.x - start.x);
	line.delta.y = abs(end.y - start.y);
	line.sign.x = start.x < end.x ? 1 : -1;
	line.sign.y = start.y < end.y ? 1 : -1;
	line.error = line.delta.x - line.delta.y;
	put_pixel(surf, end.x, end.y, color);
	while (start.x != end.x || start.y != end.y)
	{
		put_pixel(surf, start.x, start.y, color);
		line.offset = line.error * 2;
		if (line.offset > -line.delta.y)
		{
			line.error -= line.delta.y;
			start.x += line.sign.x;
		}
		if (line.offset < line.delta.x)
		{
			line.error += line.delta.x;
			start.y += line.sign.y;
		}
	}
}

void			put_pixel(SDL_Surface *surf, int x, int y, int color)
{
	int		*pix;

	if ((x >= 0 && x <= EDIT_W + MENU_W) && (y >= 0 && y <= WIN_H))
	{
		pix = surf->pixels + y * surf->pitch + x * surf->format->BytesPerPixel;
		*pix = color;
	}
}

static double	deg_to_rad(int deg)
{
	return (deg * M_PI / 180);
}

void			put_fov(SDL_Surface *surf, t_vertex pt, int agl, int color)
{
	size_t		i;
	int			angle;
	t_vertex	p0;
	t_vertex	p1;

	i = 0;
	while (i < 2)
	{
		p0 = init_vertex(cos(deg_to_rad(agl)) * SIZE + pt.x,
			-sin(deg_to_rad(agl)) * SIZE + pt.y);
		angle = agl + i * ANGLE - ANGLE / 2;
		angle = angle > 360 ? angle - 360 : angle;
		angle = angle < 0 ? angle + 360 : angle;
		p1 = init_vertex(-cos(deg_to_rad(angle)) * SIZE + pt.x,
			sin(deg_to_rad(angle)) * SIZE + pt.y);
		draw_ed_line(surf, p0, p1, color);
		++i;
	}
}
