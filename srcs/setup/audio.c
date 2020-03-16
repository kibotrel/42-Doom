/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:04:05 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/16 01:39:38 by vivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "libft.h"

static int32_t	bits_per_sample(int32_t format)
{
	int32_t			mask;

	mask = format & SF_FORMAT_SUBMASK;
	if (mask == SF_FORMAT_PCM_24)
		return (24);
	else if (mask == SF_FORMAT_PCM_32)
		return (32);
	else if (mask == SF_FORMAT_PCM_S8 || mask == SF_FORMAT_PCM_U8)
		return (8);
	else
		return (16);
}

void			audio_setup(t_env *env, t_audio *audio)
{
	int				i;
	static char		*path[2] = {"./assets/shotgun.wav", "./assets/ost1.wav"};

	i = -1;
	ao_initialize();
	if ((audio->driver = ao_default_driver_id()) < 0)
		clean(env, E_AUDIO_DRIVER);
	while (++i < NB_SAMPLES)
	{
		ft_bzero(&audio->info[i], sizeof(SF_INFO));
		if (!(audio->stream[i] = sf_open(path[i], SFM_READ, &audio->info[i])))
			clean(env, E_AUDIO_OPEN);
		audio->format[i].bits = bits_per_sample(audio->info[i].format);
		audio->format[i].channels = audio->info[i].channels;
		audio->format[i].rate = audio->info[i].samplerate;
		audio->format[i].byte_format = AO_FMT_NATIVE;
		audio->format[i].matrix = 0;
		ft_bzero(audio->buffer[i], sizeof(short) * STREAM_SIZE);
	}
	if (!(audio->device = ao_open_live(audio->driver, &audio->format[0], NULL)))
		clean(env, E_DEVICE_OPEN);
}
