/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitobi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 07:39:14 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/23 08:31:00 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitobi(unsigned int value)
{
	unsigned int	tab[4];
	char			*result;
	unsigned int	byte;
	int				i;

	i = 0;
	result = ft_memalloc(37);
	tab[0] = 0xff000000;
	tab[1] = 256*256*256;
	tab[2] = -1;
	while (++tab[2] < 4)
	{
		byte = (value & tab[0]) / tab[1];
		if (i != 0)
			result[i++] = ' ';
		tab[3] = -1;
		while (++tab[3] < 8)
		{
			result[i++] = '0' + ((byte & 0x80) != 0);
			byte *= 2;
		}
		tab[0] /= 256;
		tab[1] /= 256;
	}
	return (result);
}
