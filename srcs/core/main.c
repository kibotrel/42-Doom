/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:53:54 by kibotrel          #+#    #+#             */
/*   Updated: 2020/02/28 06:18:27 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "game.h"
#include "libft.h"
#include "clean.h"
#include "setup.h"
#include "utils.h"
#include "parse.h"

//	If ac == 2, a map is sent to the program
//	replace ft_isvalidname by a parser call + check the name inside
//	function prototype should be modified to get env in this scope

/*
 __attribute__((destructor)) void no_end(void);
  void no_end(){while(1);}
  */

/*
static int	prechecks(int ac, char **av)
{
	return ((ac == 2 ? ft_isvalidname(av[1], ".data") : 1));
}
*/

static void	update_screen(t_env *env)
{
	if (SDL_UpdateWindowSurface(env->sdl.win))
		clean(env, E_SDL_UPDATE);
	fps_counter(env);
}

#include <ao.h>
#include <unistd.h>
#include <sndfile.h>

int			main(int ac, char **av)
{
	t_env	env;

	SF_INFO				info;
	ao_device			*device;
	ao_sample_format	format;

	info.format = 0;
	SNDFILE	*stream = sf_open("./assets/shotgun.wav", SFM_READ, &info);
	ao_initialize();
	int driver = ao_default_driver_id();
	int bitrate = info.format & SF_FORMAT_SUBMASK;
	if (bitrate == SF_FORMAT_PCM_24)
		format.bits = 24;
	else if (bitrate == SF_FORMAT_PCM_32)
		format.bits = 32;
	else if (bitrate == SF_FORMAT_PCM_S8 || bitrate == SF_FORMAT_PCM_U8)
		format.bits = 8;
	else
		format.bits = 16;
	format.channels = info.channels;
	format.rate = info.samplerate;
	format.byte_format = AO_FMT_NATIVE;
	format.matrix = 0;
	device = ao_open_live(driver, &format, NULL);
	short *buffer = malloc(sizeof(short) * format.channels * info.frames);
	ft_bzero(buffer, sizeof(short) * format.channels * info.frames);
	int read = sf_read_short(stream, buffer, format.channels * info.frames);
	ao_play(device, (char *)buffer, (uint_32) (read * sizeof(short)));
	free(buffer);
	sf_close(stream);
	ao_close(device);
	ao_shutdown();
	exit(0);

	if (ac <= 2)
	{
		env_setup(&env);
		graphic_setup(&env, &env.sdl);
		while (1)
		{
			selector(&env, ac, av);
			if (env.win == GAME)
				physics(&env);
			global_hooks(&env, &env.sdl);
			update_screen(&env);
		}
	}
	else
		usage();
	return (0);
}
