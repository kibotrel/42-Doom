/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:34:35 by reda-con          #+#    #+#             */
/*   Updated: 2020/03/06 12:22:26 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "clean.h"
#include "libft.h"

void	doors2(t_env *env, int t, uint32_t i, uint32_t j)
{
	uint32_t	k;
	int			l;

	l = env->sector[i].door_neighbor[j];
	if (l > -1 && env->sector[l].type != -t)
		env->sector[i].neighbor[j] = l;
	k = -1;
	l = env->sector[i].neighbor[j];
	while (l > -1 && ++k < env->sector[l].points)
		if (env->sector[l].door_neighbor[k] > -1
				&& env->sector[env->sector[l].door_neighbor[k]].type == -t)
			env->sector[l].neighbor[k] = env->sector[l].door_neighbor[k];
}

void	doors(t_env *env, int t)
{
	uint32_t	i;
	uint32_t	j;

	i = -1;
	if (!env->tuto || env->test.all_move)
	{
		env->plate = env->cam.sector;
		if (t == 8 && env->tuto)
			env->test.door = 1;
		while (++i < env->zones)
		{
			if (env->sector[i].type == -t)
			{
				j = -1;
				env->open = 1;
				env->old_door = SDL_GetTicks();
				while (++j < env->sector[i].points)
					doors2(env, t, i, j);
			}
		}
	}
}

void	effector(t_env *env, int s)
{
	police_color(&env->sdl.color, 0xff, 0x00, 0x00);
	if (env->sector[s].type == LAVA)
		info(env, ft_strdup("Warning"), v2d(RATIO_GRID_X / 2, 1), 1);
	police_color(&env->sdl.color, 0xff, 0xff, 0x00);
	if (env->sector[s].type == MONEY)
		info(env, ft_strdup("Earning money"), v2d(RATIO_GRID_X / 2, 1), 1);
	police_color(&env->sdl.color, 0xff, 0x69, 0xb4);
	if (env->sector[s].type == HEAL)
		info(env, ft_strdup("Healing"), v2d(RATIO_GRID_X / 2, 1), 1);
	env->st_fl = SDL_GetTicks();
	if (env->st_fl > env->old_st_fl + 200)
	{
		if (env->sector[s].type == LAVA && env->cam.ground == 1)
			update_life(env, (double)env->sector[s].data / 5, 1);
		if (env->sector[s].type == MONEY)
			env->data.money += (double)env->sector[s].data / 5;
		if (env->sector[s].type == HEAL)
			update_life(env, (double)env->sector[s].data / 5, 0);
		env->old_st_fl = env->st_fl;
	}
	if (env->data.life <= 0 || env->sector[s].type == END)
		env->data.life <= 0 ? clean(env, DEATH) : clean(env, WIN);
	police_color(&env->sdl.color, 0xff, 0xff, 0xff);
}

void	elevator(t_sector *sector, int s, t_cam *cam, int *input)
{
	if ((sector[s].type == ELEVATOR || sector[s].type == -ELEVATOR)
			&& cam->fly == -1)
	{
		if (input[SDL_SCANCODE_E] && ((sector[s].floor < sector[s].data
			+ sector[s].elvt && sector[s].type == ELEVATOR)
		|| (sector[s].floor < sector[s].elvt && sector[s].type == -ELEVATOR)))
		{
			++cam->pos.z;
			++sector[s].floor;
		}
		if (input[SDL_SCANCODE_Q] && ((sector[s].floor
						> sector[s].elvt && sector[s].type == ELEVATOR)
					|| (sector[s].floor > sector[s].elvt
						- sector[s].data && sector[s].type == -ELEVATOR)))
		{
			--cam->pos.z;
			--sector[s].floor;
		}
		if (sector[s].floor >= sector[s].ceil - 5 && --cam->pos.z)
			sector[s].floor = sector[s].ceil - 6;
	}
}

void	sector_triger(t_env *env)
{
	elevator(env->sector, env->cam.sector, &env->cam, env->input);
	effector(env, env->cam.sector);
	if (env->poor)
	{
		env->jp = SDL_GetTicks();
		if (env->jp < env->old_jp + 1000)
			poor(env, env->poor);
		else
			env->poor = 0;
	}
	if (env->input[SDL_SCANCODE_E] && env->sector[env->cam.sector].type > END)
		doors(env, env->sector[env->cam.sector].type);
	if (env->open == 1)
	{
		env->door = SDL_GetTicks();
		if (env->door < env->old_door + 1000)
			info(env, ft_strdup("A door has been opened"),
				v2d(RATIO_GRID_X / 2, 1), 1);
		else
		{
			env->sector[env->plate].type = 0;
			env->open = 0;
		}
	}
}
