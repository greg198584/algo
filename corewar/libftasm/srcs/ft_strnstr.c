/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 11:59:10 by igomez            #+#    #+#             */
/*   Updated: 2015/02/25 12:04:54 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	s2len;
	int		i;

	if (!(s2len = ft_strlen(s2)))
		return ((char *)s1);
	if (len > ft_strlen(s1))
		len = ft_strlen(s1);
	i = -1;
	while (++i < (int)(len - s2len))
	{
		if ((*s1 == *s2 && (!ft_strncmp(s1, s2, s2len))))
			return ((char *)s2);
		s2++;
	}
	return (NULL);
}
