/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:09:05 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/11/19 13:03:26 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "editor.h"

static bool		is_saved(t_editor *editor)
{
	if (editor->map_save == false)
	{
		ft_putendl("You didn't save, press Esc to quit");
		editor->map_save = true;
		return (false);
	}
	else
	{
		ft_putendl("Exiting...");
		return (true);
	}
}

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

t_vertex		init_vertex(int x, int y)
{
	t_vertex	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

void			rectangle(t_vertex start, t_vertex end, int clr, SDL_Surface *s)
{
	draw_line(s, start, init_vertex(start.x, end.y), clr);
	draw_line(s, init_vertex(end.x, start.y), end, clr);
	draw_line(s, start, init_vertex(end.x, start.y), clr);
	draw_line(s, init_vertex(start.x, end.y), end, clr);
}

void			blank_menu(SDL_Surface *s)
{
	rectangle(init_vertex(1340, 140), init_vertex(1510, 210), 0xffffff, s);
	rectangle(init_vertex(1340, 240), init_vertex(1510, 310), 0xffffff, s);
	rectangle(init_vertex(1340, 340), init_vertex(1510, 410), 0xffffff, s);
	rectangle(init_vertex(1340, 440), init_vertex(1510, 510), 0xffffff, s);
	rectangle(init_vertex(1340, 540), init_vertex(1510, 610), 0xffffff, s);
}

void			display_menu(SDL_Surface *s)
{
	int		x;
	int		y;

	x = EDIT_W;
	while (x < (MENU_W + EDIT_W))
	{
		y = 0;
		while (y < WIN_H)
		{
			put_pixel(s, x, y, 0x1e1e1e);
			++y;
		}
		++x;
	}
	square(1400, 200, 0x0000ff, s);
	square(1400, 300, 0xff00ff, s);
	square(1400, 400, 0xff0000, s);
	square(1400, 500, 0x8b4513, s);
	square(1400, 600, 0x00ff00, s);
	blank_menu(s);
}

static void		display_editor(t_editor *editor)
{
	t_vertex	mouse;

	display_grid(editor);
	display_player(editor->player, &editor->sdl);
	display_entities(&editor->sdl, editor->enemy, 0xff0000);
	display_entities(&editor->sdl, editor->object, 0x8b4513);
	display_sector(editor);
	display_vertex(&editor->sdl, editor->vertex, 0xffff00);
	if (editor->sett == SECTOR && editor->sdl.event.motion.x <= EDIT_W)
	{
		mouse.x = (editor->sdl.event.motion.x / editor->dist_grid)
				* editor->dist_grid;
		mouse.y = (editor->sdl.event.motion.y / editor->dist_grid)
			* editor->dist_grid;
		display_mouse(&editor->sdl, mouse, 0x0ff0f0);
	}
	display_line(editor, editor->sdl.event.motion.x,
		editor->sdl.event.motion.y);
}

static void		mouse(t_editor *editor, SDL_Event event)
{
	if (event.motion.x <= EDIT_W)
	{
	if (editor->sett == SECTOR)
		place_sector(editor, event.motion.x, event.motion.y);
	else if (editor->sett == PLAYER)
		place_player(editor, event.motion.x, event.motion.y);
	else if (editor->sett == ENEMY)
		place_entity(editor, event.motion.x, event.motion.y, 0);
	else if (editor->sett == OBJECT)
		place_entity(editor, event.motion.x, event.motion.y, 1);
	else if (editor->sett == PORTAL)
		place_portal(editor, event.motion.x, event.motion.y);
	editor->map_save = false;
	}
	else
	{
		if (event.motion.x >= 1340 && event.motion.x <= 1510)
		{
			if (event.motion.y >= 140 && event.motion.y < 210)
				editor->sett = SECTOR;
			else if (event.motion.y >= 240 && event.motion.y < 310)
				editor->sett = PLAYER;
			else if (event.motion.y >= 340 && event.motion.y < 410)
				editor->sett = ENEMY;
			else if (event.motion.y >= 440 && event.motion.y < 510)
				editor->sett = OBJECT;
			else if (event.motion.y >= 540 && event.motion.y < 610)
				editor->sett = PORTAL;
		}
	}
}

static void		keydown(t_editor *editor, SDL_Event event)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
	{
		if (is_saved(editor) == true)
			editor->finish = true;
	}
	if (event.key.keysym.scancode == SDL_SCANCODE_RETURN)
	{
		create_map(editor);
		editor->map_save = true;
	}
	if (editor->sect_is_closed == true)
	{
		if (event.key.keysym.scancode == SDL_SCANCODE_1)
			editor->sett = SECTOR;
		else if (event.key.keysym.scancode == SDL_SCANCODE_2)
			editor->sett = PLAYER;
		else if (event.key.keysym.scancode == SDL_SCANCODE_3)
			editor->sett = ENEMY;
		else if (event.key.keysym.scancode == SDL_SCANCODE_4)
			editor->sett = OBJECT;
		else if (event.key.keysym.scancode == SDL_SCANCODE_5)
			editor->sett = PORTAL;
	}
}

void			non(t_sdl s)
{
	int		x;
	int		y;

	x = s.event.motion.x;
	y = s.event.motion.y;
	if (x >= 1340 && x <= 1510)
	{
		if (y >= 140 && y <= 210)
			rectangle(init_vertex(1340, 140), init_vertex(1510, 210), 0x5f287e, s.surf);
		else if (y >= 240 && y <= 310)
			rectangle(init_vertex(1340, 240), init_vertex(1510, 310), 0x5f287e, s.surf);
		else if (y >= 340 && y <= 410)
			rectangle(init_vertex(1340, 340), init_vertex(1510, 410), 0x5f287e, s.surf);
		else if (y >= 440 && y <= 510)
			rectangle(init_vertex(1340, 440), init_vertex(1510, 510), 0x5f287e, s.surf);
		else if (y >= 540 && y <= 610)
			rectangle(init_vertex(1340, 540), init_vertex(1510, 610), 0x5f287e, s.surf);
		else
			blank_menu(s.surf);
	}
	else
		blank_menu(s.surf);
}

void			events(t_editor *editor)
{
	display_menu(editor->sdl.surf);
	while (editor->finish == false)
	{
		while (SDL_PollEvent(&(editor->sdl.event)))
		{
			if (editor->sdl.event.type == SDL_QUIT)
			{
				if (is_saved(editor) == true)
					editor->finish = true;
			}
			else if (editor->sdl.event.type == SDL_KEYDOWN)
				keydown(editor, editor->sdl.event);
			else if (editor->sdl.event.type == SDL_MOUSEBUTTONDOWN)
				mouse(editor, editor->sdl.event);
			else if (editor->sdl.event.type == SDL_MOUSEMOTION)
				non(editor->sdl);
		}
		display_editor(editor);
		if (SDL_UpdateWindowSurface(editor->sdl.win) != 0)
			exit(1);
	}
}
