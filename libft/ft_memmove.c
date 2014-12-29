/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:53:33 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/29 21:46:50 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*dp;
	const char	*sp;

	if (s1 <= s2)
		return (ft_memcpy(s1, s2, n));
	sp = s2 + n;
	dp = s1 + n;
	while (n--)
		*--dp = *--sp;
	return (s1);
}
