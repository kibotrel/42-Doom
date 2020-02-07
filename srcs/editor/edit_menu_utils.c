#include "editor.h"

void			square(int x, int y, int color, SDL_Surface *s)
{
	int		i;
	int		j;

	i = x - 50;
	while (i < x)
	{
		j = y - 50;
		while (j < y)
		{
			put_pixel(s, i, j, color);
			++j;
		}
		++i;
	}
}

void			rectangle(t_vertex start, t_vertex end, int clr, SDL_Surface *s)
{
	draw_ed_line(s, start, init_vertex(start.x, end.y), clr);
	draw_ed_line(s, init_vertex(end.x, start.y), end, clr);
	draw_ed_line(s, start, init_vertex(end.x, start.y), clr);
	draw_ed_line(s, init_vertex(start.x, end.y), end, clr);
}

void			draw_ed_background(SDL_Surface *s)
{
	int		x;
	int		y;

	x = EDIT_W;
	while (x < MENU_W + EDIT_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			put_pixel(s, x, y, 0x1e1e1e);
			++y;
		}
		++x;
	}
}

void			next_blank_menu(int set, SDL_Surface *s)
{
	if (set != PORTAL && set != PLAYER)
	{
		square(1600, 400, 0xff00ff, s);
		square(1600, 500, 0x00ffff, s);
		rectangle(init_vertex(1540, 340), init_vertex(1710, 410), WHITE, s);
		rectangle(init_vertex(1540, 440), init_vertex(1710, 510), WHITE, s);
		if (set == SECTOR)
		{
			square(1600, 600, 0x124079, s);
			rectangle(init_vertex(1540, 540), init_vertex(1710, 610), WHITE, s);
			square(1600, 700, 0x8f58a4, s);
			rectangle(init_vertex(1540, 640), init_vertex(1710, 710), WHITE, s);
			square(1600, 800, 0x5872b1, s);
			rectangle(init_vertex(1540, 740), init_vertex(1710, 810), WHITE, s);
		}
	}
	if (set != PORTAL)
	{
		square(1600, 200, 0x181279, s);
		square(1600, 300, 0x261017, s);
		rectangle(init_vertex(1540, 140), init_vertex(1710, 210), WHITE, s);
		rectangle(init_vertex(1540, 240), init_vertex(1710, 310), WHITE, s);
	}
}

void			blank_menu(SDL_Surface *s, int set, t_editor *edit, int preset, t_env *env)
{
	int		clr;

	draw_ed_background(s);
	clr = ((set != SECTOR) ? 0xffffff : 0x289655);
	rectangle(init_vertex(1340, 140), init_vertex(1510, 210), clr, s);
	clr = ((set != PLAYER) ? 0xffffff : 0x177489);
	rectangle(init_vertex(1340, 240), init_vertex(1510, 310), clr, s);
	clr = ((set != ENEMY) ? 0xffffff : 0x090875);
	rectangle(init_vertex(1340, 340), init_vertex(1510, 410), clr, s);
	clr = ((set != OBJECT) ? 0xffffff : 0x146595);
	rectangle(init_vertex(1340, 440), init_vertex(1510, 510), clr, s);
	clr = ((set != PORTAL) ? 0xffffff : 0x177013);
	rectangle(init_vertex(1340, 540), init_vertex(1510, 610), clr, s);
	next_blank_menu(set, s);
	sec_blank_menu(s, set, preset);
	rectangle(init_vertex(1350, 250), init_vertex(1400, 300), 0xffa500, s);
	rectangle(init_vertex(1350, 150), init_vertex(1400, 200), 0xffa500, s);
	rectangle(init_vertex(1350, 450), init_vertex(1400, 500), 0xffa500, s);
	rectangle(init_vertex(1350, 350), init_vertex(1400, 400), 0xffa500, s);
	rectangle(init_vertex(1350, 550), init_vertex(1400, 600), 0xffa500, s);
	rectangle(init_vertex(1300, 760), init_vertex(1410, 810), 0xffffff, s);
	rectangle(init_vertex(1420, 760), init_vertex(1530, 810), 0xffffff, s);
	print_param_to_screen(env, edit->sett, edit);
	print_param_in_param(set, env);
}
