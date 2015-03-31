/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:39:12 by igomez            #+#    #+#             */
/*   Updated: 2015/02/25 11:53:41 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;
	char	*str;

	if (*s2 == '\0')
		return ((char *)s1);
	str = (char *)s1;
	len = ft_strlen(s2);
	while (*str)
		if (*str++ == *s2)
			if (ft_strncmp((const char *)(str - 1), s2, len) == 0)
				return (str - 1);
	return (NULL);
}
