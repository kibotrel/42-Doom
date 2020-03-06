/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:50:27 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 09:57:09 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "structs.h"

static void	mixer(t_audio *audio)
{
	int		i;
	int		mix;

	i = -1;
	while (++i < STREAM_SIZE)
	{
		mix = audio->buffer[1][i] + audio->buffer[0][i];
		if (mix > SHRT_MAX)
			mix = SHRT_MAX;
		else if (mix < SHRT_MIN)
			mix = SHRT_MIN;
		audio->buffer[1][i] = (short)mix;
	}
}

static int	shotgun_fire(t_env *env)
{
	int		i;

	i = sf_read_short(env->audio.stream[0], env->audio.buffer[0], STREAM_SIZE);
	if (!i)
	{
		env->audio.fire = 0;
		sf_seek(env->audio.stream[0], 0, SEEK_SET);
	}
	return (i);
}

void		audio(t_env *env)
{
	int		read[2];
	t_audio	*audio;

	audio = &env->audio;
	while (1)
	{
		read[1] = 0;
		read[0] = sf_read_short(audio->stream[1], audio->buffer[1],
								STREAM_SIZE);
		if (!read[0])
			sf_seek(audio->stream[1], 0, SEEK_SET);
		if (audio->fire && (read[1] = shotgun_fire(env)) > 0)
			mixer(audio);
		if (read[0] && env->win == GAME && !env->data.closed)
			ao_play(audio->device, (char *)audio->buffer[1],
					(uint_32)(read[0] * sizeof(short)));
		if (env->win != GAME || env->data.closed)
			break ;
	}
	pthread_exit(NULL);
}
