/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 09:28:02 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/23 11:16:18 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <limits.h>
#include <stdlib.h>

int	ft_check_arg(int byte, int t)
{
	int	result;
	int	ret;
	int	i;

	i = 8;
	ret = 0;
	while ((i -= 2) > 0)
	{
		result = (byte >> i) & 0x3;
		ret += (result == 1) + 2 * (result == 3);
		if (result == 2)
			ret += 2 + 2 * (t == 1 || t == 2 || (t >= 6 && t <= 8) || t == 13);
	}
	return (ret);
}

int	ft_check_byte(unsigned char *mem, int pos, int param)
{
	unsigned int	value;
	int				i;
	int				pos_mem;

	pos_mem = pos;
	i = 0;
	value = 0;
	while (i < param)
		value = (value << 8) | (mem[pos_mem + ++i] & 0xFF);
	if (mem[pos_mem + 1] & 0x40)
		value = value - OVERFLOW;
	return ((int)value);
}
