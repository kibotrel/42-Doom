/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:58:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/15 23:51:14 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "clean.h"
#include "libft.h"
#include "setup.h"
#include "utils.h"

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
	env->error[E_BKGD] = M_BKGD;
}

static void	assets_paths(t_env *env)
{
	ft_bzero(env->asset, sizeof(char*));
	env->asset[MENU_1080P] = "assets/menu_1080.bmp";
	env->asset[MENU_900P] = "assets/menu_900.bmp";
	env->asset[MENU_768P] = "assets/menu_768.bmp";
	env->asset[MENU_720P] = "assets/menu_720.bmp";
}

static void	infos_setup(t_env *env)
{
	ft_bzero(env->input, sizeof(int) * SDL_NUM_SCANCODES);
	ft_bzero(&env->data.ui, sizeof(t_ui));
	env->data.ui.min.y = floor(env->h / RATIO_UI_Y);
	env->data.ui.min.x = floor(env->w / RATIO_UI_X) * 5;
	env->data.ui.max.y = env->h;
	env->data.ui.max.x = floor(env->w / RATIO_UI_X) * 7;
	if ((env->data.ui.background = get_dimensions(env->h)))
	 	clean(env, E_BKGD);
	env->data.f_size = floor(env->w * MAX_FONT_SIZE / MAX_WIDTH);
}

void		point(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

void		env_setup(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	env->w = WIN_W;
	env->h = WIN_H;
	assets_paths(env);
	error_messages(env);
	infos_setup(env);

	ft_bzero(&env->player, sizeof(t_player));
	ft_bzero(&env->vertex, sizeof(t_point) * 4);
	ft_bzero(&env->wall, sizeof(t_point) * 8);
	env->player.position.x = env->w / 2;
	env->player.position.y = env->h / 2;
	env->pos = env->player.position;
	env->player.speed = 1.0;
	env->vertex[0].y = env->h / 4;
	env->vertex[0].x = env->w / 4;
	env->vertex[1].y = env->h / 4;
	env->vertex[1].x = env->w / 4 * 3;
	env->vertex[2].y = env->h / 4 * 3;
	env->vertex[2].x = env->w / 4 * 3;
	env->vertex[3].y = env->h / 4 * 3;
	env->vertex[3].x = env->w / 4;
	point(&env->wall[0], env->w / 4 + 7,   env->h / 4 + 21 );
	point(&env->wall[1], env->w / 4 + 91,  env->h / 4 + 76 );
	point(&env->wall[2], env->w / 4 + 371, env->h / 2 + 103);
	point(&env->wall[3], env->w / 4 + 93,  env->h / 2 + 103);
	point(&env->wall[4], env->w / 2 + 7,   env->h / 4 + 98);
	point(&env->wall[5], env->w / 2 - 82,  env->h / 4 + 108);
	point(&env->wall[6], env->w / 2 + 290, env->h / 4 + 153);
	point(&env->wall[7], env->w / 2 + 170, env->h / 4 + 420);
}
