/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:29:05 by igomez            #+#    #+#             */
/*   Updated: 2015/02/25 11:25:56 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char *p;

	p = (char *)ft_memalloc((int)ft_nbrlen(n) + 1);
	if (n >= 0 && p)
	{
		*--p = '0' + (n % 10);
		while ((n /= 10) != 0)
			*--p = '0' + (n % 10);
	}
	else if (p)
	{
		*--p = '0' - (n % 10);
		while ((n /= 10) != 0)
			*--p = '0' - (n % 10);
		*--p = '-';
	}
	return (p);
}