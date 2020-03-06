/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:51:44 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/06 09:56:24 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
