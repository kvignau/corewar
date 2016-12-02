/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:52:36 by mchevall          #+#    #+#             */
/*   Updated: 2016/12/02 07:52:47 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				reverse_byte(int buf, int readv)
{
	if (readv == (sizeof(int)))
		return (((buf >> 24) & 0xff) |
				((buf << 8) & 0xff0000) |
				((buf >> 8) & 0xff00) |
				((buf << 24) & 0xff000000));
	else if (readv == 3)
		return ((((buf << 16) & 0xff0000)) |
			((buf << 0) & 0xff00) |
			((buf >> 16) & (0xff)));
	else if (readv == 2)
		return (((buf << 8) & 0xff00) | (buf >> 8));
	else
		return (buf);
}
