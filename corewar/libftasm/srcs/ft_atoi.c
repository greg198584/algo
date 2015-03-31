/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:35:22 by igomez            #+#    #+#             */
/*   Updated: 2014/11/05 16:56:10 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int negativ;
	int total;

	total = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\v'
			|| *s == '\f' || *s == '\r' || *s == '+')
		s++;
	negativ = 1;
	if (*s == '-' && *(s - 1) != '+')
		negativ = (*s++ == '-') * (-1);
	while (ft_isdigit(*s))
		total = total * 10 + ((int)*s++ - '0');
	return (total * negativ);
}
