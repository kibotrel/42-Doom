/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:32:02 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/24 15:07:17 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	hud_setup(t_env *env)
{
	(void)hud;
	ft_bzero(&env->data.hud, sizeof(t_hud));
	//env->data.hud.fps = load_text("FPS : ", ft_itoa(env->data.fps));
	// hud->sector = load_text("Sector : ", ft_itoa(env->cam.sector));
	// hud->angle = load_text("Angle : ", ft_itoa((int)fabs(ft_degrees(env->cam.angle)) % 360));
}
