/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:34:54 by igomez            #+#    #+#             */
/*   Updated: 2015/02/25 11:38:00 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!src || !dst)
		return (NULL);
	if ((i = -1) && src < dst)
		while (++i < len)
			((char *)dst)[len - 1 - i] = ((char *)src)[len - 1 - i];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
