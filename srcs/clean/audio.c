#include <stdlib.h>
#include "structs.h"

void	audio_clean(t_audio *audio)
{
	int	i;

	i = -1;
	while (++i < NB_SAMPLES)
		if (audio->stream[i])
			sf_close(audio->stream[i]);
	ao_close(audio->device);
	ao_shutdown();
}
