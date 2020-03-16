/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:51:44 by kibotrel          #+#    #+#             */
/*   Updated: 2020/03/16 01:34:29 by vivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "structs.h"

void audio_clean(t_env *env)
{
	int	i;

	i = -1;
	while (++i < NB_SAMPLES)
		if (env->audio.stream[i] && sf_close(env->audio.stream[i]))
			ft_putendl(env->error[E_AUDIO_CLOSE]);
	if (!ao_close(env->audio.device))
		ft_putendl(env->error[E_DEVICE_CLOSE]);
	ao_shutdown();
}
