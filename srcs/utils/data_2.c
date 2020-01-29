/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:03:37 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/29 08:41:29 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*load_text(char *prefix, char *info, int mode)
{
	char	*string;

	string = ft_strjoin(prefix, info);
	if (mode == 0)
		free(prefix);
	else if (mode == 1)
		free(info);
	else
	{
		free(prefix);
		free(info);
	}
	return (string);
}
