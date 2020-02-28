#include "clean.h"
#include "libft.h"

static int32_t	bits_per_sample(int32_t format)
{
	int32_t	mask;

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
	int	i;

	i = -1;
	ao_initialize();
	if ((audio->driver = ao_default_driver_id()) < 0)
		clean(env, E_AUDIO_DRIVER);
	while (++i < 1)//NB_SAMPLES)
	{
		audio->stream[i] = sf_open("./assets/shotgun.wav", SFM_READ, &audio->info[i]);
		audio->format[i].bits = bits_per_sample(audio->info[i].format);
		audio->format[i].channels = audio->info[i].channels;
		audio->format[i].rate = audio->info[i].samplerate;
		audio->format[i].byte_format = AO_FMT_NATIVE;
		audio->format[i].matrix = 0;
		audio->buffsize[i] = audio->format[i].channels * audio->info[i].frames;
		// printf("%d\n%d\n%d\n%d\n", audio->format[i].bits, audio->format[i].channels, audio->format[i].rate, audio->format[i].byte_format);
	}
	audio->buffer[0] = (short*)malloc(sizeof(short) * audio->buffsize[0]);
	ft_bzero(audio->buffer[0], sizeof(short) * audio->buffsize[0]);
	audio->device = ao_open_live(audio->driver, &audio->format[0], NULL);

	int read = sf_read_short(audio->stream[0], audio->buffer[0], audio->buffsize[0]);
	ao_play(audio->device, (char *)audio->buffer[0], (uint_32) (read * sizeof(short)));
	sf_close(audio->stream[0]);
	ao_close(audio->device);
	ao_shutdown();
	free(audio->buffer[0]);
	exit(0);
}
