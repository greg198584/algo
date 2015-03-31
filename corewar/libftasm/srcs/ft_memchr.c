/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:16:13 by igomez            #+#    #+#             */
/*   Updated: 2015/02/25 11:31:17 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p_s;

	if (!s)
		return (NULL);
	p_s = (unsigned char *)s;
	while (n--)
		if (*p_s++ == (unsigned char)c)
			return ((void *)(p_s - 1));
	return (NULL);
}
