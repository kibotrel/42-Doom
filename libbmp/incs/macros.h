/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:15:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 02:45:12 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*
**	Useful macros
*/

# define BMP_SIGN		0x424D
# define DIB_SIZE		108u
# define MAX_SIZE		16842752u
# define BMP_SHIFT		122u
# define BUFFER_SIZE	6

/*
**	Byte swapping.
*/

# define B3				0xFF
# define B2				0xFF00
# define B1				0xFF0000
# define B0				0xFF000000

#endif
