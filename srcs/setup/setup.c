/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:58:26 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/03 13:11:21 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "clean.h"
#include "libft.h"
#include "setup.h"
#include "utils.h"
#include "editor.h"

static void	time_track(t_env *env)
{
	ft_bzero(&env->tick, sizeof(t_time));
	ft_bzero(&env->tick.fly, sizeof(t_tick));
	ft_bzero(&env->tick.fps, sizeof(t_tick));
	ft_bzero(&env->tick.frame, sizeof(t_tick));
	ft_bzero(&env->tick.debug, sizeof(t_tick));
	ft_bzero(&env->tick.test, sizeof(t_tick));
}

static void	error_messages(t_env *env)
{
	ft_bzero(env->error, sizeof(char*));
	env->error[NOTHING] = "";
	env->error[E_FILENAME] = M_FILENAME;
	env->error[E_SDL_INIT] = M_SDL_INIT;
	env->error[E_SDL_WIN] = M_SDL_WIN;
	env->error[E_SDL_WINSURF] = M_SDL_WINSURF;
	env->error[E_SDL_UPDATE] = M_SDL_UPDATE;
	env->error[E_TTF_INIT] = M_TTF_INIT;
	env->error[E_TTF_FONT] = M_TTF_FONT;
	env->error[E_TTF_RENDER] = M_TTF_RENDER;
	env->error[E_SDL_BLIT] = M_SDL_BLIT;
	env->error[E_BMP_PARSE] = M_BMP_PARSE;
	env->error[E_MALLOC] = M_MALLOC;
	env->error[E_BKGD] = M_BKGD;
}

static void	assets_paths(t_env *env)
{
	ft_bzero(env->asset, sizeof(char*));
	env->asset[MENU_1080P] = "assets/menu_1080.bmp";
	env->asset[MENU_900P] = "assets/menu_900.bmp";
	env->asset[MENU_768P] = "assets/menu_768.bmp";
	env->asset[MENU_720P] = "assets/menu_720.bmp";
	env->asset[ED_TEXT_1] = "./assets/texture_1.bmp";
	env->asset[ED_TEXT_2] = "./assets/texture_2.bmp";
	env->asset[ED_TEXT_3] = "./assets/texture_3.bmp";
	env->asset[ED_TEXT_4] = "./assets/texture_4.bmp";
	env->asset[ED_OBJ_1] = "./assets/object_1.bmp";
	env->asset[ED_OBJ_2] = "./assets/object_2.bmp";
	env->asset[ED_OBJ_3] = "./assets/object_3.bmp";
	env->asset[ED_OBJ_4] = "./assets/object_4.bmp";
	env->asset[ED_ENEMY_1] = "./assets/enemy_1.bmp";
	env->asset[ED_ENEMY_2] = "./assets/enemy_2.bmp";
	env->asset[ED_ENEMY_3] = "./assets/enemy_3.bmp";
	env->asset[ED_ENEMY_4] = "./assets/enemy_4.bmp";
	env->asset[ED_PORTAL_DOOR] = "./assets/portal_wall.bmp";
	env->asset[ED_PORTAL_WALL] = "./assets/portal_door.bmp";

}

static void	infos_setup(t_env *env)
{
	ft_bzero(env->input, sizeof(int) * SDL_NUM_SCANCODES);
	ft_bzero(&env->data, sizeof(t_data));
	ft_bzero(&env->data.hud, sizeof(t_hud));
	ft_bzero(&env->data.ui, sizeof(t_ui));
	ft_bzero(&env->cam, sizeof(t_cam));
	env->data.ui.min.y = floor(env->h / RATIO_UI_Y);
	env->data.ui.min.x = floor(env->w / RATIO_UI_X) * 5;
	env->data.ui.max.y = env->h;
	env->data.ui.max.x = floor(env->w / RATIO_UI_X) * 7;
	env->data.grid.min.y = floor(env->h / RATIO_GRID_Y);
	env->data.grid.min.x = floor(env->w / RATIO_GRID_X);
	env->data.grid.max.y = floor(env->h - RATIO_GRID_Y);
	env->data.grid.max.x = floor(env->w - RATIO_GRID_X);
	if ((env->data.ui.background = get_dimensions(env->h)) == -1)
		clean(env, E_BKGD);
	env->data.f_size = floor(env->w * MAX_FONT_SIZE / MAX_WIDTH);
	env->data.g_size = env->data.f_size / 3;
	env->data.hud.debug = -1;
	env->cam.fly = -1;
	env->cam.fall = 1;
	env->cam.speed = 1;
}

void		env_setup(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	env->w = WIN_W;
	env->h = WIN_H;
	env->win = MENU;
	assets_paths(env);
	error_messages(env);
	infos_setup(env);
	time_track(env);
	editor_setup(&env->editor);
	env->old_st_fl = 0;
	env->st_fl = 1;
}
