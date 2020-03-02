/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:01:04 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/02 02:16:34 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "clean.h"

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

static void		shot(t_audio *audio)
{
	int			read;
	SNDFILE		*stream;
	ao_device	*device;

	device = audio->device;
	stream = audio->stream[0];
	read = sf_read_short(stream, audio->buffer[0], audio->buffsize[0]);
	ao_play(device, (char *)audio->buffer[0], (uint_32) (read * sizeof(short)));
	sf_seek(stream, -audio->info[0].frames, SEEK_END);
	pthread_exit(NULL);
}
static uint32_t	weapon_state(t_env *env)
{
	uint32_t	pos;

	env->tick.shot.new = SDL_GetTicks();
	pos = weapon_frame(env->tick.shot.new - env->tick.shot.old);
	if (!pos)
		env->data.shot = 0;
	else if (pos == 1 && env->data.fire)
	{
		pthread_create(&env->sound, NULL, (void*)shot, &env->audio);
		env->data.fire = 0;
	}
	return (pos);
}

void			weapon(t_env *env)
{
	t_pos		shift;
	t_pos		vertex[2];
	t_anime		null;

	null = (t_anime){0, 0};
	env->data.hud.shotgun.frame = (env->data.shot ? weapon_state(env) : 0);
	shift = (t_pos){env->w / 2 + env->data.grid.min.x * 3, env->h};
	draw_asset(env, env->sdl.bmp[SHOTGUN], shift, &env->data.hud.shotgun);
	vertex[0] = p2d(0, 24, env->data.grid.min.x, env->data.grid.min.y);
	vertex[1] = p2d(21, 28, env->data.grid.min.x, env->data.grid.min.y);
	blur_area(env, vertex[0], vertex[1]);
	shift = (t_pos){env->data.grid.min.x, env->data.grid.min.y * 27};
	draw_asset(env, env->sdl.bmp[MAGAZINE], shift, &null);
	shift = (t_pos){shift.x * 12, shift.y};
	draw_asset(env, env->sdl.bmp[SHELL], shift, &null);
	info(env, ft_itoa(env->data.magazines), v2d(9, 25.5), 1);
	info(env, txt(ft_itoa(env->data.ammos), " / 5", 0), v2d(18, 25.5), 1);
}
