/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:03:37 by kibotrel          #+#    #+#             */
/*   Updated: 2020/01/24 15:06:03 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*load_text(char *prefix, char *info)
{
	char	*string;

	string = ft_strjoin(prefix, info);
	free(info);
	return (string);
}
