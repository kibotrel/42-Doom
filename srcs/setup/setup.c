/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:58:26 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/20 14:11:12 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "clean.h"
#include "libft.h"
#include "setup.h"
#include "utils.h"
#include "editor.h"

static void	bzero_params(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	ft_bzero(env->asset, sizeof(char*));
	ft_bzero(env->error, sizeof(char*));
	ft_bzero(&env->cam, sizeof(t_cam));
	ft_bzero(&env->data, sizeof(t_data));
	ft_bzero(&env->data.ui, sizeof(t_ui));
	ft_bzero(&env->data.hud, sizeof(t_hud));
	ft_bzero(&env->tick, sizeof(t_time));
	ft_bzero(&env->tick.fly, sizeof(t_tick));
	ft_bzero(&env->tick.fps, sizeof(t_tick));
	ft_bzero(&env->tick.hud, sizeof(t_tick));
	ft_bzero(&env->tick.frame, sizeof(t_tick));
	ft_bzero(&env->tick.debug, sizeof(t_tick));
	ft_bzero(&env->tick.purse, sizeof(t_tick));
	ft_bzero(&env->tick.editor, sizeof(t_tick));
	ft_bzero(&env->tick.reload, sizeof(t_tick));
	ft_bzero(&env->tick.sector_triger, sizeof(t_tick));
	ft_bzero(env->input, sizeof(int) * SDL_NUM_SCANCODES);
}

static void	error_messages(t_env *env)
{
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
	env->error[E_PARSE] = M_PARSE;
}

static void	assets_paths(t_env *env)
{
	env->asset[BG_MENU] = background_path(env->w, env->h);
	env->asset[ED_TEXT_1] = "./assets/texture_1.bmp";
	env->asset[ED_TEXT_2] = "./assets/texture_2.bmp";
	env->asset[ED_TEXT_3] = "./assets/texture_3.bmp";
	env->asset[ED_TEXT_4] = "./assets/texture_4.bmp";
	env->asset[ED_TEXT_5] = "./assets/texture_5.bmp";
	env->asset[ED_TEXT_6] = "./assets/texture_6.bmp";
	env->asset[ED_TEXT_7] = "./assets/texture_7.bmp";
	env->asset[ED_TEXT_8] = "./assets/texture_8.bmp";
	env->asset[ED_TEXT_9] = "./assets/texture_9.bmp";
	env->asset[ED_TEXT_10] = "./assets/texture_10.bmp";
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
	env->asset[SHOTGUN] = shotgun_asset(env->w, env->h);
	env->asset[MAGAZINE] = magazine_asset(env->w, env->h);
	env->asset[SHELL] = shell_asset(env->w, env->h);
	env->asset[COIN] = coins_asset(env->w, env->h);
	env->asset[SKYBOX] = "./assets/skybox.bmp";
}

static void	infos_setup(t_env *env)
{
	env->w = WIN_W;
	env->h = WIN_H;
	env->win = GAME;
	env->cam.fly = -1;
	env->cam.fall = 1;
	env->cam.speed = 1;
	env->cam.fov = v2d(0.75 * env->h, 0.2 * env->h);
	env->data.life = 100;
	env->data.ammos = 5;
	env->data.magazines = 20;
	env->data.ui.min.y = floor(env->h / RATIO_UI_Y);
	env->data.ui.min.x = floor(env->w / RATIO_UI_X) * 5;
	env->data.ui.max.y = env->h;
	env->data.ui.max.x = floor(env->w / RATIO_UI_X) * 7;
	env->data.grid.min.y = floor(env->h / RATIO_GRID_Y);
	env->data.grid.min.x = floor(env->w / RATIO_GRID_X);
	env->data.grid.max.y = floor(env->h - RATIO_GRID_Y);
	env->data.grid.max.x = floor(env->w - RATIO_GRID_X);
	if ((get_dimensions(env->h)) == -1)
		clean(env, E_BKGD);
	env->data.f_size = floor(env->w * MAX_FONT_SIZE / MAX_WIDTH);
	env->data.g_size = env->data.f_size / 3;
	env->data.hud.coin.shift = coin_shift(env->w, env->h);
	env->data.hud.shotgun.shift = shotgun_shift(env->w, env->h);
}

void		env_setup(t_env *env)
{
	bzero_params(env);
	infos_setup(env);
	assets_paths(env);
	error_messages(env);
	editor_setup(&env->editor);
	env->old_st_fl = 0;
	env->st_fl = 1;
}
