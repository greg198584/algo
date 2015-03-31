/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:16:01 by igomez            #+#    #+#             */
/*   Updated: 2015/02/25 12:09:37 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((str = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	ft_strncpy(str, s1, ft_strlen(s1));
	ft_strncat(str, s2, ft_strlen(s2));
	return (str);
}
