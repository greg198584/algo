/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 08:30:26 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/19 15:14:57 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_uitoa(unsigned long int n)
{
	char *p;

	if ((p = ft_strnew(20) + 19) == NULL)
		return (NULL);
	if (p)
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
