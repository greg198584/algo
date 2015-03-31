/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 09:27:59 by igomez            #+#    #+#             */
/*   Updated: 2015/02/25 11:49:20 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrep(char *str, char const *sub, char const *rep, int r)
{
	char	*result;
	char	*pos1;
	char	*pos2;
	int		f;

	f = 0;
	pos1 = str;
	while ((pos1 = ft_strstr(pos1, sub)) && f++)
		pos1 += ft_strlen(sub);
	f = ((ft_strlen(str) - (ft_strlen(sub) * f)) + (ft_strlen(rep) * f)) + 1;
	result = (char *)ft_memalloc(f);
	pos1 = str;
	while ((pos2 = ft_strstr(pos1, sub)))
	{
		f = (pos2 - pos1);
		ft_strncat(result, pos1, f);
		ft_strncat(result, rep, ft_strlen(rep));
		pos1 = (pos2 + ft_strlen(sub));
		if (r == 0x01)
			break ;
	}
	if (pos1 != (str + ft_strlen(str)))
		ft_strncat(result, pos1, (str - pos1));
	return (result);
}
